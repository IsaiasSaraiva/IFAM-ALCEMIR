#ifndef LEITURASENSOR_H
#define LEITURASENSOR_H

#include <OneWire.h>
#include <DallasTemperature.h>

// Função para ler o sensor de umidade e temperatura
void LerSensor(int sensorPin, DallasTemperature &sensors, int &sensorValue, float &temperatureC);

#endif
