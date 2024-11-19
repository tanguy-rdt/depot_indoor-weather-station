#include "display.h"

#include "hal_conf_internal.h"

#include "sdl/sdl.h"

#include "simu_bg_black.c"
#include "simu_bg_white.c"


static lv_disp_draw_buf_t DISP_BUF1;

static lv_style_t _styleBackground;
static lv_style_t _styleBacklight;


Display::Display()
    : _disp(nullptr), _dummyBacklight(nullptr) {

}

Display::~Display() {
    lv_obj_del(_dummyBacklight);

    _disp = nullptr;
}

void Display::init() {
    _disp = NULL;

    sdl_init();
    createDisplayBuffer();
    createDisplay();
    initDummyCircleDisplay();
    initDummyBacklight();

    setBacklightLevel(100);
}

void Display::setBacklightLevel(int percent) {
    switch (percent) {
        case 25:
            lv_style_set_bg_opa(&_styleBacklight, LV_OPA_70);
            break;
        case 50:
            lv_style_set_bg_opa(&_styleBacklight, LV_OPA_40);
            break;
        case 75:
            lv_style_set_bg_opa(&_styleBacklight, LV_OPA_20);
            break;
        case 100:
            lv_style_set_bg_opa(&_styleBacklight, LV_OPA_TRANSP);
            break;
    }
}

void Display::createDisplayBuffer() {
    static lv_color_t buf1_1[HAL_SCREEN_WIDTH * 100];
    static lv_color_t buf1_2[HAL_SCREEN_WIDTH * 100];
    
    lv_disp_draw_buf_init(&DISP_BUF1, buf1_1, buf1_2, HAL_SCREEN_WIDTH * 100);
}

void Display::createDisplay() {
    static lv_disp_drv_t disp_drv;

    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf = &DISP_BUF1;
    disp_drv.flush_cb = sdl_display_flush;
    disp_drv.hor_res = HAL_SCREEN_WIDTH;
    disp_drv.ver_res = HAL_SCREEN_HEIGHT;
    disp_drv.antialiasing = 1;

    _disp = lv_disp_drv_register(&disp_drv);
}

void Display::initDummyCircleDisplay() {
    lv_style_init(&_styleBackground);
    lv_style_set_bg_img_src(&_styleBackground, &simu_bg_white);
    lv_obj_add_style(lv_scr_act(), &_styleBackground, 0);
}

void Display::initDummyBacklight() {
    lv_style_init(&_styleBacklight);
    lv_style_set_radius(&_styleBacklight, 0);
    lv_style_set_border_width(&_styleBacklight, 0);
    lv_style_set_bg_opa(&_styleBacklight, LV_OPA_TRANSP);
    lv_style_set_bg_color(&_styleBacklight, lv_color_black());
    lv_style_set_pad_all(&_styleBacklight, 0);

    _dummyBacklight = lv_obj_create(lv_scr_act());
    lv_obj_set_size(_dummyBacklight, HAL_SCREEN_WIDTH, HAL_SCREEN_HEIGHT);
    lv_obj_align(_dummyBacklight, LV_ALIGN_BOTTOM_LEFT, 0, 0);
    lv_obj_set_scroll_dir(_dummyBacklight, LV_DIR_NONE);
    lv_obj_set_style_pad_gap(_dummyBacklight, 0, 0);
    lv_obj_add_style(_dummyBacklight, &_styleBacklight, 0);
    lv_obj_clear_flag(_dummyBacklight, LV_OBJ_FLAG_CLICKABLE);
}


