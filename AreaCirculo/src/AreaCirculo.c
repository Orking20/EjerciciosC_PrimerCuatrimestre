/*
 ============================================================================
 Name        : AreaCirculo.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Clase 03 - Ejercicio 01
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265359

float pedirNumero(void);
float area(float radio, float* pArea);

int main(void)
{
	float radio;
	float varArea;

	radio = pedirNumero();
	area(radio, &varArea);

	printf("Area del círculo: %lf", varArea);

	return EXIT_SUCCESS;
}

float pedirNumero(void)
{
	float respuesta;

	printf("Ingrese un número: ");
	scanf("%f", &respuesta);

	return respuesta;
}

float area(float radio, float* pArea)
{
	*pArea = PI * (radio * radio);
	return 0;
}
