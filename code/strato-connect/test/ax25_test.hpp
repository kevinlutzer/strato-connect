#ifndef AX25_TEST_HPP
#define AX25_TEST_HPP

#include <gtest/gtest.h>
#include <iostream>
#include "../ax25/ax25.hpp"

using namespace std;

namespace ax25test {

  // TEST(AX25, encode) {
  //   AX25 ax25;

  //   // Apply regular callsign with 6 alpha numerica characters with an ssid of 0
  //   char *scallsign = "V3WA52"; // random callsign
  //   char *dcallsign = "BEC"; // random callsign
  //   char *data = "Hello World";

  //   uint8_t *frame; 
  //   uint16_t frame_len = ax25.encode(&frame, dcallsign, scallsign, data);

  //   for (int i = 0; i < frame_len; i++) {    
  //     cout << "Index: " << i << " " << frame[i] << endl;
  //   }

  //   // Length is the length of the header + the length of  "HELLO WORLD"
  //   EXPECT_EQ(frame_len, 10);
  //   EXPECT_EQ(*frame, *data);
  // }
} // namespace

#endif