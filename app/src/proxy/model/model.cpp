/**
 * @file model.cpp
 * @brief Indoor Weather Station Model
 * @author Tanguy Roudaut
 * @date 24/11/2024
 */

#include "model.h"
#include "log.h"

namespace proxy {

Model::Model() {
    _temp = 35.0;
    _hum = 100.0;
    _press = 1050.0;
    _airQuality = 500.0;
}

Model::~Model() {

}

float Model::getTemperature() const {
    return _temp;
}

void Model::setTemperature(const float temp) {
    _temp = temp;
    Log::debug("Model -- Temperature set to %f", _temp);
}

float Model::getHumidity() const {
    return _hum;
}

void Model::setHumidity(const float hum) {
    _hum = hum;
    Log::debug("Model -- Humidity set to %f", _hum);
}

float Model::getPressure() const {
    return _press;
}

void Model::setPressure(const float press) {
    _press = press;
    Log::debug("Model -- Pressure set to %f", _press);
}

float Model::getAirQuality() const {
    return _airQuality;
}

void Model::setAirQuality(const float airQuality) {
    _airQuality = airQuality;
    Log::debug("Model -- Air quality set to %f", _airQuality);
}

} // proxy