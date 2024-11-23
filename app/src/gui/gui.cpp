#include "gui.h"

#include "lvgl.h"

Gui::Gui() {

}

Gui::~Gui() {

}

void Gui::init() {
    ci = new Widgets::CircularIndicator(0, 0, 110);
    ci->setRange(0.0, 100.0);
    ci->setAngle(45, 315);
    ci->setWidth(15);
    ci->setColors({lv_palette_main(LV_PALETTE_YELLOW), lv_palette_main(LV_PALETTE_ORANGE), lv_palette_main(LV_PALETTE_RED)});
    ci->setValue(25.0);
    ci->draw();
}