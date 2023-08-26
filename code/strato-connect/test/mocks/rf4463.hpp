#include <stdlib.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class RF4463 {
    virtual bool txPacket(uint8_t* sendbuf,uint8_t sendLen);
};

class MockRF4463 : public RF4463 {
    MOCK_METHOD(bool, txPacket, (uint8_t* sendbuf,uint8_t sendLen), (override));
};