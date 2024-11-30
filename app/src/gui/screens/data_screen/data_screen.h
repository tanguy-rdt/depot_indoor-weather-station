#ifndef DATA_SCREEN_H
#define DATA_SCREEN_H

#include <map>

#include "lvgl.h"

#include "itf_screens.h"
#include "circular_indicator.h"
#include "proxy/proxy.h"
#include "data_type.h"
#include <screens_manager.h>
#include "screens_name.h"

using namespace proxy;

namespace screens {
class ScreensManager;

class DataScreen: public ItfScreens {
    public:
        DataScreen(Proxy* proxy, EventManager* eventManager);
        ~DataScreen();

        void show(ScreenName screenName);

    private:
        void showData(DataType dataTypes);
        void update(DataType dataType) const;

        DataType _currentDataTypeScreen;

        EventManager* _eventManager;
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
