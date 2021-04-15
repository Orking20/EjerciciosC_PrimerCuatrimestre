/*
 ============================================================================
 Name        : SabClase3_Ej2.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Realizar un programa que permita el ingreso de 10 números enteros distintos
 	 	 	   de cero. La carga deberá ser aleatoria (todos los elementos se inicializarán en
 	 	 	   cero por default. Determinar el promedio de los positivos, y del menor de los
 	 	 	   negativos la suma de los antecesores. Utilizar funciones y vectores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define TAM_ARRAY 10

int main(void)
{
	int array[TAM_ARRAY];
	float promedio;
	int sumaAntecesores;

	for(int i = 0; i < TAM_ARRAY; i++)
	{
		array[i] = 0;
	}

	for(int i = 0; i < TAM_ARRAY; i++)
	{
		utn_getNumero(&array[i], "Ingrese un número entero: \n", "Error. Debe ingresar un número entero distinto de 0\n", -32768, 32767, 5);
		while(array[i] == 0)
		{
			printf("Error. Debe ingresar un número entero distinto de 0\n");
			utn_getNumero(&array[i], "Ingrese un número entero: \n", "Hubo un error con los parámetros\n", -32768, 32767, 5);
		}
	}

	promediarPositivos(array, TAM_ARRAY, &promedio);
	sumaAntesecores(array, TAM_ARRAY, &sumaAntecesores);
	printf("El promedio de los positivos es: %.2f\n", promedio);
	printf("La suma de los antecesores del número mínimo de los negativos es: %d", sumaAntecesores);

	return EXIT_SUCCESS;
}
