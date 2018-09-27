//Alarma para el acceso a una puerta 
//Sandra Luz Godinez Guerrero
//Sistemas Programables

#include <avr/sleep.h>
#include <LiquidCrystal.h>

//Crear el objeto LCD con los números correspondientes (rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

//Definir pines usados 
#define ledVerde 2
#define reed 3
#define buzzer 10

//definir frecuencias para el buzzer
const int tono1 = 1000;
const int tono2 = 1250;

//Variable para almacenar el estado del reed switch
volatile int value = HIGH;

void setup() {
  //Configurar entradas y salidas
  pinMode(reed, INPUT_PULLUP);
  pinMode(ledVerde, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);
  
  //Modo de bajo consumo.
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  //Se crea una interrupcion que reaccione al cambiar de LOW a HIGH
  attachInterrupt(digitalPinToInterrupt(reed), interrupcion, RISING); 
  Serial.begin(9600);
}

void loop() {
  //Obtener el estado del reed switch
  value = digitalRead(reed);
 //si es LOW quiere decir que el iman esta cerca y HIGH al alejar el iman
  if (value == LOW) {
    sleep_disable();
    digitalWrite(ledVerde, HIGH);
    //Mostrar mensaje en display lcd 16x2
    lcd.display();
    lcd.home();
    lcd.print(" PUERTA ABIERTA ");
    lcd.setCursor (0,1);
    lcd.print("      ENTRE     ");
  
   //Sonido del buzzer
   tone(buzzer, tono1);
   delay(200);
   tone(buzzer, tono2);

  } else {
     digitalWrite(ledVerde,LOW);//Apaga el led con la alarma; si esta linea no se comenta el led se apagara
     noTone(buzzer);
     // Turn off the display:
     lcd.noDisplay();
     sleep_enable();//inicializamos el modo bajo consumo
     sleep_mode();//ponemos el modo bajo consumo.
  }
 
  delay(200);

}

void interrupcion() {
  value = !value;
}


