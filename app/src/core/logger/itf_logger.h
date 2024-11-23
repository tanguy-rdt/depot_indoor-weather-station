#ifndef ITF_LOGGER_H
#define ITF_LOGGER_H

#include <string>


/**
 * @class ItfLogger
 * @brief Interface for logger implementations.
 *
 * The `ItfLogger` class defines a common interface for logging functionality.
 * This interface ensures a consistent logging API across different systems.
 */
class ItfLogger {
    public:

        /**
        * @enum Level
        * @brief Represents the severity levels for log messages.
        */
        enum class Level {
            Debug,
            Info,
            Warning,
            Error,
            Critical,
            None
        };


        /**
        * @brief Sets the minimum log level.
        * Messages below this level of severity will be ignored.
        *
        * @param level The minimum severity level to log.
        */
        virtual void setLevel(Level level) = 0;


        /**
        * @brief Logs a message with a specific severity level.
        *
        * @param level The severity level of the log message.
        * @param message The message to log.
        */
        virtual void log(Level level, const std::string& message) = 0;
};


/**
 * @typedef LogLevel
 * @brief Alias for `ItfLogger::Level`.
 */
using LogLevel =  ItfLogger::Level;


#endif // ITF_LOGGER_H