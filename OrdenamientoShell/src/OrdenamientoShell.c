/*
 ============================================================================
 Name        : OrdenamientoShell.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Ordenamiento de Shell
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define LIMITE 10

void ordenacion_shell (int* array, int limite);

int main(void)
{
	int array[LIMITE] = {3, 6, 5, 8, 2, 9, 7, 1, 10, 4};

	ordenacion_shell(array, LIMITE);

	for(int i = 0; i < LIMITE; i++)
	{
		printf("%d\n", array[i]);
	}

	return EXIT_SUCCESS;
}

void ordenacion_shell(int* array, int limite)
{
	int incremento = limite / 2, i, j;
	int auxiliar;

	do
	{
		for(i = incremento + 1; i < limite; i++)
		{
			auxiliar = array[i];
			j = i - incremento;
			while((j >= 0) && (auxiliar < array[j]))
			{
				array[j + incremento] = array[j];
				j -= incremento;
			}
			array[j + incremento] = auxiliar;
		}
		incremento /= 2;
	}
	while(incremento > 0);
}
