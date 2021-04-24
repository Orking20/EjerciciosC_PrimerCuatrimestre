/*
 ============================================================================
 Name        : SabClase3_Ej5.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Crear una función que permita cargar los datos de un jugador y otra que los muestre.
		 	   Crear la estructura Jugador (nombre, goles metidos, partidos jugados, promedio de goles).
			   Una tercera función calculará el promedio de goles.
			   Cargar los datos de 5 jugadores. Y mostrarlos por pantalla.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"
#include "utn.h"
#define CANT_JUGADORES 5

int main(void)
{
	Jugador arrayJugadores[CANT_JUGADORES];
	int opcionMenu;
	int flagPrimeraCarga = 0;

	do
	{
		utn_getNumero(&opcionMenu, "\n\n1) Cargar jugadores\n2) Mostrar jugadores\n3) Ver promedio de goles\n4) Salir\n", "\nError. Ingrese un número del menú", 1, 4, 3);

		switch(opcionMenu)
		{
			case 1:
			{
				for(int i = 0; i < CANT_JUGADORES; i++)
				{
					cargarJugador(arrayJugadores, CANT_JUGADORES, i, &flagPrimeraCarga);
				}
				break;
			}
			case 2:
			{
				if(flagPrimeraCarga)
				{
					mostrarJugadores(arrayJugadores, CANT_JUGADORES);
				}
				else
				{
					printf("\nError. Todavía no se ingresaron jugadores. Cargelos primero en la opción 1");
				}
				break;
			}
			case 3:
			{
				if(flagPrimeraCarga)
				{
					promediarGoles(arrayJugadores, CANT_JUGADORES);
				}
				else
				{
					printf("\nError. Todavía no se ingresaron jugadores. Cargelos primero en la opción 1");
				}

				break;
			}
		}
	}while(opcionMenu != 4);





	return EXIT_SUCCESS;
}
