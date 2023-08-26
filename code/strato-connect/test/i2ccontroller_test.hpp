#include <gtest/gtest-message.h>
#include <iostream>
#include <i2ccontroller.hpp>
#include <Wire.h>
#include <ax25.hpp>

using namespace std;
using ::testing::AtLeast;

namespace {

  TEST(I2CController, main_test) {
    AX25 ax25 = AX25();
    MockTwoWire twoWire = MockTwoWire();
    I2CController controller = I2CController(&ax25, &twoWire);

    uint8_t data[1];
    data[0] = 0x01;
    EXPECT_CALL(twoWire, write(data, 1));

    twoWire.write(data, 1);

    uint8_t buf[1];
    buf[0] = CMD_PING;
    controller.onReceive(buf, 1);
  }

}  // namespace
