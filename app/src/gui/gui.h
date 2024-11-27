#ifndef GUI_H
#define GUI_H

#include "screens/data_screen/data_screen.h"
#include "proxy/proxy.h"

using namespace proxy;

namespace gui {

class Gui {

    public:
        Gui(Proxy* proxy, EventManager* eventManager);
        ~Gui();

        void init();

    private:
        EventManager* _eventManager;
        Proxy* _proxy;
        DataScreen* _dataScreen;
};

} // gui

#endif // GUI_H
