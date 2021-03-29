/*
 ============================================================================
 Name        : Arrays3.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Ordenar los elementos de una lista de menor a mayor y mostrarlos
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN 9

int main(void)
{
	int array[ARRAY_LEN] = {16, 8, 13, 15, 19, 9, 2, 4, 11};
	int auxiliar;

	for(int i = 0; i < ARRAY_LEN; i++)
	{
		for(int j = i + 1; j < ARRAY_LEN; j++)
		{
			if(array[i] > array[j])
			{
				auxiliar = array[i];
				array[i] = array[j];
				array[j] = auxiliar;
			}
		}
	}

	for(int i = 0; i < ARRAY_LEN; i++)
	{
		printf("%d\n", array[i]);
	}

	return EXIT_SUCCESS;
}
