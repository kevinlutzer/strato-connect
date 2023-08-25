#ifndef I2CCONTROLLER_HPP
#define I2CCONTROLLER_HPP

#include "ax25.hpp"
#include "rf4463.hpp"

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
        I2CController(AX25 *ax25, RF4463 *rf4463);
        void onReceive(uint8_t *buf, int len);
        void onWrite(WriteFunction writeFunc);

    private:
        AX25 *ax25;
        RF4463 *rf4463;
        WriteFunction writeFunc;

        void ping();
};

#endif