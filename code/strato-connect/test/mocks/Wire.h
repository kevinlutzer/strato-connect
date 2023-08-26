#ifndef WIRE_H
#define WIRE_H

#include <stdlib.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

class TwoWire {
    public:
        TwoWire() {};
        virtual ~TwoWire() = default;
        virtual size_t write(const uint8_t *, int) {return 0; };
        // virtual void onReceive( void (*)(int) ) = default;
        // virtual uint8_t read(void) = 0;
};

class MockTwoWire: public TwoWire {
    public:
        MOCK_METHOD(size_t, write, (const uint8_t *, int), (override));
        // MOCK_METHOD(void, onReceive, (void (*)(int)), (override));
        // MOCK_METHOD(void, onReceive, (void (*)(int)), (override));
        // MOCK_METHOD(void, read, (void), (override));
};

#endif