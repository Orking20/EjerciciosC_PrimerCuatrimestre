/*
 ============================================================================
 Name        : Clase7_Ej1.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Escribir la función calcularMayor(), la misma debe recibir dos
 	 	 	   números enteros y devolver por referencia, el numero mayor.
 	 	 	   Deberá retornar un 1 sí encontró un mayor, o un 0 si ambos
 	 	 	   números son iguales.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void)
{
	int resultado;
	int num1;
	int num2;

	// Pedir dos numeros al usuario con utn_getNumber() y guardarlos
	// en num1 y num 2
	utn_getNumber(&num1, "Ingrese el valor de num1: ", "Hubo un error", 3, -32768, 32767);
	utn_getNumber(&num2, "Ingrese el valor de num2: ", "Hubo un error", 3, -32768, 32767);

	// luego llamo a la funcion calcularMayor()
	if(calcularMayor(&resultado, num1, num2) == 0)
	{
		printf("Los numeros son iguales\n");
	}
	else
	{
		printf("El mayor es: %d\n", resultado);
	}

	return EXIT_SUCCESS;
}
