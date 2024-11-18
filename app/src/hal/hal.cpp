#include "hal.h"

#ifdef STUB
    #include "hal_stub.h"
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