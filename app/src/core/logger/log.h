#ifndef LOG_H
#define LOG_H

#include "logger.h"


/**
 * @namespace Log
 * @brief Provides inline logging functions for simplified access to the logging system.
 *
 * The `Log` namespace wraps the `Core::Logger` functionality into concise inline functions for
 * setting log levels and sending messages to the logger.
 */
namespace Log {


/**
 * @brief Sets the logging level.
 * Messages with a lower severity level than the specified level will be ignored.
 * @param level The minimum log level to display.
 */
inline void level(LogLevel level) {
    Core::Logger::setLevel(level);
}


/**
 * @brief Logs a debug-level message.
 * @param msg The message to log.
 */
inline void debug(const std::string& msg) {
    Core::Logger::log(LogLevel::DEBUG, msg);
}


/**
 * @brief Logs an info-level message.
 * @param msg The message to log.
 */
inline void info(const std::string& msg) {
    Core::Logger::log(LogLevel::INFO, msg);
}


/**
 * @brief Logs an warn-level message.
 * @param msg The message to log.
 */
inline void warn(const std::string& msg) {
    Core::Logger::log(LogLevel::WARNING, msg);
}


/**
 * @brief Logs an error-level message.
 * @param msg The message to log.
 */
inline void error(const std::string& msg) {
    Core::Logger::log(LogLevel::ERROR, msg);
}


/**
 * @brief Logs an critical-level message.
 * @param msg The message to log.
 */
inline void critical(const std::string& msg) {
    Core::Logger::log(LogLevel::CRITICAL, msg);
}

} // Log

#endif // LOG_H
