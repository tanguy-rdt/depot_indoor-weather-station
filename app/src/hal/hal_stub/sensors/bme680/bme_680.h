/**
 * @file BME680
 * @brief [Description]
 * @author Tanguy Roudaut
 * @date 24/11/2024
 */

#ifndef BME_680_H
#define BME_680_H

#include "itf_bme680.h"

namespace sensors {

class BME680: public ItfBME680 {
    public:
        BME680() = default;
        ~BME680() = default;

        float getTemperature() const override;
        float getHumidity() const override;
        float getPressure() const override;
        float getAirQuality() const override;

};

} // sensors

#endif //BME_680_H
