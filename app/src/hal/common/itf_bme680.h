/**
 * @file ItfBME680
 * @brief [Description]
 * @author Tanguy Roudaut
 * @date 25/11/2024
 */

#ifndef ITF_BME680_H
#define ITF_BME680_H

#include "itf_sensor.h"

class ItfBME680 : public ItfSensor {
    public:
        virtual ~ItfBME680() = default;
        virtual float getTemperature() const = 0;
        virtual float getHumidity() const = 0;
        virtual float getPressure() const = 0;
        virtual float getAirQuality() const = 0;
};

#endif // ITF_BME680_H