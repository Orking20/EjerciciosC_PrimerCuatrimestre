/*
 ============================================================================
 Name        : Clase7_Ej5.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : a) Realizar un programa que le pida 5 números int al usuario y los almacene en un array.
 	 	 	   Luego ejecutar la función borrarImpares() pasandole el array y que deberá reemplazar los
 	 	 	   números que son impares por un 0.
 	 	 	   b) Luego imprimir el array para chequear el funcionamiento.
 	 	 	   c) Ordenar el array de menor a mayor y volver a imprimirlo.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define CANT_ARRAY 5

int main(void)
{
	int array[CANT_ARRAY];

	for(int i = 0; i < CANT_ARRAY; i++)
	{
		utn_getNumero(&array[i], "Ingrese un número: \n", "Error. Solo se pueden ingresar números entre 1 y 1000\n", 1, 1000, 3);
	}

	borrarImpares(array, CANT_ARRAY);

	printf("Cadena desordenada de números pares:\n");
	for(int i = 0; i < CANT_ARRAY; i++)
	{
		printf("%d\n", array[i]);
	}

	ordenSeleccion(array, CANT_ARRAY);

	printf("Cadena ordenada de números pares:\n");
	for(int i = 0; i < CANT_ARRAY; i++)
	{
		printf("%d\n", array[i]);
	}

	return EXIT_SUCCESS;
}
