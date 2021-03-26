/*
 ============================================================================
 Name        : Multiplicacion.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Escribir un programa que realice las siguientes acciones
			   Asigne a 2 variables numero1 y numero2 valores distintos de cero
			   Efectúe el producto de dichas variables
			   Muestre el resultado pos pantalla
			   Obtenga el cuadrado de numero1 y lo muestre por pantalla
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int numero1;
	int numero2;
	int resultado;

	numero1 = 4;
	numero2 = 7;

	resultado = numero1 * numero2;
	printf("El producto de los dos números es: %d", resultado);
	resultado = numero1 * numero1;
	printf("\nEl cuadrado de numero1 es: %d", resultado);

	return EXIT_SUCCESS;
}
