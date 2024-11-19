#ifndef HAL_CONF_INTERNAL_H
#ifdef __has_include
    #if __has_include("hal_conf.h")
        #include "hal_conf.h"
    #else
        #error "hal_conf.h is missing"
    #endif
#endif
#endif  /*HAL_CONF_INTERNAL_H*/


#ifdef CONF_HAL_SCREEN_WIDTH
    #define HAL_SCREEN_WIDTH CONF_HAL_SCREEN_WIDTH
#else
    #error "hal_conf.h: CONF_HAL_SCREEN_WIDTH is missing"
#endif


#ifdef CONF_HAL_SCREEN_HEIGHT
    #define HAL_SCREEN_HEIGHT CONF_HAL_SCREEN_HEIGHT
#else
    #error "hal_conf.h: CONF_HAL_SCREEN_HEIGHT is missing"
#endif