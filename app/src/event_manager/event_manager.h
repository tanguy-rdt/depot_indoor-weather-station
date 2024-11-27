/**
 * @file EventManager
 * @brief [Description]
 * @author Tanguy Roudaut
 * @date 25/11/2024
 */

#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include "sigslot/signal.hpp"

class EventManager {

    public:
      EventManager() = default;
      ~EventManager() = default;

      enum class Signal {
          TEMPERATURE_UPDATED,
          HUMIDITY_UPDATED,
          PRESSURE_UPDATED,
          AIR_QUALITY_UPDATED,
          LEFT_BUTTON_PRESSED,
          RIGHT_BUTTON_PRESSED,
          OK_BUTTON_PRESSED,
      };

      void connect(Signal sig, std::function<void()> cb);
      void emit(Signal sig);

    private:
        sigslot::signal<> _temperatureUpdated;
        sigslot::signal<> _humidityUpdated;
        sigslot::signal<> _pressureUpdated;
        sigslot::signal<> _airQualityUpdated;
        sigslot::signal<> _leftButtonPressed;
        sigslot::signal<> _rightButtonPressed;
        sigslot::signal<> _okButtonPressed;

};



#endif //EVENT_MANAGER_H
