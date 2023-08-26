#include <gtest/gtest.h>
#include <iostream>
#include <ax25.hpp>

using namespace std;

namespace {

  TEST(AX25, encode) {
    AX25 ax25;

    // Apply regular callsign with 6 alpha numerica characters with an ssid of 0
    char *scallsign = "V3WA52"; // random callsign
    char *dcallsign = "BEC"; // random callsign
    char *data = "Hello World";

    uint8_t *frame; 
    uint16_t frame_len = ax25.encode(&frame, dcallsign, scallsign, data);

    // Length is the length of the header + the length of  "HELLO WORLD"
    EXPECT_EQ(frame_len, 11);
    EXPECT_EQ(*frame, *data);
  }
}  // namespace
