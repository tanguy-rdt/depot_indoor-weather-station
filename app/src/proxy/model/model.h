/**
 * @file model.h
 * @brief Indoor Weather Station Model
 * @author Tanguy Roudaut
 * @date 24/11/2024
 */

#ifndef MODEL_H
#define MODEL_H

namespace proxy {

class Model {
    public:
        Model();
        ~Model();

        float getTemperature() const;
        void  setTemperature(float temp);

        float getHumidity() const;
        void  setHumidity(float hum);

        float getPressure() const;
        void  setPressure(float press);

        float getAirQuality() const;
        void  setAirQuality(float airQuality);

    private:
        float _temp;
        float _hum;
        float _press;
        float _airQuality;
};

} // proxy

#endif //MODEL_H
