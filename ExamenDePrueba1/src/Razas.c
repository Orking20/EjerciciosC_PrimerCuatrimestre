/*
 * Razas.c
 *
 *  Created on: 20 abr. 2021
 *      Author: mateo
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Razas.h"
#define TAM_DESCRIPCION 4096
#define TAM_PAIS_ORIGEN 100
#define TAM_TAMANIO 20

int inicializarRazas(Raza* pRazas, int limite)
{
	int retorno = -1;

	if(pRazas != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			pRazas[i].idRaza = 0;
			strncpy(pRazas[i].descripcion, "", sizeof(pRazas[i].descripcion));
			pRazas[i].tamanio = 0;
			strncpy(pRazas[i].paisOrigen, "", sizeof(pRazas[i].paisOrigen));
			pRazas[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

int altaRaza(Raza* pRazas, int indice)
{
	int retorno = -1;
	Raza bufferRaza;

	if(pRazas != NULL && indice >= 0)
	{
		if(!utn_getTexto(bufferRaza.descripcion, TAM_DESCRIPCION, "Ingrese la descripción (raza)\n", "Error. raza no válida\n") &&
		   !utn_getNumero(&bufferRaza.tamanio, "Ingrese el tamaño (1.Chico - 2.Mediano - 3.Grande):\n", "Error. Solo puede ingresar (1.Chico - 2.Mediano - 3.Grande):\n", 1, 3, 5) &&
		   !utn_getTexto(bufferRaza.paisOrigen, TAM_PAIS_ORIGEN, "Ingrese el pais: \n", "Error. Ese no es un país válido\n"))
		{
			bufferRaza.idRaza = indice + 1;
			bufferRaza.isEmpty = 0;
			pRazas[indice] = bufferRaza;
			retorno = 0;
		}
		else
		{
			printf("Ingresaste un dato inválido.\n");
		}
	}

	return retorno;
}

int mostrarRazas(Raza* pRazas, int limite)
{
	int retorno = -1;

	if(pRazas != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pRazas[i].isEmpty)
			{
				printf("ID: %-10d Descripción: %-10s Pais de origen: %-15s\n", pRazas[i].idRaza, pRazas[i].descripcion, pRazas[i].paisOrigen);
			}
		}
		retorno = 0;
	}

	return retorno;
}

/*int getPeso(Raza* pRazas, int limite, int id, int* tamanio)
{
	int retorno = -1;

	for(int j = 0; j < limite; j++)
	{
		printf("IsEmpty: %d", pRazas[j].isEmpty);
	}

	if(pRazas != NULL && limite > 0 && tamanio != NULL)
	{
		retorno = -2;
		for(int i = 0; i < limite; i++)
		{
			if(pRazas[i].idRaza == id)
			{
				*tamanio = pRazas[i].tamanio;
				printf("Entró al if del getPeso\n");
				retorno = 0;
				break;
			}
			printf("retorna -2\n");
		}
	}

	return retorno;
}*/

int buscarIndiceVacioRaza(Raza* pRazas, int limite)
{
	int respuesta = -1;

	if(pRazas != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pRazas[i].isEmpty)
			{
				respuesta = i;
				break;
			}
		}
	}

	return respuesta;
}

int buscarIdRazas(Raza* pRazas, int limite, int id)
{
	int retorno = -1;

	if(pRazas != NULL)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pRazas[i].idRaza == id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
