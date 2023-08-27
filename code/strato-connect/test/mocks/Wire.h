#ifndef WIRE_H
#define WIRE_H

#include <stdlib.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

class TwoWire {
    public:
        TwoWire() {};
        virtual ~TwoWire() = default;
        virtual size_t write(const uint8_t *, int) { return 0; };
        virtual size_t write(const uint8_t) { return 0; };
        virtual void onReceive( void (*)(int len) ) {};
        virtual uint8_t read() { return 0; };
};

class MockTwoWire: public TwoWire {
    public:
        MOCK_METHOD(size_t, write, (const uint8_t *, int), (override));
        MOCK_METHOD(size_t, write, (const uint8_t), (override));
        MOCK_METHOD(void, onReceive, (void (*)(int len)), (override));
        MOCK_METHOD(uint8_t, read, (), (override));
};

#endif