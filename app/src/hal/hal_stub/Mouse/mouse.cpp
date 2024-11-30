/**
 * @file Mouse
 * @brief [Description]
 * @author Tanguy Roudaut
 * @date 30/11/2024
 */

#include "mouse.h"

#include "sdl/sdl.h"

Mouse::Mouse() {
	lv_indev_drv_init(&_mouseDrv);
	_mouseDrv.type = LV_INDEV_TYPE_POINTER;
	_mouseDrv.read_cb = sdl_mouse_read;
	_mouse = lv_indev_drv_register(&_mouseDrv);
}

Mouse::~Mouse() {

}