/*
 ============================================================================
 Name        : Circunsferencia.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Diseñar un programa que calcule la longitud de la
 	 	 	   circunferencia teniendo el diámetro
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592654

int main(void)
{
	float diametro;
	float circunsferencia;

	printf("Ingrese el diámetro: ");
	scanf("%f", &diametro);

	circunsferencia = PI * diametro;

	printf("La circunsferencia: %f", circunsferencia);

	return EXIT_SUCCESS;
}
