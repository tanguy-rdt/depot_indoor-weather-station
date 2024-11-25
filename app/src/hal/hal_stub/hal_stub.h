#ifndef HAL_STUB_H
#define HAL_STUB_H

#include <memory>

#include "itf_hal.h"
#include "display.h"

#include "common/itf_sensor.h"
#include "common/sensor_availability.h"

#include "sensors/bme680/bme_680.h"


class HalStub: public ItfHal {

public:
    HalStub();
    ~HalStub();

    void init();
    void setDisplayBrightness(int percent);
    ItfSensor* getSensor(Sensors sensor) override;

private:
    std::unique_ptr<Display> _display;
    sensors::BME680 _bme680;
};


#endif // HAL_STUB_H
