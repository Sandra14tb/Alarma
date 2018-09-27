#include <avr/sleep.h>

//Definir pines usados 
#define ledVerde 2
#define reed 4
#define buzzer 9

//definir frecuencias para el buzzer
const int tono1 = 1000;
const int tono2 = 1250;

//Variable para almacenar el estado del reed switch
int value = 0;

void setup() {
  //Configurar entradas y salidas
  pinMode(reed, INPUT_PULLUP);
  pinMode(ledVerde, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  //Obtener el estado del reed switch
  value = digitalRead(reed);
 //si es LOW quiere decir que el iman esta cerca y HIGH al alejar el iman
  if (value == LOW) {
    digitalWrite(ledVerde, HIGH);

   //Sonido del buzzer
   tone(buzzer, tono1);
   delay(200);
   tone(buzzer, tono2);

  } else {
    digitalWrite(ledVerde,LOW);
   //Detener el sonido del buzzer
    noTone(buzzer);
  }
 
  delay(200);

}

