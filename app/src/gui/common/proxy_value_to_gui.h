/**
 * @file proxy_value_to_gui.h
 * @brief Toolbox to convert proxy value to GUI string
 * @author Tanguy Roudaut
 * @date 24/11/2024
 */

#ifndef PROXY_VALUE_TO_GUI_H
#define PROXY_VALUE_TO_GUI_H

#include <string>
#include <sstream>
#include <iomanip>

namespace tools {

/**
 * @brief Converts a boolean value to its string representation for GUI display.
 *
 * @param value The boolean value to be converted.
 * @return A string "true" if the input value is true, otherwise "false".
 */
inline std::string convertToGUI(const bool& value) {
    return value ? "true" : "false";
}

/**
 * @brief Converts a floating-point value to a string format suitable for GUI display.
 *
 * @param value The floating-point value to be converted.
 * @return A string representation of the rounded floating point value
 */
inline std::string convertToGUI(const float& value) {
    std::ostringstream oss;
    oss << std::setprecision(4) << value;
    return oss.str();
}

/**
 * @brief Converts a double value to a string for GUI display.
 *
 * @param value The double value to be converted to string.
 * @return A string representation of the rounded double value
 */
inline std::string convertToGUI(const double& value) {
    std::ostringstream oss;
    oss << std::setprecision(4) << value;
    return oss.str();
}

} // tools

#endif //PROXY_VALUE_TO_GUI_H
