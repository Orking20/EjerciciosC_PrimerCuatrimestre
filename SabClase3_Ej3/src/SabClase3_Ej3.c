/*
 ============================================================================
 Name        : SabClase3_Ej3.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Realizar un programa que permita el ingreso de 10 números enteros
 	 	 	   (positivos y negativos). Necesito generar un listado de los números
 	 	 	   positivos de manera creciente y negativos de manera decreciente.
 	 	 	   (Como máximo 4 for)
 	 	 	   Ejemplo: Listado 1: 4, 5, 6, 10, 18, 29 Listado 2 : -1,-5,-9,-12
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define TAM_ARRAY 10

int main(void)
{
	int array[TAM_ARRAY];

	for(int i = 0; i < TAM_ARRAY; i++)
	{
		utn_getNumero(&array[i], "Ingrese un número entero: \n", "Error", -32768, 32767, 5);
	}

	ordenamientoCreciente(array, TAM_ARRAY);
	for(int i = 0; i < TAM_ARRAY; i++)
	{
		if(array[i] >= 0)
		{
			printf("%d\n", array[i]);
		}
	}

	ordenamientoDecreciente(array, TAM_ARRAY);
	for(int i = 0; i < TAM_ARRAY; i++)
	{
		if(array[i] < 0)
		{
			printf("%d\n", array[i]);
		}
	}

	return EXIT_SUCCESS;
}
