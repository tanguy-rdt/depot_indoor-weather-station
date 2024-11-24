#include "gui.h"

#include "lvgl.h"

namespace gui {

Gui::Gui() {
    _dataScreen = new DataScreen();
}

Gui::~Gui() {

}

void Gui::init() {
    lv_scr_load(_dataScreen->getScreen());
    _dataScreen->showData(DataScreen::Types::TEMPERATURE);
}

} // gui