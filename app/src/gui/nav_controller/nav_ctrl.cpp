/**
 * @file nav_ctrl.cpp
 * @brief Controls navigation UI
 * @author Tanguy Roudaut
 * @date 27/11/2024
 */

#include "nav_ctrl.h"
#include "log.h"

NavCtrl::NavCtrl(ScreensManager* screensManager)
	: _screensManager(screensManager) {

	_currentScreen = 0;

	if (_screensManager->screenAvailability(ScreenName::DATA_SCREEN_TEMPERATURE))
		_screensMap.emplace(_screensManager->getScreenPos(ScreenName::DATA_SCREEN_TEMPERATURE),
						    ScreenName::DATA_SCREEN_TEMPERATURE);

	if (_screensManager->screenAvailability(ScreenName::DATA_SCREEN_HUMIDITY))
		_screensMap.emplace(_screensManager->getScreenPos(ScreenName::DATA_SCREEN_HUMIDITY),
							ScreenName::DATA_SCREEN_HUMIDITY);

	if (_screensManager->screenAvailability(ScreenName::DATA_SCREEN_PRESSURE))
		_screensMap.emplace(_screensManager->getScreenPos(ScreenName::DATA_SCREEN_PRESSURE),
							ScreenName::DATA_SCREEN_PRESSURE);

	if (_screensManager->screenAvailability(ScreenName::DATA_SCREEN_AIR_QUALITY))
		_screensMap.emplace(_screensManager->getScreenPos(ScreenName::DATA_SCREEN_AIR_QUALITY),
							ScreenName::DATA_SCREEN_AIR_QUALITY);
}

NavCtrl::~NavCtrl() {

}

void NavCtrl::next() {
	_currentScreen++;
    if (_currentScreen >= _screensMap.size())
    	_currentScreen = 0;

	_screensManager->show(_screensMap[_currentScreen]);
}

void NavCtrl::prev() {
	_currentScreen--;
    if (_currentScreen < 0)
    	_currentScreen = _screensMap.size() - 1;

    _screensManager->show(_screensMap[_currentScreen]);
}
