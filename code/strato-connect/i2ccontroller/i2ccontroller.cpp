#include "i2ccontroller.hpp"
#include <Wire.h>

I2CController::I2CController(AX25 *ax25, TwoWire *wire) {
    this->ax25 = ax25;
    // this->rf4463 = rf4463;
    this->wire = wire;
}

void I2CController::onReceive(uint8_t *buf, int len) {
    if(len < 1) {
        return; 
    }

    switch(buf[0]) {
        case CMD_PING:
            this->ping();
            break;
        case CMD_VERSION:
            this->version();
            break;
        default:
            break;
    }
}

void I2CController::ping() {
    this->wire->write(0x01);
}

void I2CController::version() {
    this->wire->write(VERSION);
}

