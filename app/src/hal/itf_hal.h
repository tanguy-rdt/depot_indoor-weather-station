#ifndef ITF_HAL_H
#define ITF_HAL_H

#include "common/itf_sensor.h"
#include "common/sensor_availability.h"
#include "sensors/bme680/bme_680.h"

class ItfHal {
public:
    virtual ~ItfHal() = default;

    virtual void init() = 0;
    virtual void setDisplayBrightness(int percent) = 0;
    virtual ItfSensor* getSensor(Sensors sensor) = 0;
};

#endif // ITF_HAL_H