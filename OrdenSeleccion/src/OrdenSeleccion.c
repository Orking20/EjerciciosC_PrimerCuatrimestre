/*
 ============================================================================
 Name        : OrdenSeleccion.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Ordenamiento por selección
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define LEN_ARRAY 8

void ordenSeleccion(int* array, int limite);

int main(void)
{
	int array[LEN_ARRAY];

	for(int i = 0; i < LEN_ARRAY; i++)
	{
		printf("Ingrese un número: ");
		scanf("%d", &array[i]);
	}

	ordenSeleccion(array, LEN_ARRAY);

	for(int i = 0; i < LEN_ARRAY; i++)
	{
		printf("%d\n", array[i]);
	}

	return EXIT_SUCCESS;
}

void ordenSeleccion(int* array, int limite)
{
	int masChico;
	int auxiliar;

	for(int i = 0; i < limite - 1; i++)
	{
		masChico = i;
		for(int j = i + 1; j < limite; j++)
		{
			if(array[j] < array[masChico])
			{
				masChico = j;
			}
		}
		auxiliar = array[i];
		array[i] = array[masChico];
		array[masChico] = auxiliar;
	}
}
