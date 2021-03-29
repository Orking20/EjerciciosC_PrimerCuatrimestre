/*
 ============================================================================
 Name        : Arrays.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Pedirle al usuario 5 edades y luego imprimirlas. Definir un
 	 	 	   array de 5 posiciones y usar la funcion utn_getNumero() para
 	 	 	   pedir los valores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define EDADES_LEN 5

int main(void)
{
	int edades[EDADES_LEN];

	for(int i = 0; i < EDADES_LEN; i++)
	{
		utn_getNumero(&edades[i], "Ingrese la edad: ", "Error\n", 3, 1, 80);
	}

	for(int i = 0; i < EDADES_LEN; i++)
	{
		printf("Edad %d: %d\n", i + 1, edades[i]);
	}

	return EXIT_SUCCESS;
}
