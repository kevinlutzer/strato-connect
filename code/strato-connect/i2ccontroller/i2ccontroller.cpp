#include "i2ccontroller.hpp"
#include <Wire.h>

I2CController::I2CController(AX25 *ax25, RF4463 *rf4463, TwoWire *wire) {
    this->ax25 = ax25;
    this->rf4463 = rf4463;
    this->wire = wire;
}  

void I2CController::onReceive(uint8_t *buf, int len) {
    return;
}

void I2CController::ping() {
    this->wire->write(0x01);
}


