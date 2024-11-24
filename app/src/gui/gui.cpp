#include "gui.h"

#include "lvgl.h"

namespace gui {

Gui::Gui(Proxy* proxy)
    : _proxy(proxy) {

    _dataScreen = new DataScreen(_proxy);
}

Gui::~Gui() {

}

void Gui::init() {
    lv_scr_load(_dataScreen->getScreen());
    _dataScreen->showData(DataScreen::Types::AIR_QUALITY);
}

} // gui