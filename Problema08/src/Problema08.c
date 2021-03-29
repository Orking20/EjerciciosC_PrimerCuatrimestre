/*
 ============================================================================
 Name        : Problema08.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Realizar un programa que permita el ingreso de 10 números enteros.
 	 	 	   Determinar el PROMEDIO de los positivos, la cantidad de ceros y del
 	 	 	   menor de los negativos LA SUMA DE LOS ANTESECORES.

 	 	 	   Nota: Utilizar la función del Problema07 y desarrollar
 	 	 	   funciones para resolver los procesos que están en mayúsculas.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main(void)
{
	int numeroIngresado;
	int sumaPositivos;
	int cantPositivos;
	int cantCeros;
	int menorNegativo;

	sumaPositivos = 0;
	cantPositivos = 0;
	cantCeros = 0;

	for(int i = 0; i < 10; i++)
	{
		printf("Ingrese un número entero: ");
		scanf("%d", &numeroIngresado);

		if(numeroIngresado > 0)
		{
			sumaPositivos += numeroIngresado;
			cantPositivos++;
		}
		else if(averiguarEntero(numeroIngresado) == 0)
		{
			cantCeros++;
		}
		else
		{
			if(i == 0 || numeroIngresado < menorNegativo)
			{
				menorNegativo = numeroIngresado;
			}
		}
	}



	printf("Promedio de positivos: %d\n", promedio(sumaPositivos, cantPositivos));
	printf("Cantidad de ceros: %d\n", cantCeros);
	printf("La suma de los antecesores del menor de los negativos: %d\n", sumaAntecesores(menorNegativo));


	return EXIT_SUCCESS;
}
