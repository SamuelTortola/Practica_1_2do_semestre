
#include "jugadores.h"

int servicio_activo =  0, ganajugador1 = 0, ganajugador2 = 0;


void activacion(uint8_t activo){   //Activar o desactivar el juego
	if (activo == 1)
	{
		servicio_activo = 1;  //Permitir a los jugadores jugar
	}
	
	else{
		servicio_activo = 0;   //No permitir a los jugadores jugar
	}
}



void jugador1(uint8_t presionado){
	if (presionado == 1 && servicio_activo == 1)
	{
		
		PORTC = PORTC + 1;
		if (PORTC >= 15)
		{
			PORTD = 0x06;
			PORTC = 15;
		}
	}
}

void jugador2(uint8_t presionado){
	if (presionado == 1 && servicio_activo == 1)
	{
		if (PORTC >= 15)
		{
			PORTD = 0x06;
			PORTC = 15;
		}
		
		PORTC = PORTC + 1;
	}
	
}