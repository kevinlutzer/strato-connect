#ifndef AX25_TEST_HPP
#define AX25_TEST_HPP

#include <gtest/gtest.h>
#include <iostream>
#include "../ax25/ax25.hpp"

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

    for (int i = 0; i < frame_len; i++) {    
      cout << "Index: " << i << " " << frame[i] << endl;
    }

    // the length of "HELLO WORLD" plust the null terminator
    EXPECT_EQ(frame_len, 11);
    EXPECT_EQ(*frame, *data);
  }
} // namespace

#endif