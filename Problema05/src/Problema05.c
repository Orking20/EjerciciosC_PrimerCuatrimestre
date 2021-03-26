/*
 ============================================================================
 Name        : Problema05.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Diseñar en un programa que permita ingresar 10 números, ninguno
 	 	 	   de ellos igual a cero. Se pide sumar los positivos, obtener el
 	 	 	   producto de los negativos y luego mostrar ambos resultados
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int numeroIngresado;
	int sumaPositivos;
	int productoNegativos;

	sumaPositivos = 0;
	productoNegativos = 1;

	for(int i = 0; i < 10; i++)
	{
		printf("Ingrese un número: ");
		scanf("%d", &numeroIngresado);
		while(numeroIngresado == 0)
		{
			printf("No puede ingresar 0. Ingrese otro número");
			scanf("%d", &numeroIngresado);
		}
		if(numeroIngresado > 0)
		{
			sumaPositivos += numeroIngresado;
		}
		else
		{
			productoNegativos *= numeroIngresado;
		}
	}

	printf("Suma de números positivos: %d\nProducto de los negativos: %d", sumaPositivos, productoNegativos);

	return EXIT_SUCCESS;
}
