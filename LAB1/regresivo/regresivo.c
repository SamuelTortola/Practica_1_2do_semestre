
#include "regresivo.h"


const uint8_t  lista[66] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D}; //Lista de numeros a mostrar en display

void conteo_regresivo(uint8_t activador)
{
	if(activador == 1)
	{
		reseteo_juego(1);
		PORTD = lista[5];
		_delay_ms(1000);
		PORTD = lista[4];
		_delay_ms(1000);
		PORTD = lista[3];
		_delay_ms(1000);
		PORTD = lista[2];
		_delay_ms(1000);
		PORTD = lista[1];
		_delay_ms(1000);
		PORTD = lista[0];
		activador = 0;    //Desactivar cuenta regresiva
		activacion(1);     //Activar el juego
		PORTC = 0;
		
	}
}