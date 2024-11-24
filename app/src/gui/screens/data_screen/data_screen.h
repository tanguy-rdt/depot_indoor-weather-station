#ifndef DATA_SCREEN_H
#define DATA_SCREEN_H

#include <map>
#include "lvgl.h"

#include "circular_indicator.h"
#include "proxy/proxy.h"
#include "data_type.h"

using namespace proxy;

namespace gui {

class DataScreen {
    public:
        DataScreen(Proxy* proxy);
        ~DataScreen();

        using Screen = lv_obj_t;

        Screen* getScreen() const;
        void showData(DataType dataTypes);

    private:
        Proxy* _proxy;

        Widgets::CircularIndicator* _circularIndicator;

        Screen* _screen;
        lv_obj_t* _labelContainer;
        lv_obj_t* _labelValue;
        lv_obj_t* _labelUnits;

        struct Data {
            std::string units;
            std::pair<float, float> range;
            std::vector<lv_color_t> colors;
        };

        std::map<DataType, Data> _data;
};

} // gui

#endif //DATA_SCREEN_H
