#include "hal_stub.h"

#include <pthread.h>
#include <unistd.h>

#include "lvgl.h"


static pthread_t THR_TICK;
static bool END_TICK;

static void* tick_thread(void *data) {
  (void)data;

  while(!END_TICK) {
    usleep(5000);
    lv_tick_inc(5);
  }

  return NULL;
}


HalStub::HalStub() {
    _display = std::make_unique<Display>();
}

HalStub::~HalStub() {

}

void HalStub::init() {
    _display->init();

    END_TICK = false;
    pthread_create(&THR_TICK, NULL, tick_thread, NULL);
}

ItfSensor* HalStub::getSensor(Sensors sensor) {
    if (sensors::isSensorAvailable(sensor)) {
        return sensor == Sensors::BME680 ? &_bme680 :
                                           nullptr;
    }

    return nullptr;
}

void HalStub::setDisplayBrightness(int percent) {
    _display->setBacklightLevel(percent);
}