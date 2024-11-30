/**
 * @file ScreensManager
 * @brief [Description]
 * @author Tanguy Roudaut
 * @date 30/11/2024
 */

#include "screens_manager.h"

#include <log.h>

#include "data_screen.h"

#include "gui_conf_internal.h"

namespace screens {

ScreensManager::ScreensManager(proxy::Proxy* proxy, EventManager* eventManager) {
	ItfScreens* dataScreen =  new DataScreen(proxy, eventManager);
	screenFactory(ScreenName::DATA_SCREEN_TEMPERATURE, dataScreen);
	screenFactory(ScreenName::DATA_SCREEN_HUMIDITY, dataScreen);
	screenFactory(ScreenName::DATA_SCREEN_PRESSURE, dataScreen);
	screenFactory(ScreenName::DATA_SCREEN_AIR_QUALITY, dataScreen);
}

ScreensManager::~ScreensManager() {

}

bool ScreensManager::screenAvailability(ScreenName screen) {
	auto status = screen == ScreenName::DATA_SCREEN_TEMPERATURE ? static_cast<bool>(GUI_DATA_SCREEN_TEMPERATURE_AVAILABLE) :
				  screen == ScreenName::DATA_SCREEN_HUMIDITY    ? static_cast<bool>(GUI_DATA_SCREEN_HUMIDITY_AVAILABLE)    :
				  screen == ScreenName::DATA_SCREEN_PRESSURE    ? static_cast<bool>(GUI_DATA_SCREEN_PRESSURE_AVAILABLE)    :
				  screen == ScreenName::DATA_SCREEN_AIR_QUALITY ? static_cast<bool>(GUI_DATA_SCREEN_AIR_QUALITY_AVAILABLE) : false;

	return status;
}

int ScreensManager::getScreenPos(ScreenName screen) {
	int position =
		screen == ScreenName::DATA_SCREEN_TEMPERATURE ? GUI_DATA_SCREEN_TEMPERATURE_ORDER :
		screen == ScreenName::DATA_SCREEN_HUMIDITY    ? GUI_DATA_SCREEN_HUMIDITY_ORDER    :
		screen == ScreenName::DATA_SCREEN_PRESSURE    ? GUI_DATA_SCREEN_PRESSURE_ORDER    :
		screen == ScreenName::DATA_SCREEN_AIR_QUALITY ? GUI_DATA_SCREEN_AIR_QUALITY_ORDER : -100;

	return position;
}


void ScreensManager::show(ScreenName screen) {
	_screens[screen]->show(screen);
}


void ScreensManager::screenFactory(ScreenName screen, ItfScreens* screenInstance) {
	if (screenAvailability(screen))
		_screens.emplace(screen, screenInstance);
	else
		Log::debug("ScreenManager::screenFactory -- Screen not available");
}

}