/**
 * @file proxy.cpp
 * @brief Indoor Weather Station Proxy
 * @author Tanguy Roudaut
 * @date 24/11/2024
 */

#include "proxy.h"

namespace proxy {

Proxy::Proxy() {

}

Proxy::~Proxy() {

}

float Proxy::getTemperature() const {
    return _model.getTemperature();
}

void Proxy::setTemperature(float temp) {
    _model.setTemperature(temp);
}

float Proxy::getHumidity() const {
    return _model.getHumidity();
}

void Proxy::setHumidity(float hum) {
    _model.setHumidity(hum);
}

float Proxy::getPressure() const {
    return _model.getPressure();
}

void Proxy::setPressure(float press) {
    _model.setPressure(press);
}

float Proxy::getAirQuality() const {
    return _model.getAirQuality();
}

void Proxy::setAirQuality(float airQuality) {
    _model.setAirQuality(airQuality);
}

} // proxy