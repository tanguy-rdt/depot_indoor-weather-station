#include "gui.h"

#include "lvgl.h"
#include "data_type.h"

namespace gui {

Gui::Gui(Proxy* proxy, EventManager* eventManager)
    : _proxy(proxy), _eventManager(eventManager) {

    _dataScreen = new DataScreen(_proxy, _eventManager);
}

Gui::~Gui() {

}

void Gui::init() {
    lv_scr_load(_dataScreen->getScreen());
    _dataScreen->showData(DataType::TEMPERATURE);
}

} // gui