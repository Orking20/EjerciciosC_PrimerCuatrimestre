/*
 ============================================================================
 Name        : OrdenBurbujaMejorado.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define LIMITE 5

int ordenArray(int* array, int limite);

int main(void)
{
	int array[LIMITE] = {18, 21, 5, 9, 15};

	ordenArray(array, LIMITE);

	for(int i = 0; i < LIMITE; i++)
	{
		printf("%d\n", array[i]);
	}

	return EXIT_SUCCESS;
}

int ordenArray(int* array, int limite)
{
	int retorno = -1;
	int auxiliar;
	int flagSwap = 0;

	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 0; i < limite - 1; i++)
			{
				if(array[i] > array[i + 1])
				{
					auxiliar = array[i];
					array[i] = array[i + 1];
					array[i + 1] = auxiliar;
					flagSwap = 1;
				}
			}
		}while(flagSwap);
		retorno = 0;
	}

	return retorno;
}
