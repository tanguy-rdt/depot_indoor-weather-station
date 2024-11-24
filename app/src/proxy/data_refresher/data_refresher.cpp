/**
 * @file data_refresher.cpp
 * @brief Manages scheduled data monitoring tasks using threading.
 * @author Tanguy Roudaut
 * @date 24/11/2024
 */
 

#include "data_refresher.h"

#include "log.h"

namespace proxy {

DataRefresher::DataRefresher() {
    _running = false;
}

DataRefresher::~DataRefresher() {

}

void DataRefresher::start() {
    _thread = std::thread(&DataRefresher::run, this);
    _running = true;
}

void DataRefresher::stop() {
    _running = false;
    if (_thread.joinable()) {
        _thread.join();
        Log::info("DataRefresher -- Stopped");
    }
}

void DataRefresher::newEntry(DataType dataType, int interval, std::function<void()> proxyFunction) {
    Log::debug("DataRefresher -- New entry for data type %s", tools::dataTypeToString(dataType).c_str());
    _dataToMonitor.emplace(dataType, std::make_tuple(interval, 0, proxyFunction));
}

void DataRefresher::run() {
    Log::info("DataRefresher -- Running");

    while (_running) {
        for (auto& [dataType, data] : _dataToMonitor) {
            data = std::make_tuple(std::get<0>(data), std::get<1>(data) + 1, std::get<2>(data));
            if (std::get<1>(data) >= std::get<0>(data)) {
                std::get<2>(data)();
                std::get<1>(data) = 0;
            }
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

} // proxy