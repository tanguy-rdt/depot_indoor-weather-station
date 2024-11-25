#include "hal.h"

#ifdef STUB
    #include "hal_stub.h"
#else 
    #error "No HAL type specified"
#endif


Hal::Hal() {
    #ifdef STUB
        _hal = std::make_unique<HalStub>();
    #endif
}

Hal::~Hal() {

}

void Hal::init() {
    _hal->init();
}

ItfSensor* Hal::getSensor(Sensors sensor) const {
    return _hal->getSensor(sensor);
}
