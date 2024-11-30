#ifndef GUI_H
#define GUI_H

#include "proxy/proxy.h"
#include "event_manager/event_manager.h"
#include "nav_controller/nav_ctrl.h"
#include "screens/screens_manager.h"

using namespace proxy;

namespace gui {
using namespace screens;

class Gui {

    public:
        Gui(Proxy* proxy, EventManager* eventManager);
        ~Gui();

        void init();

    private:

        NavCtrl* _navCtrl;
        EventManager* _eventManager;
        Proxy* _proxy;
        ScreensManager* _screensManager;
};

} // gui

#endif // GUI_H
