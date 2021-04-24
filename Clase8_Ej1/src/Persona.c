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
#include "utn.h"
#define TAM_NOMBRE 100

int inicializarPersonas(Persona* pArray, int limite)
{
	int retorno = -1;

	if(pArray != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			strncpy(pArray[i].nombre, "", sizeof(pArray[i].nombre));
			strncpy(pArray[i].apellido, "", sizeof(pArray[i].apellido));
			pArray[i].legajo = 0;
			pArray[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

int cargarPersonas(Persona* pPersona, int limite, int indice)
{
	int retorno = -1;
	Persona bufferPersona;
	char nombre[TAM_NOMBRE];
	char apellido[TAM_NOMBRE];
	int legajo;
	int legajoExistente = 0;

	if(pPersona != NULL && limite > 0 && indice >= 0)
	{
		if(utn_getNombre(nombre, TAM_NOMBRE, "Ingrese el nombre: \n", "Error. Ese nombre no es válido\n") == 0)
		{
			if(utn_getNombre(apellido, TAM_NOMBRE, "Ingrese el apellido: \n", "Error. Ese apellido no es válido\n") == 0)
			{
				if(utn_getNumero(&legajo, "Ingrese el legajo: \n", "Error. Ese legajo no es válido", 1, 1000, 5) == 0)
				{
					for(int i = 0; i < limite; i++)
					{
						if(legajo == pPersona[i].legajo)
						{
							printf("Error. Ese legajo ya existe.\n");
							legajoExistente = 1;
						}
					}
					if(legajoExistente == 0)
					{
						strncpy(bufferPersona.nombre, nombre, sizeof(bufferPersona.nombre));
						strncpy(bufferPersona.apellido, apellido, sizeof(bufferPersona.apellido));
						bufferPersona.legajo = legajo;
						bufferPersona.isEmpty = 0;

						pPersona[indice] = bufferPersona;
						retorno =0;
					}
				}
			}
		}
	}

	return retorno;
}

int eliminarPersonas(Persona* pPersona, int limite)
{
	int retorno = -1;
	int legajo;
	Persona bufferPersona;

	if(pPersona != NULL && limite > 0)
	{
		utn_getNumero(&legajo, "Ingrese el legajo de la persona que desea eliminar: \n", "Error. Ese legajo no es válido\n", 1, 1000, 3);

		for(int i = 0; i < limite; i++)
		{
			if(legajo == pPersona[i].legajo)
			{
				strncpy(bufferPersona.apellido, "", sizeof(bufferPersona.apellido));
				strncpy(bufferPersona.nombre, "", sizeof(bufferPersona.nombre));
				bufferPersona.legajo = 0;
				bufferPersona.isEmpty = 1;

				pPersona[i] = bufferPersona;
				printf("Eliminado exitosamente\n");
				retorno = 0;
			}
		}
	}

	return retorno;
}

int mostrarPersonas(Persona* pPersona, int limite)
{
	int retorno = -1;

	if(pPersona != NULL && limite > 0)
	{
		for(int i = limite; i >= 0; i--)
		{
			if(pPersona[i].isEmpty == 0)
			{
				printf("Nombre: %s - Apellido: %s - Legajo: %d\n", pPersona[i].nombre, pPersona[i].apellido, pPersona[i].legajo);
			}
		}
		retorno = 0;
	}

	return retorno;
}

int ordenarPersonas(Persona* pArray, int limite)
{
	int retorno = -1;
	char auxApellido[100];
	char auxNombre[100];
	int auxLegajo;
	int auxIsEmpty;
	int flagSwap = 0;

	if(pArray != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 0; i < limite - 1; i++)
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

					auxIsEmpty = pArray[i].isEmpty;
					pArray[i].isEmpty = pArray[i + 1].isEmpty;
					pArray[i + 1].isEmpty = auxIsEmpty;

					flagSwap = 1;
				}
			}
		}while(flagSwap);
		retorno = 0;
	}

	return retorno;
}

/**
 * \brief Busca en el array el primer indice vacío
 * \param Producto* pProducto: Cadena que va a ser analizada
 * \param int limite: Limite o tamaño de la cadena
 * \return Retorna el primer indice vacío o -1 en caso de error o si ya está lleno el array*/
int buscarIndiceVacio(Persona* pProducto, int limite)
{
	int respuesta = -1;

	if(pProducto != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pProducto[i].isEmpty)
			{
				respuesta = i;
				break;
			}
		}
	}

	return respuesta;
}
