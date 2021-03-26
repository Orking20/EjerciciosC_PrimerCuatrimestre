/*
 ============================================================================
 Name        : Impares.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Escribir en C un programa que muestre los números impares
 	 	 	   entre 0 y 100 y que imprima cuantos impares hay
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	for(int i = 0; i <= 100; i++)
	{
		if(i % 2 != 0)
		{
			printf("%d\n", i);
		}
	}

	return EXIT_SUCCESS;
}
