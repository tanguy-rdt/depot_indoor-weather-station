#ifndef GUI_H
#define GUI_H

#include "screens.h"
#include "circular_indicator.h"


namespace Widgets {
    class CircularIndicator;
}

class Gui {

public:
    Gui();
    ~Gui();

    void init();

private:
    Screens _screens;
    Widgets::CircularIndicator* ci;

};


#endif // GUI_H
