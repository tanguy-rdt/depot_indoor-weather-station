#include "gui.h"

#include "lvgl.h"
#include "data_type.h"

namespace gui {

Gui::Gui(Proxy* proxy, EventManager* eventManager)
    : _proxy(proxy), _eventManager(eventManager) {

    _screensManager = new ScreensManager(proxy, _eventManager);
    _screensManager->show(ScreenName::DATA_SCREEN_TEMPERATURE);

    _navCtrl = new NavCtrl(_screensManager);

    // _dataScreen = new DataScreen(_proxy, _eventManager);

    // _navCtrl.registerNewScreen(_dataScreen->getScreen());

    _eventManager->connect(EventManager::Signal::RIGHT_BUTTON_PRESSED, [this]() {
        _navCtrl->next();
    });
    //
    _eventManager->connect(EventManager::Signal::LEFT_BUTTON_PRESSED, [this]() {
        _navCtrl->prev();
    });
}

Gui::~Gui() {

}

void Gui::init() {
    // _navCtrl.next();
    _eventManager->emit(EventManager::Signal::GUI_UPDATED);
}




} // gui