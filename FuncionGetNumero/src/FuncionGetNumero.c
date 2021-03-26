/*
 ============================================================================
 Name        : FuncionGetNumero.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Hacer una función que pida un número
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "utn.h"

int main(void)
{
	int numero;
	float altura;
	char letra;

	if(utn_getNumero(&numero, "\nIngrese la edad: ", "\nError\n", 3, 0, 100) == 0)
	{
		printf("\nIngresaste %d\n", numero);
	}

	if(utn_getFloat(&altura, "\nIngrese su altura: ", "\nError\n", 3, 1.00, 2.80) == 0)
	{
		printf("\nIngresaste %0.2f\n", altura);
	}

	if(utn_getChar(&letra, "\nIngrese un caracter: ", "\nError\n", 3, 'd', 'o') == 0)
	{
		printf("\nIngresaste %c\n", letra);
	}


	return EXIT_SUCCESS;
}
