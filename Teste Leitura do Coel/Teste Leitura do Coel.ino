#include <ModbusMaster.h>

ModbusMaster node;

float Temp_PR1 = 3;
float Setpoint = 4;
float Compressor = 0;
float Porta = 0;


void setup() {
  Serial.begin(9600);
  node.begin(1, Serial);

}

void loop() {
  uint8_t result;
  word lowbyte ;
  word highbyte ;
  int16_t pr1 ;


  // TEMPERATURA 1

  result = node.readHoldingRegisters(0x200, 2);
  if (result == node.ku8MBSuccess)
  {
    lowbyte = lowByte(node.getResponseBuffer(0x00) );
    highbyte = highByte(node.getResponseBuffer(0x00) );
  
    String valores_hex = String(lowbyte, HEX) + String(highbyte, HEX);
    String stringinint = String(highbyte, HEX);
    if (stringinint.toInt() < 10) {
      valores_hex = String(lowbyte, HEX) + "0" + String(highbyte, HEX);
      if (valores_hex.length() == 4) {
        valores_hex.remove(1, 1);
      }
    }
    int x;
    char *endptr;
    x = strtol(valores_hex.c_str(), &endptr, 16);
    if (x < 0) {
      valores_hex = String(lowbyte, HEX) + String(highbyte, HEX);
      x = strtol(valores_hex.c_str(), &endptr, 16);
    }
    String number = String(x);
    Temp_PR1 = (number.toFloat() / 10);
    Serial.println(" ");
    Serial.println("Temperatura 1: ");
    Serial.println(Temp_PR1);
    Serial.println(" ");
  }
  else{
    Serial.print("nao foi");
  }
  delay(250);
  
 
 
  // SETPOINT

  result = node.readHoldingRegisters(0x2803, 2);
  if (result == node.ku8MBSuccess)
  {
    lowbyte = lowByte(node.getResponseBuffer(0x00) );
    highbyte = highByte(node.getResponseBuffer(0x00) );
  
    String valores_hex = String(lowbyte, HEX) + String(highbyte, HEX);
    String stringinint = String(highbyte, HEX);
    if (stringinint.toInt() < 10) {
      valores_hex = String(lowbyte, HEX) + "0" + String(highbyte, HEX);
      if (valores_hex.length() == 4) {
        valores_hex.remove(1, 1);
      }
    }
    int x;
    char *endptr;
    x = strtol(valores_hex.c_str(), &endptr, 16);
    if (x < 0) {
      valores_hex = String(lowbyte, HEX) + String(highbyte, HEX);
      x = strtol(valores_hex.c_str(), &endptr, 16);
    }
    String number = String(x);
    Setpoint = (number.toFloat() / 10);
    Serial.println(" ");
    Serial.println("SetPoint: ");
    Serial.println(Setpoint);
    Serial.println(" ");
  }
  else{
    Serial.print("nao foi");
  }
  delay(250);


  // PORTA

  result = node.readHoldingRegisters(0x21F, 2);
  if (result == node.ku8MBSuccess)
  {
    highbyte = highByte(node.getResponseBuffer(0x00) );
  
    Porta = highbyte;
    Serial.println(" ");
    Serial.println("Porta: ");
    Serial.println(Porta);
    Serial.println(" ");
  }
  else{
    Serial.print("nao foi");
  }
  delay(250);



  // COMPRESSOR

  result = node.readHoldingRegisters(0x210, 2);
  if (result == node.ku8MBSuccess)
  {
    highbyte = highByte(node.getResponseBuffer(0x00) );
  
    Compressor = highbyte;
    Serial.println(" ");
    Serial.println("Compressor: ");
    Serial.println(Compressor);
    Serial.println(" ");
  }
  else{
    Serial.print("nao foi");
  }
  delay(1000);
}
