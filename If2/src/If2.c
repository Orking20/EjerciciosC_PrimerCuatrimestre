/*
 ============================================================================
 Name        : If2.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Hacer el programa que nos permita introducir un número por
 	 	 	   teclado y nos informe si es par o impar
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int numeroIngresado;

	printf("Ingrese un número: ");
	scanf("%d", &numeroIngresado);

	if(numeroIngresado % 2 == 0)
	{
		printf("Es par");
	}
	else
	{
		printf("Es impar");
	}

	return EXIT_SUCCESS;
}
