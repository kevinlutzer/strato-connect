#include "i2ccontroller.hpp"
#include <iostream>
#include <Wire.h>

using namespace std;

I2CController::I2CController(AX25 *ax25, TwoWire *wire) {
    this->ax25 = ax25;
    this->wire = wire;
}  

void I2CController::onReceive(uint8_t *buf, int len) {
    if (len == 0) {
        return;
    }

    uint8_t cmd = buf[0];
    switch (cmd) {
        case CMD_PING:
            this->writeByte(0x01);
            break;
        case CMD_VERSION:
            this->writeByte(VERSION);
            break;
        default:
            break;
    }
}

void I2CController::writeByte(uint8_t data) {
    cout << "HELLO WORLD2" << endl;
    uint8_t buf[1];
    buf[0] = data;
    this->wire->write(buf, 1);
}
