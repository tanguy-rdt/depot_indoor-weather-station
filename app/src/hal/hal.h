#ifndef HAL_H
#define HAL_H

#include <memory>
#include <sensors/bme680/bme_680.h>
#include "event_manager/event_manager.h"

#include "itf_hal.h"
#include "common/itf_sensor.h"

#include "common/sensor_availability.h"

class Hal {

public:
    Hal(EventManager* eventManager);
    ~Hal();

    void init();
    ItfSensor* getSensor(Sensors sensor) const;

private:
    ItfHal* _hal;

};


#endif // HAL_H
