/**
 * @file nav_ctrl.h
 * @brief Controls navigation UI
 * @author Tanguy Roudaut
 * @date 27/11/2024
 */

#ifndef NAV_CTRL_H
#define NAV_CTRL_H

#include "lvgl.h"
#include "screens_manager.h"

#include <vector>

using namespace screens;

class NavCtrl {
  	public:
    	NavCtrl(ScreensManager* screensManager);
        ~NavCtrl();

		using Screen = lv_obj_t;

        void next();
        void prev();

    private:
		ScreensManager* _screensManager;

		std::map<int, ScreenName> _screensMap;
        int _currentScreen;

};



#endif //NAV_CTRL_H
