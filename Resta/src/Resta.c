/*
 ============================================================================
 Name        : Resta2.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Clase 01 - Ejercicio 03
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int a;
	int b;
	int resultado;

	printf("\nIngrese un número: ");
	scanf("%d", &a);
	printf("\nIngrese un número: ");
	scanf("%d", &b);
	resultado = a - b;

	printf("\n______________________________________\n");
	printf("\nEl resultado de la resta es: %d \n", resultado);
	if(resultado > 0)
	{
		printf("\nResultado positivo \n");
	}
	if(resultado < 0)
	{
		printf("\nResultado negativo \n");
	}
	printf("______________________________\n\n\n\n");

	return EXIT_SUCCESS;
}
