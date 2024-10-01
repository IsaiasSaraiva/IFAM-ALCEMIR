#include "LeituraSensor.h"
#include <Arduino.h> 

// Função para ler o sensor de umidade e temperatura
void LerSensor(int sensorPin, DallasTemperature &sensors, int &sensorValue, float &temperatureC) {
  sensorValue = analogRead(sensorPin); 
  sensors.requestTemperatures();
  temperatureC = sensors.getTempCByIndex(0);
  
  if (temperatureC == DEVICE_DISCONNECTED_C) {
    Serial.println("Error: Could not read temperature data.");
  } else {
    Serial.print("Soil Moisture Value: ");
    Serial.println(sensorValue);
    Serial.print("Temperature (C): ");
    Serial.println(temperatureC);
  }
}
