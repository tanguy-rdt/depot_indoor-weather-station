#ifndef DATA_SCREEN_H
#define DATA_SCREEN_H

#include <map>
#include "lvgl.h"

#include "circular_indicator.h"


namespace gui {

class DataScreen {
    public:
        DataScreen();
        ~DataScreen();

        using Screen = lv_obj_t;

        enum class Types {
            TEMPERATURE,
            HUMIDITY,
            PRESSURE,
            QUALITY_OF_AIR,
        };

        Screen* getScreen() const;
        void showData(Types dataTypes);

    private:
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

        std::map<Types, Data> _data;
};

} // gui

#endif //DATA_SCREEN_H
