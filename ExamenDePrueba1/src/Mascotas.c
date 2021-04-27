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
			//pMascotas[i].sexo = '';
			strncpy(pMascotas[i].tipo, "", sizeof(pMascotas[i].tipo));
			pMascotas[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

void harcodeoMascotas(Mascota* pMascotas, int limite)
{
	int id[7] = {1, 2, 3, 4, 5, 6, 7};
	char nombre[7][TAM_NOMBRE] = {"Pipo", "Lolo", "Iris", "Negro", "Sara", "Olivia", "Uclides"};
	int edad[7] = {13, 9, 7, 8, 4, 16, 3};
	char sexo[7] = {'f', 'm', 'f', 'm', 'm', 'm', 'm'};
	char tipo[7][TAM_TIPO] = {"Gato", "Gato", "Gato", "Raro", "Perro", "Perro", "Gato"};
	int isEmpty[7] = {0, 0, 0, 0, 0, 0, 0};
	int idRaza[7] = {1, 2, 3, 4, 5, 6, 7};

	for(int i = 0; i < limite; i++)
	{
		pMascotas[i].idMascota = id[i];
		strncpy(pMascotas[i].nombre, nombre[i], sizeof(pMascotas[i].nombre));
		pMascotas[i].edad = edad[i];
		pMascotas[i].sexo = sexo[i];
		strncpy(pMascotas[i].tipo, tipo[i], sizeof(pMascotas[i].tipo));
		pMascotas[i].isEmpty = isEmpty[i];
		pMascotas[i].idRaza = idRaza[i];
	}
}

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

int buscarMascotas(Mascota* pMascota, int limite)
{
	int respuesta = -1;

	if(pMascota != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i ++)
		{
			if(!pMascota[i].isEmpty)
			{
				respuesta = 1;
				break;
			}
			respuesta = 0;
		}
	}

	return respuesta;
}
