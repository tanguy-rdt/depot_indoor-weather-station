#include "display.h"

#include "hal_conf_internal.h"

#include "sdl/sdl.h"

#include "simu_bg_black.c"
#include "simu_bg_white.c"

#include "log.h"

static lv_style_t _styleBacklight;


Display::Display()
    : _disp(nullptr), _dummyBacklight(nullptr) {

    sdl_init();
    initDisplay();
}

Display::~Display() {
    lv_obj_del(_dummyBacklight);

    _disp = nullptr;
}

void Display::initDisplay() {
    _dispBuf1 = new lv_color_t[HAL_SCREEN_WIDTH * 100];
    _dispBuf2 = new lv_color_t[HAL_SCREEN_WIDTH * 100];

    lv_disp_draw_buf_init(&_dispBuf, _dispBuf1, _dispBuf2, HAL_SCREEN_WIDTH * 100);

    lv_disp_drv_init(&_dispDrv);
    _dispDrv.draw_buf = &_dispBuf;
    _dispDrv.flush_cb = sdl_display_flush;
    _dispDrv.hor_res = HAL_SCREEN_WIDTH;
    _dispDrv.ver_res = HAL_SCREEN_HEIGHT;
    _dispDrv.antialiasing = 1;
    _disp = lv_disp_drv_register(&_dispDrv);

    lv_disp_set_bg_image(_disp, &simu_bg_black);
}

void Display::setBacklightLevel(int percent) {
    // switch (percent) {
    //     case 25:
    //         lv_style_set_bg_opa(&_styleBacklight, LV_OPA_70);
    //         break;
    //     case 50:
    //         lv_style_set_bg_opa(&_styleBacklight, LV_OPA_40);
    //         break;
    //     case 75:
    //         lv_style_set_bg_opa(&_styleBacklight, LV_OPA_20);
    //         break;
    //     case 100:
    //         lv_style_set_bg_opa(&_styleBacklight, LV_OPA_TRANSP);
    //         break;
    // }
}

void Display::initDummyBacklight() {
    // lv_style_init(&_styleBacklight);
    // lv_style_set_radius(&_styleBacklight, 0);
    // lv_style_set_border_width(&_styleBacklight, 0);
    // lv_style_set_bg_opa(&_styleBacklight, LV_OPA_TRANSP);
    // lv_style_set_bg_color(&_styleBacklight, lv_color_black());
    // lv_style_set_pad_all(&_styleBacklight, 0);
    //
    // _dummyBacklight = lv_obj_create(lv_scr_act());
    // lv_obj_set_size(_dummyBacklight, HAL_SCREEN_WIDTH, HAL_SCREEN_HEIGHT);
    // lv_obj_align(_dummyBacklight, LV_ALIGN_BOTTOM_LEFT, 0, 0);
    // lv_obj_set_scroll_dir(_dummyBacklight, LV_DIR_NONE);
    // lv_obj_set_style_pad_gap(_dummyBacklight, 0, 0);
    // lv_obj_add_style(_dummyBacklight, &_styleBacklight, 0);
    // lv_obj_clear_flag(_dummyBacklight, LV_OBJ_FLAG_CLICKABLE);
}


