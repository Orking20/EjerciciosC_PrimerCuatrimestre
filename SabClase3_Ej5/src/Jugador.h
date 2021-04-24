/*
 * Jugador.h
 *
 *  Created on: 17 abr. 2021
 *      Author: mateo
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

typedef struct
{
	char nombre[64];
	int golesMetidos;
	int partidosJugados;
	float promedioGoles;
}Jugador;

int cargarJugador(Jugador* pJugadores, int limite, int indice, int* pFlagPrimeraCarga);
int mostrarJugadores(Jugador* pJugadores, int limite);
int promediarGoles(Jugador* pJugadores, int limite);

#endif /* JUGADOR_H_ */
