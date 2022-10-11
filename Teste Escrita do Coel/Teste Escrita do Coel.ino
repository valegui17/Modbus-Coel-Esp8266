#include <ModbusMaster.h>

ModbusMaster node;

float Temp_PR1 = 3;
float Setpoint = 5;
word setpoint = 5.00;
float Compressor = 0;
float Porta = 0;


void setup() {
  Serial.begin(9600);
  node.begin(1, Serial);

}

void loop() {

  static uint32_t i;
  uint8_t j, result;
  uint16_t data[6];
  
  // set word 1 of TX buffer to most-significant word of counter (bits 31..16)
  node.setTransmitBuffer(0x2803, 0x5);
  Serial.println(node.setTransmitBuffer(0x2803, 0x5));
  delay(1000);
  
  // slave: write TX buffer to (2) 16-bit registers starting at register 0
  result = node.writeSingleRegister(0x2803, 0x5);
  Serial.println(result);
  delay(5000);
}