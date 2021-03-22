/*
 ============================================================================
 Name        : SumaDosNumeros.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Sumar dos números pedidos por el usuario
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout, NULL);

	int numero1;
	int numero2;
	int resultado;

	printf("Ingrese el primer número: ");
	scanf("%d", &numero1);
	printf("Ingrese el segundo número: ");
	scanf("%d", &numero2);
	resultado = numero1 + numero2;

	printf("La suma de los dos números es: %d", resultado);

	return EXIT_SUCCESS;
}
