/*
 * Mascotas.c
 *
 *  Created on: 20 abr. 2021
 *      Author: mateo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Mascotas.h"
#define TAM_SEXO 20
#define TAM_TIPO 20

int inicializarMascotas(Mascota* pMascotas, int limite)
{
	int retorno = -1;

	if(pMascotas != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			pMascotas[i].idMascota = 0;
			strncpy(pMascotas[i].nombre, "", sizeof(pMascotas[i].nombre));
			pMascotas[i].edad = 0;
			pMascotas[i].sexo = 0;
			pMascotas[i].tipo = 0;
			pMascotas[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

/*static int iniciarId(Mascota* pMascotas, int indice)
{
	int retorno = -1;

	if(pMascotas != NULL)
	{
		pMascotas[indice].idMascota = indice + 1;
	}

	return retorno;
}*/

int buscarIndiceVacioMascota(Mascota* pMascotas, int limite)
{
	int respuesta = -1;

	if(pMascotas != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pMascotas[i].isEmpty)
			{
				respuesta = i;
				break;
			}
		}
	}

	return respuesta;
}
