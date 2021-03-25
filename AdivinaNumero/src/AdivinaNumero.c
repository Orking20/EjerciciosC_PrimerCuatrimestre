/*
 ============================================================================
 Name        : Biblioteca.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : 1) Desarrollar una biblioteca "utn.h" que posea funciones
 	 	 	   para pedirle al usuario el ingreso de datos
 	 	 	   2) Diseñar un programa para jugar a adivinar un número
 	 	 	   entre 0 y 100. El juego tiene que dar pistas de si el número
 	 	 	   introducido por el jugador está por encima o por debajo.
 	 	 	   El juego termina cuando se adivina el número o se decide
 	 	 	   terminar de jugar ingresando un número negativo.
 	 	 	   Permitir jugar tantas veces como lo desee el jugador
 	 	 	   y al salir mostrar su mejor puntuación.
 	 	 	   Utilizar la biblioteca del punto anterior.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <time.h>
#include "utn.h"

#define FALSE 0
#define TRUE 1

int main(void)
{
	srand(time(NULL));

	int numeroSecreto;
	int numeroIngresado;
	int victoria;
	int intentos;
	int mejorPuntaje;
	int flag;
	int pararJuego;
	char continuar;

	flag = TRUE;
	pararJuego = FALSE;

	printf("Bienvenido a 'Adivina el número'!\nObjetivo: Adivinar el número que se encuentra entre 0 y 100\nUna vez que ingreses el número el juego te avisará si el número secreto es más alto con un '+' o más bajo con un '-'\nSi deseas dejar de jugar ingrese un número negativo\n");

	do
	{
		intentos = 0;
		victoria = FALSE;
		numeroSecreto = rand() % 101;

		do
		{
			printf("\nIngrese un número del 0 al 100: ");
			getInt(&numeroIngresado);
			if(numeroIngresado < 0)
			{
				pararJuego = TRUE;
				break;
			}
			else if(numeroSecreto > numeroIngresado)
			{
				intentos++;
				printf("+\n");
			}
			else if(numeroSecreto < numeroIngresado)
			{
				intentos++;
				printf("-\n");
			}
			else
			{
				intentos++;
				victoria = TRUE;
				printf("Adivinaste!\n");
			}
		}while(victoria == FALSE);

		//Buscamos el mejor puntaje
		if(pararJuego == FALSE)
		{
			if(flag || intentos < mejorPuntaje)
			{
				mejorPuntaje = intentos;
				flag = FALSE;
			}
		}

		//Pregunto si desea seguir jugando
		printf("¿Desea seguir jugando (S/N)? ");
		getChar(&continuar);
		while(continuar != 'S' && continuar != 'N')
		{
			printf("Hubo un error. Solo puedes ingresar 'S' o 'N'\n¿Desea seguir jugando (S/N)? ");
			getChar(&continuar);
		}

	}while(continuar == 'S');

	printf("Tu mejor puntaje es de %d intentos", mejorPuntaje);

	return EXIT_SUCCESS;
}
