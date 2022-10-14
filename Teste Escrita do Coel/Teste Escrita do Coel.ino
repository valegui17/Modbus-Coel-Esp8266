#include <ModbusMaster.h>

ModbusMaster node;

float Temp_PR1 = 3;
float Setpoint = 5;
word setpoint = 5.00;
float Compressor = 0;
float Porta = 0;
uint8_t j, result;


void setup() {
  Serial.begin(9600);
  node.begin(1, Serial);
}

void loop() {

// ESCREVER VALOR DO SETPOINT
  result = node.writeSingleRegister(0x2803, word(30));
  Serial.println(" ");
  Serial.println("SETPOINT");
  Serial.println(result);
  delay(1000);


// RESETAR VALOR DA TEMPERATURA MAXIMA
  result = node.writeSingleRegister(0x287, word(1));
  Serial.println(" ");
  Serial.println("RESET MAXIMO HT");
  Serial.println(result);
  delay(1000);


// RESETAR VALOR DA TEMPERATURA MINIMA
  result = node.writeSingleRegister(0x286, word(1));
  Serial.println(" ");
  Serial.println("RESET MINIMO LT");
  Serial.println(result);
  delay(1000);


// ESCREVER VALOR DA HYSTERESIS DO COMPRESSOR
  result = node.writeSingleRegister(0x2811, word(6));
  Serial.println(" ");
  Serial.println("HYSTERESIS");
  Serial.println(result);
  delay(1000);


// // ALTERAR VALOR DA TEMPERATURA MAXIMA DO ALARME
//   result = node.writeSingleRegister(0x282C, word(270));
//   Serial.println(" ");
//   Serial.println("ALARME MAXIMO HT");
//   Serial.println(result);
//   delay(1000);


// // ALTERAR VALOR DA TEMPERATURA MINIMA DO ALARME
//   result = node.writeSingleRegister(0x282D, word(40));
//   Serial.println(" ");
//   Serial.println("ALARME MINIMO LT");
//   Serial.println(result);
//   delay(1000);
}