// main.cpp
#include <gtest/gtest.h>
#include <iostream>
#include "./ax25_test.hpp"
// #include "i2ccontroller_test.hpp"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
