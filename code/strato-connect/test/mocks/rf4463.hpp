#ifndef RF4463_HPP
#define RF4463_HPP

#include <stdlib.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

class RF4463 {
    public:
        RF4463() = default;
        virtual ~RF4463() = default;
        virtual bool txPacket(uint8_t* buf, int len);
};

class MockRF4463: public RF4463 {
    public:
        MOCK_METHOD(bool, txPacket, (uint8_t* buf, int len), (override));
        MOCK_METHOD(void, RF4463, (), ());
};

#endif