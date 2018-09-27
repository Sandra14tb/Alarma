# Practica 2 Acceso a puerta

Sandra Luz Godínez Guerrero
Sistemas Programables 
Ingeniería en Sistemas Computacionales
27 de septiembre del 2018

# Descripción del problema a resolver
Desarrolle una alarma con arduino para el acceso a una puerta. Cuando la puerta se abra, la alarma debería sonar.
- Requisito indispensable:
Reducir el consumo de energía al mínimo. Mientras la alarma no esté sonando el arduino deberá consumir la mínima cantidad de energía.
Cuando la puerta se cierre esta deberá de dejar de sonar y regresar al estado de bajo consumo energético.

# Descripción de la solución
La practica 2 consiste en realizar la simulación del acceso a una puerta usando arduino, en este caso se uso el reed Switch para que detectara si la puerta esta cerrada o abierta esto con ayuda de un imán esto se da porque el reed switch se comporta como  un interruptor que se activa ante la presencia de un imán , en el caso de que este abierta, suena una alarma y prende el LED, si esta cerrada el LED y la alarma permanecen apagadas y el arduino  se mantiene en el consumo mínimo de energía, esta acción se realiza gracias al uso de interrupciones que nos permiten pausar lo que este realizando el arduino y cumplir con la acción que desarrolla la interrupción.
En el caso de que la puerta este abierta, en el display se mostrara el mensaje "Puerta abierta, entre "

# Materiales

- 2 Protoboard
- 1 Arduino UNO
- 1 Diodo LED
- 1 Reed switch
- 1 Buzzer
- 1 Resistencia de 220 Ohm
- Cables
- Display LCD 16x2
- Potenciometro de 10k
- 1 Imán

## Simulaciones

Diagrama  de esquema
![
](https://github.com/Sandra14tb/Alarma/blob/master/practica2_esquema.png?raw=true)
Diagrama de simulación
![
](https://github.com/Sandra14tb/Alarma/blob/master/practica2_simulado.png?raw=true)

# Imágenes de la practica Real
![enter image description here](https://github.com/Sandra14tb/Alarma/blob/master/imagen1.jpg?raw=true)
![enter image description here](https://github.com/Sandra14tb/Alarma/blob/master/imagen2.jpg?raw=true)

## Contacto
Correo: sandra_luz@live.com.mx
			sandy.goboo@gmail.com
