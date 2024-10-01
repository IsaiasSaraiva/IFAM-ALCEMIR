#include "configuracao.h"

// Definições das variáveis globais
int sensorPin = A0;                   // Pino para o sensor de umidade do solo
const int oneWireBus = A4;             // Pino do sensor de temperatura
OneWire oneWire(oneWireBus);           // Instância para comunicação OneWire
DallasTemperature sensors(&oneWire);   // Instância para o sensor de temperatura Dallas
int counter = 0;                       // Contador de pacotes LoRa

// Inicializa o sensor de temperatura
void InicializarSensor() {
  sensors.begin();
  Serial.println("Sensor de temperatura inicializado!");
}

// Inicializa o módulo LoRa
void InicializarLoRa() {
  Serial.println("LoRa Sender Test");

  SPI.begin(SCK, MISO, MOSI, SS);
  
  LoRa.setPins(SS, RST, DIO0);
  
  if (!LoRa.begin(BAND)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  Serial.println("LoRa Inicializado com sucesso!");
  delay(2000);
}
