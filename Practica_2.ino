//Alarma para el acceso a una puerta 
//Sandra Luz Godinez Guerrero
//Sistemas Programables

#include <avr/sleep.h>

//Definir pines usados 
#define ledVerde 2
#define reed 3
#define buzzer 9

//definir frecuencias para el buzzer
const int tono1 = 1000;
const int tono2 = 1250;

//Variable para almacenar el estado del reed switch
int value = 0;
int estado = LOW;

void setup() {
  //Configurar entradas y salidas
  pinMode(reed, INPUT_PULLUP);
  pinMode(ledVerde, OUTPUT);
  pinMode(buzzer, OUTPUT);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);//Establecemos el modo de bajo consumo.
  attachInterrupt(digitalPinToInterrupt(reed), interrupcion, RISING); //Se crea una interrupcion con el pin puerta
  Serial.begin(9600);
}

void loop() {
  //Obtener el estado del reed switch
  value = digitalRead(reed);
 //si es LOW quiere decir que el iman esta cerca y HIGH al alejar el iman
  if (value == LOW) {
    sleep_disable();
    digitalWrite(ledVerde, HIGH);
  
   //Sonido del buzzer
   tone(buzzer, tono1);
   delay(200);
   tone(buzzer, tono2);

  } else {
//    digitalWrite(ledVerde,LOW);//Apaga el led con la alarma; si esta linea no se comenta el led se apagara
//     noTone(buzzer);
     sleep_enable();//inicializamos el modo bajo consumo
     sleep_mode();//ponemos el modo bajo consumo.
  }
 
  delay(200);

}

void interrupcion() {
  value = !value;//Si se irrumpe la puerta, hay un cambio de estado de cerrado a abierto y viceversa
}


