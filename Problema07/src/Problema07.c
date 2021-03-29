/*
 ============================================================================
 Name        : Problema07.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Crear una función que reciba como parámetro un numero entero.
 	 	 	   La función retornara 1 en caso de que sea positivo, -1 en caso
 	 	 	   de que sea negativo y 0 en caso de que sea 0. Realizar la prueba
 	 	 	   lógica de la función en el main.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int averiguarEntero(int numero);

int main(void)
{
	int numero = 3;

	printf("%d", averiguarEntero(numero));

	return EXIT_SUCCESS;
}

int averiguarEntero(int numero)
{
	int retorno;

	if(numero > 0)
	{
		retorno = 1;
	}
	else if(numero < 0)
	{
		retorno = -1;
	}
	else
	{
		retorno = 0;
	}

	return retorno;
}
