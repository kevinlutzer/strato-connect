#include "rf4463.hpp"
#include "ax25.hpp"
#include <SPI.h>
#include <Wire.h>

#define IRQ 2
#define SDN 9
#define SEL 10
#define SCL 19

AX25 ax25 = AX25();
RF4463 rf4463 = RF4463(IRQ, SDN, SEL);
unsigned char tx_buf[]={"NEW HELLO WORLD!!!"};
unsigned char val;
unsigned char flag=0;    //  flag of rx mode
unsigned char rx_len;
unsigned char rx_buf[20];

void setup() {
  Serial.begin(9600);

  if(!rf4463.init())
    Serial.println("Init fail!");
  else
    Serial.println("Init success!");

  if(!rf4463.setTxPower(127))
    Serial.println("Failed to set power to max!");
}

void loop() {
  rf4463.txPacket(tx_buf,sizeof(tx_buf));
  delay(1000);
}
