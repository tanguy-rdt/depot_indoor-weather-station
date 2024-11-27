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

        using UpdaterCb = std::function<bool()>;
        using NotifierCb = std::function<void()>;

        void newEntry(DataType dataType, int interval, const UpdaterCb& updater, const NotifierCb& notifier);
        void start();
        void stop();

    private:
        void run();

        struct DataRefresherEntry {
            UpdaterCb updater;
            NotifierCb notifier;
            int interval;
            int tick;
        };

        std::thread _thread;
        bool _running;

        using MonitoredDataRegistry = std::map<DataType, DataRefresherEntry>;
        MonitoredDataRegistry _dataToMonitor;
};

} // proxy

#endif //DATA_REFRESHER_H
