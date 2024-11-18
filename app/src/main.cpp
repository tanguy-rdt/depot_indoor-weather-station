#ifdef ZEPHYR
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#define LOG_LEVEL LOG_LEVEL_DBG
LOG_MODULE_REGISTER(main);
#endif

int main(void)
{    
   return 0;
}
