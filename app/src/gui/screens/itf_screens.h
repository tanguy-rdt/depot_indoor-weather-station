#ifndef ITF_SCREENS_H
#define ITF_SCREENS_H

#include "lvgl.h"
#include "screens_name.h"

namespace screens {

class ItfScreens {

    public:
        virtual ~ItfScreens() = default;
        using Screen = lv_obj_t;

        virtual void show(ScreenName screenName) = 0;

    private:
        Screen* _screen = nullptr;

};

}

#endif // ITF_SCREENS_H
