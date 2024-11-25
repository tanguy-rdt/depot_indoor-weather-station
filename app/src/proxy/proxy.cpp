/**
 * @file proxy.cpp
 * @brief Indoor Weather Station Proxy
 * @author Tanguy Roudaut
 * @date 24/11/2024
 */


#include "proxy.h"

#include "log.h"

#include "hal/common/sensor_availability.h"
#include "hal/common/itf_sensor.h"
#include "hal/common/itf_bme680.h"


namespace proxy {

Proxy::Proxy(Hal* hal)
    : _hal(hal) {

    startAutomatedDataRefresh();
}

Proxy::~Proxy() {
    _dataRefresher.stop();
}

float Proxy::getTemperature() {
    std::lock_guard<std::mutex> lock(_mutex);

    if (const auto sensor = _hal->getSensor(Sensors::BME680)) {
        const auto bme680 = static_cast<ItfBME680*>(sensor);

        auto temp = bme680->getTemperature();
        if (temp != _model.getTemperature()) {
            _model.setTemperature(temp);

            Log::info("Proxy -- Temperature updated to %f", temp);
            // emit
        }
    }

    return _model.getTemperature();
}

float Proxy::getHumidity() {
    std::lock_guard<std::mutex> lock(_mutex);

    if (const auto sensor = _hal->getSensor(Sensors::BME680)) {
        const auto bme680 = static_cast<ItfBME680*>(sensor);

        auto hum = bme680->getHumidity();
        if (hum != _model.getHumidity()) {
            _model.setHumidity(hum);

            Log::info("Proxy -- Humidity updated to %f", hum);
            // emit
        }
    }

    return _model.getHumidity();
}

float Proxy::getPressure() {
    std::lock_guard<std::mutex> lock(_mutex);

    if (const auto sensor = _hal->getSensor(Sensors::BME680)) {
        const auto bme680 = static_cast<ItfBME680*>(sensor);

        auto press = bme680->getPressure();
        if (press != _model.getPressure()) {
            _model.setPressure(press);

            Log::info("Proxy -- Pressure updated to %f", press);
            // emit
        }
    }

    return _model.getPressure();
}

float Proxy::getAirQuality() {
    std::lock_guard<std::mutex> lock(_mutex);

    if (const auto sensor = _hal->getSensor(Sensors::BME680)) {
        const auto bme680 = static_cast<ItfBME680*>(sensor);

        auto airQuality = bme680->getAirQuality();
        if (airQuality != _model.getAirQuality()) {
            _model.setAirQuality(airQuality);

            Log::info("Proxy -- Air Quality updated to %f", airQuality);
            // emit
        }
    }

    return _model.getAirQuality();
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