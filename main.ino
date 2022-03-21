#include <OneWire.h>

#include <DallasTemperature.h>

#include "led.h"
#include "bomba.h"


//Sensor de temperatura
#define sensor_temperatura 7
OneWire oneWire(sensor_temperatura);
DallasTemperature sensors(&oneWire);
DeviceAddress sensor1;


//Ponteiros
led *ledf; 
led *ledp; 


bomba *bomba_fluxo;
bomba *bomba_alimentacao;

//boia
int boia_vertical = 6;
int boia_horizontal = 8;

void setup() 
{

  Serial.begin(9600);
  //Objeto led
  ledf = new led(2);
  ledp = new led(3);
  
  pinMode(ledf->porta(), OUTPUT);   
  pinMode(ledp->porta(), OUTPUT);
  Serial.print("Porta Led de funcionamento: ");
  Serial.println(ledf->porta());
  Serial.println("Porta Led de parada: ");
  Serial.println(ledp->porta());

  //Objeto bomba
  bomba_alimentacao = new bomba(4);
  bomba_fluxo = new bomba(5);
  pinMode(bomba_alimentacao->porta(),OUTPUT);
  pinMode(bomba_fluxo->porta(),OUTPUT);
  Serial.print("Porta da bomba de alimentacão: ");
  Serial.println(bomba_alimentacao->porta());
  Serial.print("Porta da bomba de fluxo: ");
  Serial.println(bomba_fluxo->porta());

  //Objeto boia
  pinMode(boia_vertical, INPUT);
  pinMode(boia_horizontal, INPUT);
  //Sensor de temperatura
  sensors.begin();
}

void loop() 
{

  //Solicita os dados da boia
  int estado1 = digitalRead(boia_vertical);
  int estado2 = digitalRead(boia_horizontal);

  //Solicita a temperatura
  sensors.requestTemperatures();
  float tempC = sensors.getTempC(sensor1);
  Serial.print("Temperatura no fluxo de agua: ");
  Serial.println(sensors.getTempCByIndex(0)); 
  
  //Bomba de alimentacao do galão condicionado ao estado da boia 0 para vazio 1 para cheio
  if (estado1 == HIGH);
  {
    bomba_alimentacao->ligar();
    bomba_alimentacao->desligar();

  }
  //Bomba de fluxo condicionado ao estado da boia verticial 1 para vazio 0 para cheio 
  if (estado2 == HIGH)
  {

    bomba_fluxo ->desligar();
    bomba_alimentacao ->desligar();
    ledp->acender();
    while (estado2 == HIGH)
    {
      Serial.println("Mal funcionamento");
    }
  }  
  else 
  {
  bomba_fluxo -> ligar();
  ledf->acender();
  }
  
}
