/**
 * @file Mouse
 * @brief [Description]
 * @author Tanguy Roudaut
 * @date 30/11/2024
 */

#ifndef MOUSE_H
#define MOUSE_H

#include "lvgl.h"

class Mouse {
	public:
		Mouse();
		~Mouse();

	private:
		lv_indev_drv_t _mouseDrv;
		lv_indev_t* _mouse;
};



#endif //MOUSE_H
