#ifndef CONFIGURACAO_H
#define CONFIGURACAO_H

#include <LoRa.h>
#include <SPI.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Definir pinos LoRa
#define SCK 5
#define MISO 19
#define MOSI 27
#define SS 18
#define RST 14
#define DIO0 26

// Definir pino do sensor de umidade do solo e temperatura
extern int sensorPin; 
extern const int oneWireBus;
extern OneWire oneWire;
extern DallasTemperature sensors;

// Banda de transmissão LoRa
#define BAND 915E6

// Contador de pacotes LoRa
extern int counter;

// Funções de inicialização
void InicializarSensor();
void InicializarLoRa();

#endif
