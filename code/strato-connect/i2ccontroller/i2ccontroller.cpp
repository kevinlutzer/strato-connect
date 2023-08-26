#include "i2ccontroller.hpp"
#include <Wire.h>

I2CController::I2CController(AX25 *ax25, TwoWire *wire) {
    this->ax25 = ax25;
    this->wire = wire;
    // this->wire->onReceive([](int len) {
    //     uint8_t buf[len];
    //     for(int i = 0; i < len; i++) {
    //         buf[i] = this->wire->read();
    //     }
    //     this->onReceive(buf, len);
    // });
}  

void I2CController::onReceive(uint8_t *buf, int len) {
    return;
}

void I2CController::writeByte(uint8_t data) {
    uint8_t buf[1];
    buf[0] = data;
    this->wire->write(buf, 1);
}


