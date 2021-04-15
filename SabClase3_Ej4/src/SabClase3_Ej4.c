/*
 ============================================================================
 Name        : SabClase3_Ej4.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Pedirle al usuario su nombre y apellido (en variables separadas,
			   una para el nombre y otra para el apellido). Ninguna de las dos
			   variables se puede modificar.
			   Debemos lograr guardar en una tercer variable el apellido y el nombre con el
			   siguiente formato:
			   Por ejemplo: 
			   Si el nombre es juan ignacio y el apellido es gOmEz, la salida debería ser:
			   Gomez, Juan Ignacio
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LETRAS 64

int main(void)
{
	char nombre[MAX_LETRAS];
	char apellido[MAX_LETRAS];
	char nombreCompleto[2][MAX_LETRAS];

	printf("Ingrese su nombre: ");
	fgets(nombre, MAX_LETRAS, stdin);
	if(nombre[strlen(nombre) - 1] == '\n')
	{
		nombre[strlen(nombre) - 1] = '\0';
	}
	printf("Ingrese su apellido: ");
	fgets(apellido, MAX_LETRAS, stdin);
	if(apellido[strlen(apellido) - 1] == '\n')
	{
		apellido[strlen(apellido) - 1] = '\0';
	}

	for(int i = 0; i < MAX_LETRAS; i++)
	{
		if(i == 0)
		{
			nombre[i] = toupper(nombre[i]);
			apellido[i] = toupper(apellido[i]);
		}
		else if(nombre[i] == ' ')
		{
			nombre[i + 1] = toupper(nombre[i + 1]);
		}
		else if(apellido[i] == ' ')
		{
			apellido[i + 1] = toupper(apellido[i + 1]);
		}
		else if(nombre[i - 1] == ' ' || apellido[i - 1] == ' ')
		{
			nombre[i] = toupper(nombre[i]);
			apellido[i] = toupper(apellido[i]);
		}
		else
		{
			nombre[i] = tolower(nombre[i]);
			apellido[i] = tolower(apellido[i]);
		}
	}

	strncpy(nombreCompleto[0], apellido, MAX_LETRAS);
	strncpy(nombreCompleto[1], nombre, MAX_LETRAS);

	for(int i = 0; i < 2; i++)
	{
		printf("%s ", nombreCompleto[i]);
	}

	return EXIT_SUCCESS;
}
