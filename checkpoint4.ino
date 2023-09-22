/**
 ******************************************************************************
   @file        mqtt_class.ino
   @author      Airton Toyofuku + Murilo Mansano
   @copyright   None
   @date        22.09.2023
   @version     1.0
   @brief       Arduino Sketch to send data to the Tago.io application throug
                MQTT protocol
 ******************************************************************************
*/
/* Private includes ----------------------------------------------------------*/
#include <Adafruit_TSL2561_U.h>
#include <Wire.h>
Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);
#include <ArduinoJson.h>    // Lib to format JSON Document
#include "EspMQTTClient.h"  // Lib to comunicate MQTT from ESP
#include "DHT.h";           // Lib to access the DHT sensor

/* Board Configuration--------------------------------------------------------*/
char temperatura[100];
char umidade    [100];
char luminosidade [100];
/* DHT Configuration----------------------------------------------------------*/
DHT dht (13, DHT11); // The sensor is connect under the GPIO 13
float dhtTemperature = 0;
float dhtHumidity = 0;
float luminosidadeSimulada = 0;
//MQTT and WiFi configuration
EspMQTTClient client
(
  ".",        //nome da sua rede Wi-Fi
  ".",  //senha da sua rede Wi-Fi
  ".",       //Endereço do servidor MQTT
  "Default",            //User é sempre default pois vamos usar token
  ".",// Código do Token
  "esp32",         //Nome do device
  1883                  //Porta de comunicação padrao
);
void setup()
{
  //dht.begin();
}
// This function is called once everything is connected (Wifi and MQTT)
// WARNING : YOU MUST IMPLEMENT IT IF YOU USE EspMQTTClient
void onConnectionEstablished()

{}
//loop do programa
void loop()
{
  //Getting temperature and Humidity data
  getDhtData();
  StaticJsonDocument<300> TemperaturaJson;
  TemperaturaJson["variable"] = "temperatura";
  TemperaturaJson["value"] = dhtTemperature;
  StaticJsonDocument<300> UmidadeJson;
  UmidadeJson["variable"] = "umidade";
  UmidadeJson["value"] = dhtHumidity;
  
  serializeJson(TemperaturaJson, temperatura);
  serializeJson(UmidadeJson, umidade);
  
  client.publish("temperatura", temperatura); 
  client.publish("umidade", umidade);

  //delay(5000); tirar case de errado
  //client.loop();
  
  // Simular a luminosidade aumentando de 1 em 1
  luminosidadeSimulada++;

  // Criar um objeto JSON para a luminosidade simulada
  StaticJsonDocument<300> LuminosidadeJson;
  LuminosidadeJson["variable"] = "luminosidade";
  LuminosidadeJson["value"] = luminosidadeSimulada;

  // Serializar o objeto JSON em uma string
  char luminosidadeStr[100];
  serializeJson(LuminosidadeJson, luminosidadeStr);

  // Publicar o valor de luminosidade simulada no tópico MQTT
  client.publish("luminosidade", luminosidadeStr);
  
  delay(5000);
  client.loop();
}
}
/*
   @brief Gets the Temp/Hum data
*/
void getDhtData(void) {
}