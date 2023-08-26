#ifndef I2CCONTROLLER_HPP
#define I2CCONTROLLER_HPP

#include <ax25.hpp>
#include <Wire.h>

//
// Meta
//
#define VERSION 0x01

//
// CMDS
//
#define CMD_PING 0x00
#define CMD_VERSION 0x01

typedef int (*WriteFunction)(const uint8_t *buffer, int size);

class I2CController {
    public:
        I2CController(AX25 *ax25, TwoWire *wire);
        void onReceive(uint8_t *buf, int len);

    private:
        AX25 *ax25;
        TwoWire *wire;

        void writeByte(uint8_t data);
};

#endif