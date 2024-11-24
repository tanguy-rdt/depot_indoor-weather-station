/**
 * @file data_refresher.h
 * @brief Manages scheduled data monitoring tasks using threading.
 * @author Tanguy Roudaut
 * @date 24/11/2024
 */


#ifndef DATA_REFRESHER_H
#define DATA_REFRESHER_H

#include <map>
#include <thread>

#include "data_type.h"

namespace proxy {

class DataRefresher {
    public:
    DataRefresher();
    ~DataRefresher();

    void newEntry(DataType dataType, int interval, std::function<void()> proxyFunction);
    void start();
    void stop();

    private:
    void run();

    using ProxyFunction = std::function<void()>;
    using MonitoredDataRegistry = std::map<DataType, std::tuple<int, int, ProxyFunction>>;

    std::thread _thread;
    bool _running;
    MonitoredDataRegistry _dataToMonitor;
};

} // proxy

#endif //DATA_REFRESHER_H
