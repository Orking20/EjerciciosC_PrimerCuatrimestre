/*
 ============================================================================
 Name        : Resta2.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Escribir un programa que realice las siguientes acciones:
			   Declare 2 variables y les asigne sendos valores
			   Realice la resta de dichas variables y muestre por pantalla la
			   leyenda "Resultado positivo" en caso deser mayor que cero
			   o "Resultado negativo" si es menor que cero
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int numero1;
	int numero2;
	int resultado;

	numero1 = 6;
	numero2 = 7;

	resultado = numero1 - numero2;
	if(resultado > 0)
	{
		printf("Resultado positivo");
	}
	else if(resultado < 0)
	{
		printf("Resultado negativo");
	}

	return EXIT_SUCCESS;
}
