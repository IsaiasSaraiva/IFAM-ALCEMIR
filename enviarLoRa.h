#ifndef ENVIARLORA_H
#define ENVIARLORA_H

#include <LoRa.h>
#include <SPI.h>

// Declaração da função para enviar dados via LoRa
void EnviarLora(uint8_t moistureValue, int tempInt, int counter);

#endif
