#include <gtest/gtest-message.h>
#include <iostream>
#include <i2ccontroller.hpp>
#include <Wire.h>
#include <ax25.hpp>

using namespace std;
using ::testing::AtLeast;

namespace {

  // // Test Ping
  // TEST(I2CController, on_recieve_ping) {
  //   AX25 ax25 = AX25();
  //   MockTwoWire twoWire = MockTwoWire();
  //   I2CController controller = I2CController(&ax25, &twoWire);

  //   EXPECT_CALL(twoWire, write(VAL_PONG));

  //   uint8_t buf[1];
  //   buf[0] = CMD_PING;
  //   controller.onReceive(buf, 1);
  // }

  // // Test Version
  // TEST(I2CController, on_recieve_version) {
  //   AX25 ax25 = AX25();
  //   MockTwoWire twoWire = MockTwoWire();
  //   I2CController controller = I2CController(&ax25, &twoWire);

  //   EXPECT_CALL(twoWire, write(VAL_VERSION));

  //   uint8_t buf[1];
  //   buf[0] = CMD_PING;
  //   controller.onReceive(buf, 1);
  // }

    // Test Version
  TEST(I2CController, on_recieve_property_source_callsign) {
    AX25 ax25 = AX25();
    MockTwoWire twoWire = MockTwoWire();
    I2CController controller = I2CController(&ax25, &twoWire);

    EXPECT_CALL(twoWire, write((uint8_t)'C'));

    uint8_t buf[3];
    buf[0] = CMD_SET_PROPERTY;
    buf[1] = ADDR_SOURCE_CALLSIGN;
    buf[2] = (uint8_t)'C';

    controller.onReceive(buf, 3);
  }
}  // namespace
