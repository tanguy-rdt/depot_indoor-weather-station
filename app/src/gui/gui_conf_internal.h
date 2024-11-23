#ifndef GUI_CONF_INTERNAL_H
#ifdef __has_include
    #if __has_include("gui_conf.h")
        #include "gui_conf.h"
    #else
        #error "gui_conf.h is missing"
    #endif
#endif
#endif  /*GUI_CONF_INTERNAL_H*/


#ifdef CONF_GUI_SCREEN_WIDTH
    #define GUI_SCREEN_WIDTH CONF_GUI_SCREEN_WIDTH
#else
    #error "gui_conf.h: CONF_GUI_SCREEN_WIDTH is missing"
#endif


#ifdef CONF_GUI_SCREEN_HEIGHT
    #define GUI_SCREEN_HEIGHT CONF_GUI_SCREEN_HEIGHT
#else
    #error "gui_conf.h: CONF_GUI_SCREEN_HEIGHT is missing"
#endif