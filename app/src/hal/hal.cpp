#include "hal.h"

#ifdef STUB
    #include "hal_stub.h"
#else 
    #error "No HAL type specified"
#endif


Hal::Hal(EventManager* eventManager) {
    #ifdef STUB
        _hal = new HalStub(eventManager);
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
