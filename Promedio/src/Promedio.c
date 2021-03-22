/*
 ============================================================================
 Name        : Promedio.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Pedir N números e imprimir el promedio
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
	int continuar;

	do
	{
		printf("\nIngrese un número: ");
		scanf("%d", &numeroIngresado);

		acumulador += numeroIngresado;
		contador++;

		printf("\n¿Desea ingresar otro número? (si: 1/no: 0) ");
		scanf("%d", &continuar);
	}while(continuar != 0);

	promedio = (float)acumulador / contador;
	printf("El promedio de todos los números es: %f", promedio);

	return EXIT_SUCCESS;
}
