#ifndef DISPLAY_H
#define DISPLAY_H

#include "lvgl.h"

class Display {
    public:
        Display();
        ~Display();

        void init();
        void setBacklightLevel(int percent);

    private:
        void createDisplayBuffer();
        void createDisplay();
        void initDummyCircleDisplay();
        void initDummyBacklight();

        lv_disp_t* _disp;
        lv_obj_t*  _dummyBacklight;
};

#endif // DISPLAY_H