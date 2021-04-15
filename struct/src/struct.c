/*
 ============================================================================
 Name        : struct.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Persona.h"

#define CANT_PERSONAS 5

int main(void)
{
	Persona arrayPersonas[CANT_PERSONAS];
	Persona pesoMax;
	Persona alturaMax;

	cargaDatosPersona(arrayPersonas, CANT_PERSONAS, 0, "Mario", "Perez", 62, 1.52);
	cargaDatosPersona(arrayPersonas, CANT_PERSONAS, 1, "Sebastian", "Gomez", 74.3, 1.64);
	cargaDatosPersona(arrayPersonas, CANT_PERSONAS, 2, "María", "Luchetti", 70.2, 1.72);
	cargaDatosPersona(arrayPersonas, CANT_PERSONAS, 3, "Marta", "Capalbo", 89, 1.60);
	cargaDatosPersona(arrayPersonas, CANT_PERSONAS, 4, "Lautaro", "Martinez", 86, 1.69);

	for(int i = 0; i < CANT_PERSONAS; i++)
	{
		if(i == 0 || arrayPersonas[i].peso > pesoMax.peso)
		{
			pesoMax = arrayPersonas[i];
		}
		if(i == 0 || arrayPersonas[i].altura > alturaMax.altura)
		{
			alturaMax = arrayPersonas[i];
		}
	}

	printf("\nEstadísticas de la persona con mayor peso:");
	printf("\nNombre: %s - Apellido: %s - Peso: %.2f - Altura: %.2f\n", pesoMax.nombre, pesoMax.apellido, pesoMax.peso, pesoMax.altura);
	printf("\nEstadísticas de la persona con mayor altura:");
	printf("\nNombre: %s - Apellido: %s - Peso: %.2f - Altura: %.2f\n", alturaMax.nombre, alturaMax.apellido, alturaMax.peso, alturaMax.altura);

	return EXIT_SUCCESS;
}
