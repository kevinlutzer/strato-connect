#include "i2ccontroller.hpp"
#include <Wire.h>

I2CController::I2CController(AX25 *ax25, TwoWire *wire) {
    this->ax25 = ax25;
    this->wire = wire;
}  

void I2CController::onReceive(uint8_t *buf, int len) {
    return;
}

void I2CController::ping() {
    uint8_t buf[1];
    buf[0] = 0x01;
    this->wire->write(buf, 1);
}


