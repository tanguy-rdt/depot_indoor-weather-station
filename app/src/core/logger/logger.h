#ifndef LOGGER_H
#define LOGGER_H

#include "itf_logger.h"
#include "singleton.h"


namespace Core {

/**
 * @class Logger
 * @brief A centralized logger manager.
 *
 * The `Logger` class acts as a facade for the logging system. It uses the Singleton pattern
 * to ensure there is only one instance of the logger throughout the application.
 * The actual logging is performed by an implementation of the `ItfLogger` interface.
 *
 * @note The `Logger` class is not directly instantiable. Use the `Singleton<Logger>::getInstance()`
 *       or its static methods to interact with the logger.
 */
class Logger: public Singleton<Logger> {

public:

    /**
     * @brief Grants the Singleton base class access to private members.
     * Allows `Singleton<Logger>` to manage the lifecycle of the `Logger` instance.
     */
    friend class Singleton<Logger>;

    static void setLevel(LogLevel level);
    static void log(LogLevel level, const std::string& message);

private:
    Logger();
    ~Logger();

    static Logger* _instance;
    static ItfLogger* _logger;
};

}

#endif // LOGGER_H
