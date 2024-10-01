#include "LeituraSensor.h"
#include "enviarLoRa.h"
#include "configuracao.h"  // Novo arquivo para configurações

void setup() {
  // Inicializar Monitor Serial
  Serial.begin(115200);
  
  // Configurações LoRa e sensor movidas para funções específicas
  InicializarSensor();    // Inicializar sensor de temperatura e umidade
  InicializarLoRa();      // Inicializar o módulo LoRa
}

void loop() {
  // Variáveis locais para armazenar leituras de sensores
  int sensorValue;
  float temperatureC;
  
  // Ler sensores
  LerSensor(sensorPin, sensors, sensorValue, temperatureC);

  // Converter valores
  uint8_t moistureValue = map(sensorValue, 0, 1023, 0, 255);
  int tempInt = int(temperatureC * 100);

  // Enviar dados via LoRa
  EnviarLora(moistureValue, tempInt, counter);

  // Incrementar o contador de pacotes
  counter++;

  // Aguardar 1 segundo antes de enviar novamente
  delay(1000);
}
