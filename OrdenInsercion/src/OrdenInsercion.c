/*
 ============================================================================
 Name        : OrdenInsercion.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Ordenamiento por inserción
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define LIMITE 8

void ordenInsercion(int* array, int limite);

int main(void)
{
	int array[LIMITE] = {5, 7, 9, 6, 3, 6, 8, 2};

	ordenInsercion(array, LIMITE);

	for(int i = 0; i < LIMITE; i++)
	{
		printf("%d\n", array[i]);
	}

	return EXIT_SUCCESS;
}

void ordenInsercion(int* array, int limite)
{
	int i, j;
	int actual;

	for (i = 1; i < limite; i++)
	{
		actual = array[i];
		for (j = i; j > 0 && array[j - 1] > actual; j--)
		{
			array[j] = array[j - 1];
		}
		array[j] = actual;
	}
}

