/*
 ============================================================================
 Name        : For4.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Escribir en y codificar en C un programa que muestre los
 	 	 	   múltiplos de 6 comprendidos entre 0 y 100
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	for(int i = 0; i <= 100; i += 6)
	{
		printf("%d\n", i);
	}

	return EXIT_SUCCESS;
}
