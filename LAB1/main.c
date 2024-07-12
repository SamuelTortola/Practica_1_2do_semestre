//******************************************************************************
// Universidad Del Valle De Guatemala
// IE2023: Electrónica digital 2
// Autor: Samuel Tortola - 22094
// Proyecto: Laboratorio 1
// Hardware: Atmega238p
// Creado: 11/07/2024
//Última modificación: 11/07/2024
//******************************************************************************


#define F_CPU 16000000
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "regresivo/regresivo.h"
#include "jugadores/jugadores.h"

void setup(void);
	
	
void setup(void){
	DDRB = 0b00111100;   //PB0, PB1 como entrada, PB2 a PB5 como salida
	DDRD = 0b01111111;  //Salida hacia LEDs de display
	DDRC = 0b0001111;  //Salida LEDs jugador 1
	PORTB = 0b00000011;		//pull up encendido en PB0 y PB1
	PORTD = 0b10000000;   //Iniciamos los leds apagados y pull up en PD7
	PORTC = 0b0000000;   //Iniciar LEDs de jugador 1 apagados
	
	UCSR0B = 0;  //Usar los pines TX y RX como digitales
	
	PCMSK0 |= (1 << 0)|(1 << 1); //PCINT0, PCINT1
	PCMSK2 |= (1 << 7); //PCINT23
	PCICR |= (1 << 0) | (1 << 1); //Mascara de interrupción
	
	sei(); //Activar interrupciones
	PORTD = 0x6D;
	activacion(0);
}	
	
	
int main(void)
{
	setup();
	
    while (1) 
    {
		
    }
}

ISR(PCINT0_vect){
	
	
	if(((PINB) & (1<<0)) == 0){   //Condicional que compara si se presionó el pulsador  de start
		_delay_ms(20);  //antirrebote
		PORTC = 0; //Borrar datos de jugadas anteriores
		conteo_regresivo(activa);
		
		
		while ((PINB & (1 << PINB0)) == 0)   //While para evitar sumas indebidas
		{
			_delay_ms(30);    
		}
		
	}
	
	if(((PINB) & (1<<1)) == 0){   //Condicional que compara si se presionó el pulsador  de start
		_delay_ms(20);  //antirrebote
		jugador1(cont1);
		
		while ((PINB & (1 << PINB1)) == 0)   //While para evitar sumas indebidas
		{
			_delay_ms(30);
		}
		
	}
}




	
	

	