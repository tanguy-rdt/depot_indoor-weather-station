#include "gui.h"

#include "lvgl.h"
#include "data_type.h"

namespace gui {

Gui::Gui(Proxy* proxy)
    : _proxy(proxy) {

    _dataScreen = new DataScreen(_proxy);
}

Gui::~Gui() {

}

void Gui::init() {
    lv_scr_load(_dataScreen->getScreen());
    _dataScreen->showData(DataType::TEMPERATURE);
}

} // gui