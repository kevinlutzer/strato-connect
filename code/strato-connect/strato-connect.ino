#include <RF4463.h>
#include <SPI.h>
#include <Wire.h>

#define IRQ 2
#define SDN 9
#define SEL 10

#define SCL 19

RF4463 rf4463 = RF4463(IRQ, SDN, SEL);
unsigned char tx_buf[]={"NEW HELLO WORLD!!!"};
unsigned char val;
unsigned char flag=0;    //  flag of rx mode
unsigned char rx_len;
unsigned char rx_buf[20];
uint8_t count = 0;

void setup() {
  pinMode(SCL, OUTPUT);
  digitalWrite(SCL,LOW);
  Serial.begin(9600);

  if(!rf4463.init())
    Serial.println("Init fail!");
  else
    Serial.println("Init success!");


  if(!rf4463.setTxPower(127))
    Serial.println("Failed to set power to max!");
}

void loop() {
  digitalWrite(SCL,HIGH);
  rf4463.txPacket(tx_buf,sizeof(tx_buf));

  Serial.println("tx ");
  Serial.print(count, DEC);
  Serial.println("\n");
  count += 1;

  digitalWrite(SCL,LOW);

  delay(1000);
}
