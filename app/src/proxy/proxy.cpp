/**
 * @file proxy.cpp
 * @brief Indoor Weather Station Proxy
 * @author Tanguy Roudaut
 * @date 24/11/2024
 */


#include "proxy.h"
#include "log.h"

namespace proxy {

Proxy::Proxy() {
    startAutomatedDataRefresh();
}

Proxy::~Proxy() {
    _dataRefresher.stop();
}

float Proxy::getTemperature() const {
    std::lock_guard<std::mutex> lock(_mutex);

    return _model.getTemperature();
}

void Proxy::setTemperature(float temp) {
    _model.setTemperature(temp);
}

float Proxy::getHumidity() const {
    std::lock_guard<std::mutex> lock(_mutex);

    return _model.getHumidity();
}

void Proxy::setHumidity(float hum) {
    _model.setHumidity(hum);
}

float Proxy::getPressure() const {
    std::lock_guard<std::mutex> lock(_mutex);

    return _model.getPressure();
}

void Proxy::setPressure(float press) {
    _model.setPressure(press);
}

float Proxy::getAirQuality() const {
    std::lock_guard<std::mutex> lock(_mutex);

    return _model.getAirQuality();
}

void Proxy::setAirQuality(float airQuality) {
    _model.setAirQuality(airQuality);
}

void Proxy::startAutomatedDataRefresh() {
    _dataRefresher.newEntry(DataType::TEMPERATURE, 1, [this]() {
        (void) this->getTemperature();
    });
    _dataRefresher.newEntry(DataType::HUMIDITY, 2, [this]() {
        (void) this->getHumidity();
    });
    _dataRefresher.newEntry(DataType::PRESSURE, 5, [this]() {
        (void) this->getPressure();
    });
    _dataRefresher.newEntry(DataType::AIR_QUALITY, 10, [this]() {
        (void) this->getAirQuality();
    });

    _dataRefresher.start();
}

} // proxy