#ifndef DISPLAY_H
#define DISPLAY_H

#include "lvgl.h"

class Display {
    public:
        Display();
        ~Display();

        void init();
        
    private:
        lv_disp_t* _disp;

        void createDisplayBuffer();
        void createDisplay();
};

#endif // DISPLAY_H