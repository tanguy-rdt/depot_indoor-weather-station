#ifndef HAL_H
#define HAL_H

#include <memory>
#include <sensors/bme680/bme_680.h>

#include "itf_hal.h"
#include "common/itf_sensor.h"

#include "common/sensor_availability.h"

class Hal {

public:
    Hal();
    ~Hal();

    void init();
    ItfSensor* getSensor(Sensors sensor) const;

private:
    std::unique_ptr<ItfHal> _hal;

};


#endif // HAL_H
