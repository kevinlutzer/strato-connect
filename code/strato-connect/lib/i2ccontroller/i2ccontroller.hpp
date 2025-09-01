#ifndef I2CCONTROLLER_HPP
#define I2CCONTROLLER_HPP

// #include <rf4463.hpp>
#include <ax25.hpp>
#include <Wire.h>

//
// Meta
//

#define VAL_VERSION 0x01
#define VAL_PONG 0x01

//
// CMDS
//

#define CMD_PING 0x00
#define CMD_VERSION 0x01
#define CMD_SET_PROPERTY 0x02
#define CMD_GET_PROPERTY 0x03

//
// Addresses
//

#define ADDR_ERROR 0x01 // readonly
#define ADDR_RSSI 0x02 // readonly
#define ADDR_SOURCE_CALLSIGN 0x03 // read/write

class I2CController {
    public:
        I2CController(AX25 *ax25, TwoWire *wire);
        void onReceive(uint8_t * buf, int len);

    private:

        //
        // Private methods
        //

        void setProperty(uint8_t *buf, int len);
        void getProperty(uint8_t addr);
        void setCallsign(uint8_t *buf, int len);
        void writeByte(uint8_t data);

        // 
        // Private variables
        //

        char * sourceCallsign;
        uint8_t sourceCallsignLen;

        AX25 *ax25;
        TwoWire *twoWire;
};

#endif