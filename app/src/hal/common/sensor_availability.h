/**
 * @file sensor_availability
 * @brief [Description]
 * @author Tanguy Roudaut
 * @date 24/11/2024
 */

#ifndef SENSOR_AVAILABILITY_H
#define SENSOR_AVAILABILITY_H

enum class Sensors {
    NONE,
    BME680,
};

namespace sensors {

    inline bool isSensorAvailable(Sensors sensor) {
        return sensor == Sensors::BME680;
    }

} // sensors

#endif //SENSOR_AVAILABILITY_H
