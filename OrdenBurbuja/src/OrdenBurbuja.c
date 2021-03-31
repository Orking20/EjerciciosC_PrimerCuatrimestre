/*
 ============================================================================
 Name        : OrdenBurbuja.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Ordenamiento burbuja
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define LIMITE 9

int main(void)
{
	int array[LIMITE] = {16, 8, 13, 15, 19, 9, 2, 4, 11};
	int auxiliar;

	for(int i = 0; i < LIMITE; i++)
	{
		for(int j = 0; j < LIMITE - i - 1; j++)
		{
			if(array[j] > array[j + 1])
			{
				auxiliar = array[j];
				array[j] = array[j + 1];
				array[j + 1] = auxiliar;
			}
		}
	}

	for(int i = 0; i < LIMITE; i++)
	{
		printf("%d\n", array[i]);
	}

	return EXIT_SUCCESS;
}
