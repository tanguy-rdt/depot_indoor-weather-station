#ifndef STD_LOGGER_H
#define STD_LOGGER_H

#include <string>

#include "itf_logger.h"

/**
 * @class StdLogger
 * @brief A standard logger implementation for console output using the std librairie.
 *
 * The `StdLogger` class provides a concrete implementation of the `ItfLogger` interface.
 */
class StdLogger: public ItfLogger {

public:
    StdLogger(LogLevel level = LogLevel::Info);
    ~StdLogger();

    void setLevel(LogLevel level);
    void log(Level level, const std::string& message, va_list args);

private:
    std::string levelToString(LogLevel level) const;
    std::string levelToColor(LogLevel level) const;
    std::string levelToStyle(LogLevel level) const;
    std::string getTimestamp() const;

    LogLevel _level;
};


#endif // STD_LOGGER_H
