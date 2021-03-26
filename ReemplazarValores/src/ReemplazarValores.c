/*
 ============================================================================
 Name        : ReemplazarValores.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Diseñar el programa necesario para que habiéndose leído el
 	 	 	   valor de 2 variables NUM1 y NUM2 se intercambien los valores
 	 	 	   de las variables, es decir que el valor que tenía NUM1 ahora
 	 	 	   lo contenga NUM2 y viceversa
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num1 = 3;
	int num2 = 9;
	int transpaso1;
	int transpaso2;

	transpaso1 = num1;
	transpaso2 = num2;
	num1 = transpaso2;
	num2 = transpaso1;

	printf("num1: %d\nnum2: %d", num1, num2);

	return EXIT_SUCCESS;
}
