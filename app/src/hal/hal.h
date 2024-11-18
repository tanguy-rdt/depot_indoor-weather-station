#ifndef HAL_H
#define HAL_H

#include <memory>

#include "itf_hal.h"

class Hal {

public:
    Hal();
    ~Hal();

    void init();

private:
    std::unique_ptr<ItfHal> _hal;

};


#endif // HAL_H
