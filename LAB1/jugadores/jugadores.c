
#include "jugadores.h"

int servicio_activo =  0, ganajugador1 = 0, ganajugador2 = 0, contador2 = 0, contador1 = 0, ganador = 0;


void activacion(uint8_t activo){   //Activar o desactivar el juego
	if (activo == 1)
	{
		servicio_activo = 1;  //Permitir a los jugadores jugar
	}
	
	else{
		servicio_activo = 0;   //No permitir a los jugadores jugar
	}
}

void reseteo_juego(uint8_t reset){
	if (reset == 1)
	{
		contador1 = 0;
		contador2 =	0;
		ganador = 0;
	}
	
}


void jugador1(uint8_t presionado){
	if (presionado == 1 && servicio_activo == 1 && ganador == 0)
	{
		contador1 ++;
		switch (contador1){
			case 1:
				PORTC = 0b0000001;
				break;
			case 2:
				PORTC = 0b0000010;
				break;
			case 3:
				PORTC = 0b0000100;
				break;
				
			case 4:
			PORTC = 0b0001111;
			PORTD = 0x06;
			contador1 = 4;
			ganador = 1;
			break;
		
	}
}
}

void jugador2(uint8_t presionado){
	if (presionado == 1 && servicio_activo == 1 && ganador == 0)
	{
			contador2 ++;
			switch (contador2){
				case 1:
					PORTD |= (1<<7);
					break;
				
				case 2:
					PORTB = 0b0001111;
					PORTD = 0b00111111;
					break;
				
				case 3:
					PORTB = 0b0010111;
					
					break;
					
				case 4:
					PORTB = 0b0111111;
					PORTD = 0x5B;
					PORTD |= (1<<7);
					contador2 = 4;
					ganador = 1;
					break;
					
				}
	}
	
}