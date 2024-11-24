/**
 * @file model.cpp
 * @brief Indoor Weather Station Model
 * @author Tanguy Roudaut
 * @date 24/11/2024
 */

#include "model.h"

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

void Model::setTemperature(float temp) {
    _temp = temp;
}

float Model::getHumidity() const {
    return _hum;
}

void Model::setHumidity(float hum) {
    _hum = hum;
}

float Model::getPressure() const {
    return _press;
}

void Model::setPressure(float press) {
    _press = press;
}

float Model::getAirQuality() const {
    return _airQuality;
}

void Model::setAirQuality(float airQuality) {
    _airQuality = airQuality;
}

} // proxy