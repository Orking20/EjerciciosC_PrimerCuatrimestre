/*
 ============================================================================
 Name        : MaximoMinimo.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Pedir 5 números y dar como resultado el máximo y el mínimo
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int numeroIngresado;
	int maximo;
	int minimo;

	for(int i = 0; i < 5; i++)
	{
		printf("\nIngrese un número: ");
		scanf("%d", &numeroIngresado);

		if(i == 0)
		{
			minimo = numeroIngresado;
			maximo = numeroIngresado;
		}
		else
		{
			if(numeroIngresado < minimo)
			{
				minimo = numeroIngresado;
			}
			if(numeroIngresado > maximo)
			{
				maximo = numeroIngresado;
			}
		}
	}
	printf("\nEl número mínimo es: %d", minimo);
	printf("\nEl número máximo es: %d", maximo);

	return EXIT_SUCCESS;
}
