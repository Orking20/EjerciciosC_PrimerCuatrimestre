/*
 ============================================================================
 Name        : SabClase3_Ej1.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Pedir el ingreso de 10 números enteros entre -1000 y 1000. Determinar:
 	 	 	   a. Cantidad de positivos y negativos.
 	 	 	   b. Sumatoria de los pares.
 	 	 	   c. El mayor de los impares.
 	 	 	   d. Listado de los números ingresados.
 	 	 	   e. Listado de los números pares.
 	 	 	   f. Listado de los números de las posiciones impares.  
 	 	 	   Se deberán utilizar funciones y vectores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define TAM_ARRAY 10

int main(void)
{
	int numerosIngresados[TAM_ARRAY];
	int numerosNegativos;
	int numerosPositivos;
	int sumaPares;
	int imparMaximo;

	for(int i = 0; i < TAM_ARRAY; i++)
	{
		utn_getNumero(&numerosIngresados[i], "\nIngrese un número entre -1000 y 1000: ", "Error. Ingrese un núero entre -1000 y 1000", -1000, 1000, 3);
	}

	ContarPositivos(numerosIngresados, TAM_ARRAY, &numerosPositivos);
	ContarNegativos(numerosIngresados, TAM_ARRAY, &numerosNegativos);
	SumarPares(numerosIngresados, TAM_ARRAY, &sumaPares);
	RetornarMayorImpar(numerosIngresados, TAM_ARRAY, &imparMaximo);

	printf("\nCantidad de negativos: %d\n", numerosNegativos);
	printf("Cantidad de positivos: %d\n", numerosPositivos);
	printf("Suma de los pares: %d\n", sumaPares);
	printf("El mayor de los impares: %d\n", imparMaximo);
	printf("Listado de los números ingresados\n");
	for(int i = 0; i < TAM_ARRAY; i++)
	{
		printf("%d\n", numerosIngresados[i]);
	}

	MostrarTodosLosNumerosPares(numerosIngresados, TAM_ARRAY);
	MostrarNumerosPosicionesImpares(numerosIngresados, TAM_ARRAY);

	return EXIT_SUCCESS;
}

