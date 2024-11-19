#ifdef ZEPHYR
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#define LOG_LEVEL LOG_LEVEL_DBG
LOG_MODULE_REGISTER(main);
#endif

#include "hal.h"

#include "lvgl.h"
#include <unistd.h>

int main() {    
   lv_init();

   Hal hal;
   hal.init();


        lv_obj_t* label = lv_label_create(lv_scr_act());
        lv_label_set_text(label, "Hello, Round Screen!");
        lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

   while (true) {
      uint32_t ms_delay = lv_timer_handler();
      usleep(ms_delay * 1000);
   }
   
   return 0;
}
