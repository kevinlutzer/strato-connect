#include <gtest/gtest-message.h>
#include <iostream>
#include <i2ccontroller.hpp>
#include <Wire.h>
#include <ax25.hpp>

using namespace std;

namespace {

  TEST(I2CController, main_test) {
    AX25 ax25;
    TwoWire wire;
    I2CController controller = I2CController(&ax25, &wire);
  }

}  // namespace
