/*
 ============================================================================
 Name        : PromedioMaxMin.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Ingresar 5 números, mostrar el promedio, el mínimo y el máximo
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

int main(void)
{
	setbuf(stdout, NULL);

	int numeroIngresado;
	int minimo;
	int maximo;
	int flag = TRUE;
	int acumulador = 0;
	int contador = 0;
	float promedio;

	for(int i = 1; i <= 5; i++)
	{
		printf("\nIngrese el número %d: ", i);
		scanf("%d", &numeroIngresado);

		if(flag)
		{
			minimo = numeroIngresado;
			maximo = numeroIngresado;
			flag = FALSE;
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

		acumulador += numeroIngresado;
		contador++;
	}

	promedio = (float)acumulador / contador;

	printf("\nEl número mínimo es: %d", minimo);
	printf("\nEl número máximo es: %d", maximo);
	printf("\nEl promedio es: %0.2f", promedio);

	return EXIT_SUCCESS;
}
