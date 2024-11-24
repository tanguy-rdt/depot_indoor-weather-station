/**
 * @file data_type.h
 * @brief Defines the DataType enum and provides utility functions for data type conversion.
 * @author Tanguy Roudaut
 * @date 24/11/2024
 */


#ifndef DATA_TYPE_H
#define DATA_TYPE_H

#include <string>

enum class DataType {
    TEMPERATURE,
    HUMIDITY,
    PRESSURE,
    AIR_QUALITY,
};

namespace tools {

    inline std::string dataTypeToString(const DataType& dataType) {
        std::string str = dataType == DataType::TEMPERATURE ? "TEMPERATURE" :
                          dataType == DataType::HUMIDITY    ? "HUMIDITY"    :
                          dataType == DataType::PRESSURE    ? "PRESSURE"    :
                          dataType == DataType::AIR_QUALITY ? "AIR_QUALITY" :
                                                              "UNKNOWN";

        return str;
    }

}

#endif //DATA_TYPE_H
