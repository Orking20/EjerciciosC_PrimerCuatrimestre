/*
 ============================================================================
 Name        : Problema06.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Ingresar un número entero por consola y efectuar la suma de
 	 	 	   todos los números que le anteceden, comenzando desde 0 y
 	 	 	   mostrar el resultado por pantalla
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int numeroIngresado;
	int sumaAntecedentes;

	sumaAntecedentes = 0;

	printf("Ingrese un número: ");
	scanf("%d", &numeroIngresado);

	for(int i = numeroIngresado - 1; i > 0; i--)
	{
		sumaAntecedentes += i;
	}

	printf("Suma de los número antecedentes: %d", sumaAntecedentes);

	return EXIT_SUCCESS;
}
