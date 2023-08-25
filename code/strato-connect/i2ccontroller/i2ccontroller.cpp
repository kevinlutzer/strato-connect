#include "i2ccontroller.hpp"

I2CController::I2CController(AX25 *ax25, RF4463 *rf4463) {
    this->ax25 = ax25;
    this->rf4463 = rf4463;
}  

void I2CController::onWrite(WriteFunction writeFunc) {
    this->writeFunc = writeFunc;
}

void I2CController::onReceive(uint8_t *buf, int len) {
    return;
}

void I2CController::ping() {
    uint8_t buf[1];
    buf[0] = 0x01;
    this->writeFunc(buf, sizeof(buf));
}


