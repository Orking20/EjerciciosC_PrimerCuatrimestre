/*
 ============================================================================
 Name        : OrdenArray.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

#define LIMITE 5

int main(void)
{
	int array[LIMITE] = {15, 18, 9, 21, 5};
	int minimo;

	ordenArray(array, LIMITE, &minimo);

	for(int i = 0; i < LIMITE; i++)
	{
		printf("%d\n", array[i]);
	}

	return EXIT_SUCCESS;
}
