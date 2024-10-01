#include "enviarLoRa.h"

// Função para enviar os dados via LoRa
void EnviarLora(uint8_t moistureValue, int tempInt, int counter) {
  uint8_t tempHighByte = highByte(tempInt);
  uint8_t tempLowByte = lowByte(tempInt);

  Serial.print("Sending packet: ");
  Serial.println(counter);

  LoRa.beginPacket();
  LoRa.write(moistureValue);
  LoRa.write(tempHighByte);
  LoRa.write(tempLowByte);
  LoRa.endPacket();
}
