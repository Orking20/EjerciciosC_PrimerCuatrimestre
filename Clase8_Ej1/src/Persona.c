/*
 * Persona.c
 *
 *  Created on: 14 abr. 2021
 *      Author: mateo
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "Persona.h"

int inicializarPersonas(Persona* pArray, int limite)
{
	int retorno = -1;

	if(pArray != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			pArray[i].isEmpty = 1;
			pArray[i].legajo = 0;
			strncpy(pArray[i].apellido, "", sizeof(pArray[i].apellido));
			strncpy(pArray[i].nombre, "", sizeof(pArray[i].nombre));
		}
	}

	return retorno;
}

int cargarPersonas(Persona* pPersona, int limite, int indice, char* nombre, char* apellido, int legajo)
{
	int retorno = -1;

	if(pPersona != NULL && limite > 0 && indice >= 0 && nombre != NULL && apellido != NULL)
	{
		strncpy(pPersona[indice].nombre, nombre, limite);
		strncpy(pPersona[indice].apellido, apellido, limite);
		pPersona[indice].legajo = legajo;
		pPersona[indice].indice = indice;
		pPersona[indice].isEmpty = 0;
		retorno = 0;
	}

	return retorno;
}

int mostrarPersonas(Persona* pArray, int limite)
{
	int retorno = -1;

	if(pArray != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pArray[i].isEmpty == 0)
			{
				printf("Nombre: %s - Apellido: %s - Legajo: %d\n", pArray[i].nombre, pArray[i].apellido, pArray[i].legajo);
			}
		}
	}

	return retorno;
}

int ordenarPersonas(Persona* pArray, int limite)
{
	int retorno = -1;
	char auxApellido[100];
	char auxNombre[100];
	int auxLegajo;
	int auxIndice;
	int flagSwap = 0;

	if(pArray != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 1; i < limite - 1; i++)
			{
				if(strcmp(pArray[i].apellido, pArray[i + 1].apellido) < 0)
				{
					strncpy(auxApellido, pArray[i].apellido, sizeof(auxApellido));
					strncpy(pArray[i].apellido, pArray[i + 1].apellido, sizeof(pArray[i].apellido));
					strncpy(pArray[i + 1].apellido, auxApellido, sizeof(pArray[i + 1].apellido));

					strncpy(auxNombre, pArray[i].nombre, sizeof(auxNombre));
					strncpy(pArray[i].nombre, pArray[i + 1].nombre, sizeof(pArray[i].nombre));
					strncpy(pArray[i + 1].nombre, auxNombre, sizeof(pArray[i + 1].nombre));

					auxLegajo = pArray[i].legajo;
					pArray[i].legajo = pArray[i + 1].legajo;
					pArray[i + 1].legajo = auxLegajo;

					auxIndice = pArray[i].indice;
					pArray[i].indice = pArray[i + 1].indice;
					pArray[i + 1].indice = auxIndice;
					flagSwap = 1;
				}
			}
		}while(flagSwap);
		retorno = 0;
	}

	return retorno;
}
