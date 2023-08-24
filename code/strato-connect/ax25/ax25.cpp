#include "ax25.hpp"

#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

uint16_t AX25::crcCcittUpdate(uint16_t crc, uint8_t data) {
  return 0;
}

uint8_t* AX25::applyCallsign(uint8_t* s, char* callsign) {
  return NULL;
}

uint16_t AX25::encode(uint8_t** buf, char* scallsign, char* dcallsign, char* data, ...) {
  int data_len = strlen(data);
  if (!data_len) {
    return 0;
  }

  *buf = (uint8_t *)malloc(data_len * sizeof(uint8_t));
  // couldn't allocate memory
  if (!(*buf)) {
    return 0;
  }

  memcpy(*buf, data, data_len);
  return data_len;
}
