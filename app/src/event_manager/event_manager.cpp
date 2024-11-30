/**
 * @file EventManager
 * @brief [Description]
 * @author Tanguy Roudaut
 * @date 25/11/2024
 */

#include "event_manager.h"


void EventManager::connect(Signal sig, std::function<void()> cb) {
    sig == Signal::TEMPERATURE_UPDATED  ? _temperatureUpdated.connect(cb) :
    sig == Signal::HUMIDITY_UPDATED     ? _humidityUpdated.connect(cb)    :
    sig == Signal::PRESSURE_UPDATED     ? _pressureUpdated.connect(cb)    :
    sig == Signal::AIR_QUALITY_UPDATED  ? _airQualityUpdated.connect(cb)  :
    sig == Signal::GUI_UPDATED          ? _guiUpdated.connect(cb)         :
    sig == Signal::LEFT_BUTTON_PRESSED  ? _leftButtonPressed.connect(cb)  :
    sig == Signal::RIGHT_BUTTON_PRESSED ? _rightButtonPressed.connect(cb) :
    sig == Signal::OK_BUTTON_PRESSED    ? _okButtonPressed.connect(cb)    : sigslot::connection();
}

void EventManager::emit(Signal sig) {
    sig == Signal::TEMPERATURE_UPDATED  ? _temperatureUpdated() :
    sig == Signal::HUMIDITY_UPDATED     ? _humidityUpdated()    :
    sig == Signal::PRESSURE_UPDATED     ? _pressureUpdated()    :
    sig == Signal::AIR_QUALITY_UPDATED  ? _airQualityUpdated()  :
    sig == Signal::GUI_UPDATED          ? _guiUpdated()         :
    sig == Signal::LEFT_BUTTON_PRESSED  ? _leftButtonPressed()  :
    sig == Signal::RIGHT_BUTTON_PRESSED ? _rightButtonPressed() :
    sig == Signal::OK_BUTTON_PRESSED    ? _okButtonPressed()    : void();
}