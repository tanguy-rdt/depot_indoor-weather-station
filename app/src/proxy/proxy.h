/**
 * @file proxy.h
 * @brief Indoor Weather Station Proxy
 * @author Tanguy Roudaut
 * @date 24/11/2024
 */

#ifndef PROXY_H
#define PROXY_H

#include <mutex>

#include "model/model.h"
#include "data_refresher/data_refresher.h"

namespace proxy {

class Proxy {
    public:
        Proxy();
        ~Proxy();

        float getTemperature() const;
        void  setTemperature(float temp);

        float getHumidity() const;
        void  setHumidity(float hum);

        float getPressure() const;
        void  setPressure(float press);

        float getAirQuality() const;
        void  setAirQuality(float airQuality);

    private:
        void startAutomatedDataRefresh();

        mutable std::mutex _mutex;

        DataRefresher _dataRefresher;
        Model _model;
};

} // proxy

#endif //PROXY_H
