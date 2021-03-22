/*
 ============================================================================
 Name        : CalculadoraSimple.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Pedir un número, después un operador y por último otro número.
 	 	 	   Según la operación asignada se llamará a una función.
 	 	 	   Mostrar al usuario el resultado.
 	 	 	   En la función dividir, validar divisiones por 0.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a;
	int b;
	int c;

	printf("Dirección de la variable a: %p\n", &a);
	printf("Dirección de la variable b: %p\n", &b);
	printf("Dirección de la variable c: %p\n", &c);
	return EXIT_SUCCESS;
}
