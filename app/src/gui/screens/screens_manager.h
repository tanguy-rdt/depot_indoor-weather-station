/**
 * @file ScreensManager
 * @brief [Description]
 * @author Tanguy Roudaut
 * @date 30/11/2024
 */

#ifndef SCREENS_MANAGER_H
#define SCREENS_MANAGER_H

#include <map>

#include "proxy/proxy.h"
#include "screens_name.h"

namespace screens {
class ItfScreens;

class ScreensManager {
	public:
		ScreensManager(proxy::Proxy* proxy, EventManager* eventManager);
		~ScreensManager();

		bool screenAvailability(ScreenName screen);
		int getScreenPos(ScreenName screen);
		void show(ScreenName screen);

	private:
		void screenFactory(ScreenName screen, ItfScreens* screenInstance);

		std::map<ScreenName, ItfScreens*> _screens;
};

}


#endif //SCREENS_MANAGER_H
