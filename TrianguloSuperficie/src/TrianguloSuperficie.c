/*
 ============================================================================
 Name        : TrianguloSuperficie.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Diseñar un programa que calcule la superficie de un triángulo
 	 	 	   a partir del ingreso de su base y altura y muestre el resultado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int base;
	int altura;
	int superficie;

	printf("Ingrese la base: ");
	scanf("%d", &base);
	printf("Ingrese la altura: ");
	scanf("%d", &altura);

	superficie = (base * altura) / 2;
	printf("La superficie del triangulo es: %d", superficie);

	return EXIT_SUCCESS;
}
