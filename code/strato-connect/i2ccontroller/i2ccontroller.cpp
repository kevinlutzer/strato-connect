#include "i2ccontroller.hpp"
#include <Wire.h>

using namespace std;

I2CController::I2CController(AX25 *ax25, TwoWire *wire) {
    this->ax25 = ax25;
    this->twoWire = wire;
}  

void I2CController::onReceive(uint8_t *buf, int len) {
    if (len == 0) {
        return;
    }

    switch (buf[0]) {
        case CMD_PING:
            this->twoWire->write(VAL_PONG);
            return;
        case CMD_VERSION:
            this->twoWire->write(VAL_VERSION);
            return;
        case CMD_SET_PROPERTY:
            // cout << "Set Property" << endl;
            this->setProperty(buf, len);
        case CMD_GET_PROPERTY:
            if (len < 1) {
                return;
            }
            this->getProperty(buf[0]);
    }

    return;
}

void I2CController::setCallsign(uint8_t *buf, int len) {
    // callsign is a minimum of 1 byte

    char scallsign[len - 1];
    for (uint8_t i = 2; i < len; i++) {
        scallsign[i] = buf[i];
    }

    this->sourceCallsign = scallsign;
    this->sourceCallsignLen = len - 1;

    return;
}

void I2CController::setProperty(uint8_t *buf, int len) {
    // callsign is a max of 6 bytes
    if (len < 3) {
        return;
    }

    uint8_t addr = buf[1]; 
    switch (addr) {
        case ADDR_SOURCE_CALLSIGN:
            this->setCallsign(buf, len);
            return;
    }
}

void I2CController::getProperty(uint8_t addr) {
    switch (addr) {
        case ADDR_SOURCE_CALLSIGN:
            this->twoWire->write((uint8_t)'C');
            return;
    }

    return;
}