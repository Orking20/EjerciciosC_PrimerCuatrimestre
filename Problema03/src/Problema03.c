/*
 ============================================================================
 Name        : Problema03.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Ingresar 5 números. Determinar cuál es el máximo y
 	 	 	   el mínimo e indicar en qué orden fue ingresado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int numeroIngresado;
	int minimo;
	int maximo;
	int minimoOrden;
	int maximoOrden;

	for(int i = 0; i < 5; i++)
	{
		printf("Ingrese un número: ");
		scanf("%d", &numeroIngresado);

		if(i == 0 || numeroIngresado < minimo)
		{
			minimo = numeroIngresado;
			minimoOrden = i + 1;
		}
		if(i == 0 || numeroIngresado > maximo)
		{
			maximo = numeroIngresado;
			maximoOrden = i + 1;
		}

	}

	printf("El número mínimo es: %d\nEl número máximo es: %d\n", minimo, maximo);
	printf("Posición número mínimo: %d\n", minimoOrden);
	printf("Posición número máximo: %d\n", maximoOrden);

	return EXIT_SUCCESS;
}
