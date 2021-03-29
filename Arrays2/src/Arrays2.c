/*
 ============================================================================
 Name        : Arrays2.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Hacer una función que calcule el promedio de los valores del
 	 	 	   array que recibe y me devuelva el promedio.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN 5

int promedioArrays(int array[], int tamanoArray, float* pPromedio);

int main(void)
{
	int array[ARRAY_LEN];
	float promedio;

	for(int i = 0; i < ARRAY_LEN; i++)
	{
		printf("Ingrese un número: ");
		scanf("%d", &array[i]);
	}

	if(promedioArrays(array, ARRAY_LEN, &promedio) == 0)
	{
		printf("El promedio de las edades es: %0.2f", promedio);
	}
	else
	{
		printf("Hubo un error. Asegúrese de que el tamaño del array sea mayor a 0");
	}

	return EXIT_SUCCESS;
}

int promedioArrays(int array[], int tamanoArray, float* pPromedio)
{
	int retorno = -1;
	float acumulador = 0;

	if(array != NULL && pPromedio != NULL && tamanoArray > 0)
	{
		for(int i = 0; i < tamanoArray; i++)
		{
			acumulador += array[i];
		}
		retorno = 0;
	}

	*pPromedio = acumulador / tamanoArray;

	return retorno;
}
