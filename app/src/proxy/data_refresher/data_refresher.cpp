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

void DataRefresher::newEntry(DataType dataType, const int interval, const UpdaterCb& updater, const NotifierCb& notifier) {
    Log::debug("DataRefresher -- New entry for data type %s", tools::dataTypeToString(dataType).c_str());

    DataRefresherEntry entry = {
        .updater = updater,
        .notifier = notifier,
        .interval = interval,
        .tick = 0
    };

    _dataToMonitor.emplace(dataType,entry);
}

void DataRefresher::run() {
    Log::info("DataRefresher -- Running");

    while (_running) {
        for (auto& [dataType, entry] : _dataToMonitor) {
            if (entry.tick == entry.interval) {
                entry.tick = 0;
                if (entry.updater()) {
                    entry.notifier();
                }
            } else {
                entry.tick++;
            }
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

} // proxy