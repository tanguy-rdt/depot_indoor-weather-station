#include "data_screen.h"

#include "lvgl.h"

#include "proxy_value_to_gui.h"
#include "gui_conf_internal.h"
#include "log.h"

namespace gui {

DataScreen::DataScreen(Proxy* proxy)
    : _proxy(proxy){

    Log::debug("DataScreen -- created");

    _screen = lv_obj_create(NULL);

    _circularIndicator = new Widgets::CircularIndicator(0, 0, 110, _screen);
    _circularIndicator->setAngle(60, 300);
    _circularIndicator->setWidth(15);

    _data[DataType::TEMPERATURE] = {
        .units = "°C",
        .range = std::make_pair(10.0, 35.0),
        .colors = {
            lv_palette_main(LV_PALETTE_BLUE),
            lv_palette_main(LV_PALETTE_YELLOW),
            lv_palette_main(LV_PALETTE_ORANGE),
            lv_palette_main(LV_PALETTE_RED)
        }
    };

    _data[DataType::HUMIDITY] = {
        .units = "%",
        .range = std::make_pair(0.0, 100.0),
        .colors = {
            lv_color_white(),
            lv_palette_main(LV_PALETTE_LIGHT_BLUE),
            lv_palette_main(LV_PALETTE_BLUE)
        }
    };

    _data[DataType::PRESSURE] = {
        .units = "Pa",
        .range = std::make_pair(950.0, 1050.0),
        .colors = {
            lv_palette_main(LV_PALETTE_GREY),
            lv_palette_main(LV_PALETTE_LIGHT_BLUE),
            lv_palette_main(LV_PALETTE_BLUE)
        }
    };

    _data[DataType::AIR_QUALITY] = {
        .units = "",
        .range = std::make_pair(0.0, 500.0),
        .colors = {
            lv_palette_main(LV_PALETTE_GREEN),
            lv_palette_main(LV_PALETTE_YELLOW),
            lv_palette_main(LV_PALETTE_RED),
            lv_palette_main(LV_PALETTE_PURPLE),
        }
    };

    _labelContainer = lv_obj_create(_screen);
    lv_obj_set_size(_labelContainer, GUI_SCREEN_WIDTH, 70);
    lv_obj_center(_labelContainer);
    lv_obj_set_flex_flow(_labelContainer, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(_labelContainer, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_scroll_dir(_labelContainer, LV_DIR_NONE);

    _labelValue = lv_label_create(_labelContainer);
    lv_obj_set_style_text_color(_labelValue, lv_color_white(), 0);
    lv_obj_set_style_text_font(_labelValue, &roboto_50, 0);

    _labelUnits = lv_label_create(_labelContainer);
    lv_obj_set_style_text_color(_labelUnits, lv_color_white(), 0);
    lv_obj_set_style_text_font(_labelUnits, &roboto_30, 0);
}

DataScreen::~DataScreen() {
    Log::debug("DataScreen -- destroyed");

    delete _circularIndicator;

    lv_obj_del(_labelUnits);
    lv_obj_del(_labelValue);
    lv_obj_del(_labelContainer);
    lv_obj_del(_screen);
}

DataScreen::Screen *DataScreen::getScreen() const {
    return _screen;
}

void DataScreen::showData(DataType dataType) {
    Log::debug("DataScreen::showData -- %s", tools::dataTypeToString(dataType).c_str());

    auto value = dataType == DataType::TEMPERATURE ? _proxy->getTemperature() :
                        dataType == DataType::HUMIDITY    ? _proxy->getHumidity()    :
                        dataType == DataType::PRESSURE    ? _proxy->getPressure()    :
                        dataType == DataType::AIR_QUALITY ? _proxy->getAirQuality()  : 0.0;

    _circularIndicator->setRange(_data[dataType].range.first, _data[dataType].range.second);
    _circularIndicator->setColors(_data[dataType].colors);
    auto modStatus = _circularIndicator->setValue(value);
    _circularIndicator->draw();


    auto guiValue = modStatus ? tools::convertToGUI(value) : std::string("--.-");
    lv_label_set_text(_labelValue, guiValue.c_str());
    lv_obj_set_parent(_labelValue, _labelContainer);

    lv_label_set_text(_labelUnits, _data[dataType].units.c_str());
    lv_obj_set_parent(_labelUnits, _labelContainer);
}

} // gui