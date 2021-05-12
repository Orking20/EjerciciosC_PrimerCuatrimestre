/*
 ============================================================================
 Name        : MemoriaDinamica.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Practicando memoria dinámica por primera vez
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int* pArray;
	int* pArrayNuevo;
	int limite = 10;

	pArray = (int*)malloc(sizeof(int) * limite);
	if(pArray != NULL)
	{
		for(int i = 0; i < limite; i++)
		{
			printf("\nIngrese un número: ");
			scanf("%d", &pArray[i]);
		}

		for(int i = 0; i < limite; i++)
		{
			printf("\n%d", pArray[i]);
		}

		limite += 10;
		pArrayNuevo = (int*)realloc(pArray, sizeof(int) * limite);

		for(int i = 0; i < limite; i++)
		{
			printf("\n%d", pArrayNuevo[i]);
		}
	}

	return EXIT_SUCCESS;
}
