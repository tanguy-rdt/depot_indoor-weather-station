#include "display.h"

#include "sdl/sdl.h"


#define SIMU_SCREEN_LENGHT 240
#define SIMU_SCREEN_HEIGHT 410


static lv_disp_draw_buf_t DISP_BUF1;


Display::Display() {

}

Display::~Display() {

}

void Display::init() {
    _disp = NULL;

    sdl_init();
    createDisplayBuffer();
    createDisplay();
}

void Display::createDisplayBuffer() {
    static lv_color_t buf1_1[SIMU_SCREEN_LENGHT * 100];
    static lv_color_t buf1_2[SIMU_SCREEN_LENGHT * 100];
    
    lv_disp_draw_buf_init(&DISP_BUF1, buf1_1, buf1_2, SIMU_SCREEN_LENGHT * 100);
}

void Display::createDisplay() {
    static lv_disp_drv_t disp_drv;

    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf = &DISP_BUF1;
    disp_drv.flush_cb = sdl_display_flush;
    disp_drv.hor_res = SIMU_SCREEN_LENGHT;
    disp_drv.ver_res = SIMU_SCREEN_HEIGHT;
    disp_drv.antialiasing = 1;

    _disp = lv_disp_drv_register(&disp_drv);
}
