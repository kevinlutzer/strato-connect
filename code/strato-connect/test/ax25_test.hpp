#include <gtest/gtest.h>
#include <iostream>
#include "../ax25/ax25.hpp"

using namespace std;

namespace {
  // Tests the default c'tor.
  // TEST(AX25, applyCallsign) {
  //   AX25 ax25;


  //   uint8_t frame[14]; 

  //   // Apply regular callsign with 6 alpha numerica characters with an ssid of 0
  //   char *callsign = "V3WA52"; // random callsign
  //   uint8_t ssid = 0x01;
  //   ax25.applyCallsign(frame, 0, callsign, ssid);

  //   // Make sure we add 
  //   for (int i = 0; i < 6; i++) {
  //     EXPECT_EQ(frame[i], (uint8_t)callsign[i]);
  //   }
  //   EXPECT_EQ(frame[6], ssid);

  //   callsign = "bec---";
  //   ssid = 0xFF;
  //   ax25.applyCallsign(frame, 7, callsign, ssid);

  //   // Make sure we add 
  //   for (int i = 7; i < 13; i++) {
  //     EXPECT_EQ(frame[i], (uint8_t)callsign[i]);
  //   }
  //   EXPECT_EQ(frame[13], ssid);
  // }

  // TEST(AX25, encode_returns_invalid_for_null_data) {
  //   AX25 ax25;

  //   char *callsign = "V3WA52"; // random callsign
  //   uint8_t ssid = 0x01;

  //   uint8_t *frame; 
  //   uint16_t frame_len = ax25.encode(frame, callsign, callsign, NULL);

  //   EXPECT_EQ(frame_len, 0);
  // }

  // TEST(AX25, encode_returns_zero_for_data_length_zero) {
  //   AX25 ax25;

  //   char *callsign = "V3WA52"; // random callsign
  //   uint8_t *frame;
  //   uint16_t frame_len = ax25.encode(frame, callsign, callsign, "");

  //   EXPECT_EQ(frame_len, 0);
  // }



  TEST(AX25, encode_returns_frame_with_encoded_data) {
    AX25 ax25;

    // Check i

    // Apply regular callsign with 6 alpha numerica characters with an ssid of 0
    char *scallsign = "V3WA52"; // random callsign
    char *dcallsign = "BEC"; // random callsign

    uint8_t *frame1, *frame2; 
    uint16_t frame1_len, frame2_len;
    frame2_len = ax25.encode2(frame2, dcallsign, scallsign, "HELLO WORLD");
    frame1_len = ax25.encode(frame1, dcallsign, scallsign, "HELLO WORLD");

    for (int i = 0; i < frame1_len; i++) {
      bitset<sizeof(frame1[i]) * 8> binary1(frame1[i]);
      // bitset<sizeof(frame2[i]) * 8> binary2(frame2[i]);
      
      // std::cout << "Index: " << i << " " << binary1 << " " << binary2 << std::endl;
      std::cout << "Index: " << i << " " << binary1 << std::endl;
    }

    // Length is the length of the header + the length of  "HELLO WORLD"
    EXPECT_EQ(frame1_len, 23);
  }
}  // namespace