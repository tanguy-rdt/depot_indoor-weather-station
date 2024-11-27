/**
 * @file BME680
 * @brief [Description]
 * @author Tanguy Roudaut
 * @date 24/11/2024
 */

#include "bme_680.h"

#include <random>

namespace sensors {

float BME680::getTemperature() const {
    return random() % 20 + 20;
}

float BME680::getHumidity() const {
    return 50.0;
}

float BME680::getPressure() const {
    return 1013.25;
}

float BME680::getAirQuality() const {
    return 100.0;
}

} // sensors