/**
 * @file proxy.h
 * @brief Indoor Weather Station Proxy
 * @author Tanguy Roudaut
 * @date 24/11/2024
 */

#ifndef PROXY_H
#define PROXY_H

#include <mutex>

#include "hal/hal.h"
#include "model/model.h"
#include "data_refresher/data_refresher.h"

namespace proxy {

class Proxy {
    public:
        Proxy(Hal* hal);
        ~Proxy();

        float getTemperature();
        float getHumidity();
        float getPressure();
        float getAirQuality();

    private:
        void startAutomatedDataRefresh();

        mutable std::mutex _mutex;

        Hal* _hal;
        DataRefresher _dataRefresher;
        Model _model;
};

} // proxy

#endif //PROXY_H
