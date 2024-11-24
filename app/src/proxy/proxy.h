/**
 * @file proxy.h
 * @brief Indoor Weather Station Proxy
 * @author Tanguy Roudaut
 * @date 24/11/2024
 */

#ifndef PROXY_H
#define PROXY_H

#include "model/model.h"


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
        Model _model;
};

} // proxy

#endif //PROXY_H
