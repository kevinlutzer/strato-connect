/*
  Documentation for AX.25 protocol: https://www.tapr.org/pdf/AX25.2.2.pdf

  I frame structure used for APRS: 

  | Flag 1 Byte | Address 14 - 28 Bytes | Control 1 - 2 Bytes | PID 1 Byte | Info N Bytes | FCS 16 Bytes | Flag 1 Byte |
*/

#include <stdint.h>

//
// Part Lengths (Bits)
// 

#define AX25_FLAG_LEN 1
#define AX25_ADDRESS_LEN 14 // @todo: support 224 bits for repeater addresses
#define AX25_CONTROL_LEN 1
#define AX25_PID_LEN 1
#define AX25_FCS_LEN 2

#define AX25_HEADER_LEN = (uint16_t)(AX25_FCS_LEN + AX25_PID_LEN + AX25_CONTROL_LEN + AX25_ADDRESS_LEN + 2 * AX25_FLAG_LEN)

#define AX25_MAX_LEN (64)

// 
// Constants
// 

#define AX25_CALLSIGN_LEN 7 // Includes the ssid
#define AX25_FLAG 0x7E // Delmiter defined in Figure 3.1. Frame format.
#define AX25_PID 0xF0 // No layer 3 protocol implemented Figure 3.2. PID definitions.
#define AX25_CONTROL_APRS 0x03 // APRS-UI frame. Control Field Definitions

class AX25
{
  private:
    uint16_t crcCcittUpdate(uint16_t crc, uint8_t data);

  public:
    uint8_t* applyCallsign(uint8_t* s, char* callsign);
    uint16_t encode(uint8_t** buf, char *scallsign, char *dcallsign, char* data, ...);
};
