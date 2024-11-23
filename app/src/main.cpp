#ifdef ZEPHYR
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#define LOG_LEVEL LOG_LEVEL_DBG
LOG_MODULE_REGISTER(main);
#endif

#include "log.h"

#include "hal.h"
#include "gui.h"

#include "lvgl.h"
#include <unistd.h>

int main() {    
   lv_init();

   Log::level(LogLevel::Debug);
   Log::info("Hello info");

   Hal hal;
   hal.init();

   Gui gui;
   gui.init();

   while (true) {
      uint32_t ms_delay = lv_timer_handler();
      usleep(ms_delay * 1000);
   }
   
   return 0;
}
