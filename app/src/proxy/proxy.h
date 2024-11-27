/**
 * @file proxy.h
 * @brief Indoor Weather Station Proxy
 * @author Tanguy Roudaut
 * @date 24/11/2024
 */

#ifndef PROXY_H
#define PROXY_H

#include <mutex>
#include <event_manager/event_manager.h>

#include "hal/hal.h"
#include "model/model.h"
#include "data_refresher/data_refresher.h"

namespace proxy {

class Proxy {
    public:
        Proxy(Hal* hal, EventManager* eventManager);
        ~Proxy();

        float getTemperature(bool update = false);
        bool tryTemperatureUpdate();
        void notifyTemperatureUpdated() const;

        float getHumidity(bool update = false);
        bool tryHumidityUpdate();
        void notifyHumidityUpdated() const;

        float getPressure(bool update = false);
        bool tryPressureUpdate();
        void notifyPressureUpdated() const;

        float getAirQuality(bool update = false);
        bool tryAirQualityUpdate();
        void notifyAirQualityUpdated() const;

    private:
        void startAutomatedDataRefresh();

        mutable std::mutex _mutex;

        Hal* _hal;
        Model _model;
        DataRefresher _dataRefresher;
        EventManager* _eventManager;
};

} // proxy

#endif //PROXY_H
