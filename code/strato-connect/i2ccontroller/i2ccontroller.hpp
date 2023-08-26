#ifndef I2CCONTROLLER_HPP
#define I2CCONTROLLER_HPP

#include <ax25.hpp>
#include <rf4463.hpp>

//
// Meta
//
#define VERSION 0x01

//
// CMDS
//
#define CMD_PING 0x00
#define CMD_VERSION 0x01

class I2CController {
    public:
        I2CController(AX25 *ax25, RF4463 *rf4463, TwoWire *wire);
        void onReceive(uint8_t *buf, int len);

    private:
        AX25 *ax25;
        TwoWire *wire;
        RF4463 *rf4463;

        void ping();
        void version();
};

#endif