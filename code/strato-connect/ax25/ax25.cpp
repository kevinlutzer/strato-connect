#include "ax25.hpp"

#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
// #include <iostream>

void AX25::applyCallsign(uint8_t *frame, uint16_t index, char *callsign, uint8_t ssid) {
  // short circuit if nullptr 
  if (callsign == nullptr) {
    return;
  }

  uint16_t callsign_len = strlen(callsign);  
  for (uint16_t i = index; i < (AX25_CALLSIGN_LEN + index); i ++) {
    frame[i] = (uint8_t)' '; // add the space character as described in the AX.25 protocol if there is no data
    if (callsign[i] && callsign[i] != '-' && callsign[i] != '\0' && (callsign_len + AX25_CALLSIGN_LEN >= (i + 1))) {
      frame[i] = (uint8_t)callsign[i];
    }
  }

  // append ssid to the end of the callsign group
  // the ssid represents the id of a specific device that
  // shares the same callsign as other devices. By default it 
  // is ascii 0.
  frame[index + AX25_CALLSIGN_LEN - 1] = ssid;
}

//   uint8_t *s = (uint8_t *)calloc(6, sizeof(uint8_t));
//   char ssid;
//   char i;

//   for (i = 0; i < 6; i++)
//     {
//       if (*callsign && *callsign != '-')
//         {
//           *(s++) = *(callsign++) << 1;
//         }
//       else
//         {
//           *(s++) = ' ' << 1;
//         }
//     }

//   if (*callsign == '-')
//     {
//       ssid = atoi(callsign + 1);
//     }
//   else
//     {
//       ssid = 0;
//     }

//   *(s++) = ('0' + ssid) << 1;
// }

/* This function is taken from avr-libc */
uint16_t AX25::crcCcittUpdate(uint16_t crc, uint8_t data)
{
  data ^= crc & 0xFF;
  data ^= data << 4;

  return ((((uint16_t)data << 8) | (crc >> 8)) ^ (uint8_t)(data >> 4) ^ ((uint16_t)data << 3));
}

uint16_t AX25::encode(uint8_t* frame, char* dcallsign, char* data) {
  // short circuit if there is data, no point in encoding a frame with no data.
  // if (data == NULL) {
  //   return 0;
  // }

  // short circuit if the data length is zero
  uint16_t data_len = strlen(data);
  // if(data_len == 0) {
  //   return 0;
  // }

  // grab substring if the data_len is greater then the max length a frame will allow for.
  // if (data_len > AX25_MAX_LEN) {
  //   data_len = AX25_MAX_LEN;
  // }

  uint16_t frame_len = data_len + (uint16_t)(AX25_FCS_LEN + AX25_PID_LEN + AX25_CONTROL_LEN + AX25_ADDRESS_LEN + 2 * AX25_FLAG_LEN);

  // allocate frame to just contain the callsign
  frame = (uint8_t*)calloc(frame_len, sizeof(uint8_t));
  for(uint16_t i = 0; i < frame_len; i++) {
    frame[i] = 0;
  }
  // if (frame == NULL) {
  //     return 0; // Exit with an error code
  // }

  // add frame flags
  // frame[0] = AX25_FLAG;
  // frame[frame_len - 1] = AX25_FLAG;

  // add the callsigns
  // applyCallsign(frame, 1, dcallsign, 0);
  // applyCallsign(frame, 1 + AX25_CALLSIGN_LEN, this->scallsign, 0);

  // frame[14] = AX25_CONTROL_APRS;
  // frame[15] = AX25_PID;

  return frame_len;
}

// int AX25::buildIFrame(uint8_t* s, const char* scallsign, const char* dcallsign, const char* data)
// {
//   // uint8_t frame[AX25_MAX_LEN + 1];
//   // uint16_t x;
//   // va_list va;

//   // va_start(va, data);

//   // /* Write in the callsigns and paths */
//   // s = applyCallsign(frame, dcallsign);
//   // s = applyCallsign(s, scallsign);

//   // /* Mark the end of the callsigns */
//   // s[-1] |= 1;

//   // *(s++) = AX25_CONTROL_APRS; 
//   // *(s++) = AX25_PID;

//   // /* The maximum message length is AX25_MAX_LEN - callsigns - CRC */
//   // /* 1 is added to allow room for vsnprintf's \0 at the end */
//   // vsnprintf((char*)s, AX25_MAX_LEN - (s - frame) - 2 + 1, data, va);
//   // va_end(va);

//   // /* Calculate and append the checksum */
//   // for (x = 0xFFFF, s = frame; *s; s++) {
//   //   x = crcCcittUpdate(x, *s);
//   // }

//   // *(s++) = ~(x & 0xFF);
//   // *(s++) = ~((x >> 8) & 0xFF);

//   // return sizeof(*s);
//   return 0;
// }
