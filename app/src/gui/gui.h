#ifndef GUI_H
#define GUI_H

#include "screens/data_screen/data_screen.h"

namespace gui {

class Gui {

    public:
        Gui();
        ~Gui();

        void init();

    private:
        DataScreen* _dataScreen;
};

} // gui

#endif // GUI_H
