#ifdef ZEPHYR
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#define LOG_LEVEL LOG_LEVEL_DBG
LOG_MODULE_REGISTER(main);
#endif

#include "log.h"

#include "hal.h"
#include "proxy/proxy.h"
#include "gui.h"
#include "event_manager/event_manager.h"
#include <unistd.h>

#include "lvgl.h"

using namespace proxy;
using namespace gui;

int main() {
   lv_init();

   EventManager eventManager;

   #ifdef DEBUG
      Log::level(LogLevel::Debug);
   #else
      Log::level(LogLevel::Info);
   #endif

   Hal hal;
   hal.init();

   Proxy proxy(&hal, &eventManager);

   Gui gui(&proxy, &eventManager);
   gui.init();

   while (true) {
      uint32_t ms_delay = lv_timer_handler();
      usleep(ms_delay * 1000);
   }

   return 0;
}
