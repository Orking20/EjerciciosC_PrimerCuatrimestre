/*
 ============================================================================
 Name        : Recursividad.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int factorial(int);

int main(void)
{
	int valor,result;

	printf("\nIngrese numero: ");
	scanf("%d", &valor);
	result = factorial(valor);
	printf("\nEl factorial de %d es %d", valor, result);

	return EXIT_SUCCESS;
}

int factorial(int n)
{
	int resp;
	if(n == 1)
		return 1;
	resp = n * factorial(n - 1);
	return (resp);
}
