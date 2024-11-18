#ifdef ZEPHYR
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#define LOG_LEVEL LOG_LEVEL_DBG
LOG_MODULE_REGISTER(main);
#endif

#include "hal.h"
#include "lvgl.h"

int main() {    
   Hal hal;
   hal.init();
   
   return 0;
}
