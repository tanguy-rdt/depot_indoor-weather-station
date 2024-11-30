#ifndef DISPLAY_H
#define DISPLAY_H

#include "lvgl.h"

class Display {
    public:
        Display();
        ~Display();

        void setBacklightLevel(int percent);

    private:
        void initDisplay();
        void initDummyBacklight();

        lv_disp_t* _disp;
        lv_disp_drv_t _dispDrv;
        lv_disp_draw_buf_t _dispBuf;
        lv_color_t* _dispBuf1;
        lv_color_t* _dispBuf2;

        lv_obj_t*  _dummyBacklight;
};

#endif // DISPLAY_H