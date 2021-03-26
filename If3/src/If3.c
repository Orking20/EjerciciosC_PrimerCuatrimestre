/*
 ============================================================================
 Name        : If3.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : De 3 números ingresados desde el teclado por el usuario, indicar cuál es el mayor
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int numeroIngresado;
	int mayor;

	for(int i = 0; i < 3; i++)
	{
		printf("Ingrese un número: ");
		scanf("%d", &numeroIngresado);

		if(i == 0 || numeroIngresado > mayor)
		{
			mayor = numeroIngresado;
		}
	}

	printf("Número mayor: %d", mayor);

	return EXIT_SUCCESS;
}
