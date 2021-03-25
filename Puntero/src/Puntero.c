/*
 ============================================================================
 Name        : Puntero.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sumar(int numeroA, int numeroB, int* punteroResultado);

int main(void)
{
	int resultado;

	if(sumar(2, 3, &resultado) == 0)
	{
		printf("Ok");
	}
	else
	{
		printf("Error");
	}



	return EXIT_SUCCESS;
}

int sumar(int numeroA, int numeroB, int* punteroResultado)
{
	*punteroResultado = numeroA + numeroB;

	return 0;
}
