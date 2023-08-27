#include "i2ccontroller.hpp"
#include <Wire.h>
#include <iostream>

using namespace std;

I2CController::I2CController(AX25 *ax25, TwoWire *wire) {
    this->ax25 = ax25;
    this->twoWire = wire;
}  

void I2CController::onReceive(uint8_t *buf, int len) {
    if (len == 0) {
        return;
    }

    cout << "onReceive: " << (int)buf[0] << endl;

    switch (buf[0]) {
        case CMD_PING:
            this->twoWire->write(VAL_PONG);
            return;
        case CMD_VERSION:
            this->twoWire->write(VAL_VERSION);
            return;
        case CMD_SET_PROPERTY:
            cout << "Set Property" << endl;
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

    cout << "Set Callsign" << endl;
    char scallsign[len - 1];
    for (uint8_t i = 2; i < len; i++) {
        scallsign[i] = buf[i];
    }

    this->sourceCallsign = scallsign;
    this->sourceCallsignLen = len - 1;

    cout << "Set Callsign " << scallsign <<  endl;

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
            cout << "ADDR " << len << endl;
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