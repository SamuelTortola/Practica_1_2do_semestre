
#ifndef REGRESIVO_H_
#define REGRESIVO_H_

#include <avr/io.h>
#include <stdint.h>
#define F_CPU 16000000
#include <util/delay.h>

#define activa 1
#define activa_jugadores 0
 
void conteo_regresivo(uint8_t activador);



#endif 