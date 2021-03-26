/*
 ============================================================================
 Name        : If.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Hacer el programa que nos permita introducir un número por
 	 	 	   teclado y nos informe si es positivo o negativo
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int numeroIngresado;

	printf("Ingrese un número: ");
	scanf("%d", &numeroIngresado);

	if(numeroIngresado > 0)
	{
		printf("Numero positivo");
	}
	else if(numeroIngresado < 0)
	{
		printf("Numero negativo");
	}

	return EXIT_SUCCESS;
}
