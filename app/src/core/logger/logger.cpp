#include "logger.h"

#ifdef SIMU
    #include "std_logger.h"
#else 
    #error "No LOGGER type specified"
#endif

#include <cstdarg>

namespace Core {

    ItfLogger* Logger::_logger = nullptr;

    Logger::Logger() {
        #ifdef SIMU
            _logger = new StdLogger();
        #endif
    }

    Logger::~Logger() {
        delete _logger;
    }


    /**
     * Sets the logging level for the Logger instance.
     *
     * @param level The log level to set for the Logger.
     */
    void Logger::setLevel(LogLevel level) {
        auto& instance = Singleton<Logger>::getInstance();
        if (instance._logger)
            instance._logger->setLevel(level);
    }


    /**
     * Logs a message with the specified log level.
     *
     * @param message The message.
     */
    void Logger::log(LogLevel level, const std::string& message) {
        auto& instance = Singleton<Logger>::getInstance();
        if (instance._logger)
            _logger->log(level, message, nullptr);
    }


    /**
     * Logs a message with the specified log level and arguments.
     *
     * @param message The message.
     * @param ... The arguments.
     */
    void Logger::log(LogLevel level, const std::string& message, va_list args) {
        auto& instance = Singleton<Logger>::getInstance();
        if (instance._logger)
            _logger->log(level, message, args);
    }

}