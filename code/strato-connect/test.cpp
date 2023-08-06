// main.cpp

#include <gtest/gtest.h>
#include <iostream>
#include "AX25_test.h"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

// Build command: g++ main.cpp -lgtest