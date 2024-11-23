#include "logger.h"

#ifdef SIMU
    #include "std_logger.h"
#else 
    #error "No LOGGER type specified"
#endif

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


void Logger::setLevel(LogLevel level) {
    auto& instance = Singleton<Logger>::getInstance();
    if (instance._logger)
        instance._logger->setLevel(level);
}

void Logger::log(LogLevel level, const std::string& message) {
    auto& instance = Singleton<Logger>::getInstance();
    if (instance._logger)
        _logger->log(level, message);
}

}