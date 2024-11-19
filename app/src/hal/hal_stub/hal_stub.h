#ifndef HAL_STUB_H
#define HAL_STUB_H

#include <memory>

#include "itf_hal.h"
#include "display.h"


class HalStub: public ItfHal {

public:
    HalStub();
    ~HalStub();

    void init();
    void setDisplayBrightness(int percent);

private:
    std::unique_ptr<Display> _display;

};


#endif // HAL_STUB_H
