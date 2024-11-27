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

Proxy::Proxy(Hal* hal, EventManager* eventManager)
    : _hal(hal), _eventManager(eventManager) {

    getTemperature(true);
    getHumidity(true);
    getPressure(true);
    getAirQuality(true);

    startAutomatedDataRefresh();
}

Proxy::~Proxy() {
    _dataRefresher.stop();
}

float Proxy::getTemperature(const bool update) {
    if (update) tryTemperatureUpdate();

    return _model.getTemperature();
}

bool Proxy::tryTemperatureUpdate() {
    Log::debug("Proxy -- Temperature update attempt");

    std::lock_guard<std::mutex> lock(_mutex);

    const auto sensor = _hal->getSensor(Sensors::BME680);
    if (sensor) {
        const auto bme680 = static_cast<ItfBME680*>(sensor);

        auto newTemp = bme680->getTemperature();
        if (_model.getTemperature() != newTemp) {
            _model.setTemperature(newTemp);
            return true;
        }

        Log::debug("Proxy -- Temperature update failed: no change");

    } else {
        Log::error("Proxy -- Temperature update failed: no BME680 sensor");
    }

    return false;
}

void Proxy::notifyTemperatureUpdated() const {
    Log::debug("Proxy -- Notify temperature updated");

    _eventManager->emit(EventManager::Signal::TEMPERATURE_UPDATED);
}

float Proxy::getHumidity(const bool update) {
    if (update) tryHumidityUpdate();

    return _model.getHumidity();
}

bool Proxy::tryHumidityUpdate() {
    Log::debug("Proxy -- Humidity update attempt");

    std::lock_guard<std::mutex> lock(_mutex);

    const auto sensor = _hal->getSensor(Sensors::BME680);
    if (sensor) {
        const auto bme680 = static_cast<ItfBME680*>(sensor);

        auto newHum = bme680->getHumidity();
        if (_model.getHumidity() != newHum) {
            _model.setHumidity(newHum);
            return true;
        }

        Log::debug("Proxy -- Humidity update failed: no change");

    } else {
        Log::error("Proxy -- Humidity update failed: no BME680 sensor");
    }

    return false;
}

void Proxy::notifyHumidityUpdated() const {
    Log::debug("Proxy -- Notify humidity updated");

    _eventManager->emit(EventManager::Signal::HUMIDITY_UPDATED);
}

float Proxy::getPressure(const bool update) {
    if (update) tryPressureUpdate();

    return _model.getPressure();
}

bool Proxy::tryPressureUpdate() {
    Log::debug("Proxy -- Pressure update attempt");

    std::lock_guard<std::mutex> lock(_mutex);

    const auto sensor = _hal->getSensor(Sensors::BME680);
    if (sensor) {
        const auto bme680 = static_cast<ItfBME680*>(sensor);

        auto newPress = bme680->getPressure();
        if (_model.getPressure() != newPress) {
            _model.setPressure(newPress);
            return true;
        }

        Log::debug("Proxy -- Pressure update failed: no change");

    } else {
        Log::error("Proxy -- Pressure update failed: no BME680 sensor");
    }

    return false;
}

void Proxy::notifyPressureUpdated() const {
    Log::debug("Proxy -- Notify pressure updated");

    _eventManager->emit(EventManager::Signal::PRESSURE_UPDATED);
}

float Proxy::getAirQuality(const bool update) {
    if (update) tryAirQualityUpdate();

    return _model.getAirQuality();
}

bool Proxy::tryAirQualityUpdate() {
    Log::debug("Proxy -- Air quality update attempt");

    std::lock_guard<std::mutex> lock(_mutex);

    const auto sensor = _hal->getSensor(Sensors::BME680);
    if (sensor) {
        const auto bme680 = static_cast<ItfBME680*>(sensor);

        auto newAirQ = bme680->getAirQuality();
        if (_model.getAirQuality() != newAirQ) {
            _model.setAirQuality(newAirQ);
            return true;
        }

        Log::debug("Proxy -- Air quality update failed: no change");

    } else {
        Log::error("Proxy -- Air quality update failed: no BME680 sensor");
    }

    return false;
}

void Proxy::notifyAirQualityUpdated() const {
    Log::debug("Proxy -- Notify air quality updated");

    _eventManager->emit(EventManager::Signal::AIR_QUALITY_UPDATED);
}

void Proxy::startAutomatedDataRefresh() {
    _dataRefresher.newEntry(DataType::TEMPERATURE, 3,
        [this]() { return this->tryTemperatureUpdate(); },
        [this]() { this->notifyTemperatureUpdated(); });

    _dataRefresher.newEntry(DataType::HUMIDITY, 6,
        [this]() { return this->tryHumidityUpdate(); },
        [this]() { this->notifyHumidityUpdated(); });

    _dataRefresher.newEntry(DataType::PRESSURE, 12,
        [this]() { return this->tryPressureUpdate(); },
        [this]() { this->notifyPressureUpdated(); });

    _dataRefresher.newEntry(DataType::AIR_QUALITY, 24,
        [this]() { return this->tryAirQualityUpdate(); },
        [this]() { this->notifyAirQualityUpdated(); });

    _dataRefresher.start();
}

} // proxy