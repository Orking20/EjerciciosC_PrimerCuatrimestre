/*
 ============================================================================
 Name        : PromedioFor.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Ingresar 5 números y calcular su media
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout, NULL);

	int numeroIngresado;
	int acumulador = 0;
	int contador = 0;
	float promedio;

	for(int i = 0; i < 5; i++)
	{
		printf("Ingrese un número: ");
		scanf("%d", &numeroIngresado);

		acumulador += numeroIngresado;
		contador++;
	}

	promedio = (float)acumulador / contador;
	printf("El promedio de los 5 números es: %0.2f", promedio);

	return EXIT_SUCCESS;
}
