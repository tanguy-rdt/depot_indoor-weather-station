#ifndef HAL_STUB_H
#define HAL_STUB_H

#include "itf_hal.h"
#include "display.h"
#include "mouse.h"
#include "keyboard_ui_shortcut.h"
#include "event_manager/event_manager.h"

#include "common/itf_sensor.h"
#include "common/sensor_availability.h"

#include "sensors/bme680/bme_680.h"


class HalStub: public ItfHal {

public:
    HalStub(EventManager* eventManager);
    ~HalStub();

    void init();
    void setDisplayBrightness(int percent);
    ItfSensor* getSensor(Sensors sensor) override;

private:
    Display* _display;
    Mouse* _mouse;
    KeyboardUiShortcut* _keyboardUiShortcut;

    sensors::BME680 _bme680;
};


#endif // HAL_STUB_H
