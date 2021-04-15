/*
 ============================================================================
 Name        : fgetsValidar.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Crear una función para validar números en un array
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validarQueSeaNumero(char* texto);

int main(void)
{
	char texto[11];
	int saldoDelBanco = 1;

	fgets(texto, 11, stdin);
	if(texto[strlen(texto) - 1] == '\n')
	{
		texto[strlen(texto) - 1] = '\0';
	}

	printf("%s", texto);

	// validar que sean todos los caracteres numericos (del 0 al 9)
	if(validarQueSeaNumero(texto) == 1)
	{
		saldoDelBanco = atoi(texto);
	}

	printf("\nTenes %d pesos", saldoDelBanco);

	return EXIT_SUCCESS;
}

int validarQueSeaNumero(char* texto)
{
	int retorno = -1;

	if(texto != NULL)
	{
		for(int i = 0; texto[i] != '\0'; i++)
		{
			retorno = 1;

			if(texto[i] < '0' || texto[i] > '9')
			{
				retorno = -1;
				break;
			}
		}
	}

	return retorno;
}


