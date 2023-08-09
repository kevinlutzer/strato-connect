#include <gtest/gtest.h>
#include <iostream>
#include "../ax25/ax25.hpp"

namespace {
  // Tests the default c'tor.
  TEST(AX25, applyCallsign) {
    AX25 ax25;
    
    // allocate frame to just contain the callsign
    uint8_t *frame = (uint8_t*)calloc(14, sizeof(uint8_t));
    if (frame == NULL) {
      FAIL();
    }

    // Apply regular callsign with 6 alpha numerica characters with an ssid of 0
    char *callsign = "V3WA52"; // random callsign
    uint8_t ssid = 0x01;
    ax25.applyCallsign(frame, 0, callsign, ssid);

    // Make sure we add 
    for (int i = 0; i < 6; i++) {
      EXPECT_EQ(frame[i], (uint8_t)callsign[i]);
    }
    EXPECT_EQ(frame[6], ssid);

    callsign = "bec---";
    ssid = 0xFF;
    ax25.applyCallsign(frame, 7, callsign, ssid);

    // Make sure we add 
    for (int i = 7; i < 13; i++) {
      EXPECT_EQ(frame[i], (uint8_t)callsign[i]);
    }
    EXPECT_EQ(frame[13], ssid);
  }
  TEST(AX25, encode) {
    AX25 ax25;

    // Apply regular callsign with 6 alpha numerica characters with an ssid of 0
    char *callsign = "V3WA52"; // random callsign
    uint8_t ssid = 0x01;

    uint8_t *frame2; 
    uint16_t frame_len = ax25.encode(frame2, callsign, "HELLO WORLD");

    for (int i = 0; i < frame_len; i++) {
      std::bitset<sizeof(frame2[i]) * 8> binary(frame2[i]);
      std::cout << binary << std::endl;
    }

    // std::bitset<sizeof(frame) * 8> binary(frame);
    // printf("frame: %b\n", frame);

    // Length is the length of the header + the length of  "HELLO WORLD"
    EXPECT_EQ(frame_len, 31);
  }
}  // namespace