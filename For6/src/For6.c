/*
 ============================================================================
 Name        : For6.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Hacer el programa que nos permita contar los múltiplos de 3
 	 	 	   desde la unidad hasta un número que introducimos por teclado
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int numeroIngresado;

	printf("Ingrese un número: ");
	scanf("%d", &numeroIngresado);

	for(int i = 1; i <= numeroIngresado; i += 3)
	{
		printf("%d\n", i);
	}

	return EXIT_SUCCESS;
}
