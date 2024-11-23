#ifndef LOG_H
#define LOG_H

#include <cstdarg>

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
inline void debug(const std::string& msg, ...) {
    va_list args;
    va_start(args, msg);
    Core::Logger::log(LogLevel::Debug, msg, args);
    va_end(args);
}


/**
 * @brief Logs an info-level message.
 * @param msg The message to log.
 */
inline void info(const std::string& msg, ...) {
    va_list args;
    va_start(args, msg);
    Core::Logger::log(LogLevel::Info, msg, args);
    va_end(args);
}


/**
 * @brief Logs an warn-level message.
 * @param msg The message to log.
 */
inline void warn(const std::string& msg, ...) {
    va_list args;
    va_start(args, msg);
    Core::Logger::log(LogLevel::Warning, msg, args);
    va_end(args);
}


/**
 * @brief Logs an error-level message.
 * @param msg The message to log.
 */
inline void error(const std::string& msg, ...) {
    va_list args;
    va_start(args, msg);
    Core::Logger::log(LogLevel::Error, msg, args);
    va_end(args);
}


/**
 * @brief Logs an critical-level message.
 * @param msg The message to log.
 */
inline void critical(const std::string& msg, ...) {
    va_list args;
    va_start(args, msg);
    Core::Logger::log(LogLevel::Error, msg, args);
    va_end(args);
}

} // Log

#endif // LOG_H
