/*
 * Relacion.c
 *
 *  Created on: 23 abr. 2021
 *      Author: mateo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Mascotas.h"
#include "Razas.h"
#include "Relacion.h"

static int getPeso(Raza* pRazas, Mascota* pMascotas, int indice, int limiteRaza);
static int buscarRazas(Raza* pRazas, int limite);
static int buscarMascotas(Mascota* pMascota, int limite);

int altaMascota(Mascota* pMascotas, Raza* pRazas, int indice, int limiteRazas)
{
	int retorno = -1;
	Mascota bufferMascota;
	int idRaza;

	if(pMascotas != NULL && pRazas != NULL && indice >= 0 && limiteRazas > 0)
	{
		if(buscarRazas(pRazas, limiteRazas) == 1)
		{
			if(!utn_getNombre(bufferMascota.nombre, "Ingrese el nombre: \n", "Error. Ese no es un nombre válido\n") &&
			   !utn_getEdad(&bufferMascota.edad, "Ingrese la edad: \n", "Error. Esa no es una edad válida\n") &&
			   !utn_getNumero(&bufferMascota.sexo, "Ingrese el sexo (1.Femenino - 2.Masculino):\n", "Error. Solo puede ingresar (1.Femenino - 2.Masculino):\n", 1, 2, 5) &&
			   !utn_getNumero(&bufferMascota.tipo, "Ingrese el tipo (1.Gato - 2.Perro - 3.Raro):\n", "Error. Solo puede ingresar (1.Gato - 2.Perro - 3.Raro):\n", 1, 3, 5))
			{
				mostrarRazas(pRazas, limiteRazas);
				if(!utn_getNumero(&idRaza, "Ingrese el ID de la raza: \n", "Error. Ese ID es inválido\n", 1, 10, 3))
				{
					for(int i = 0; i < limiteRazas; i++)
					{
						if(idRaza == pRazas[i].idRaza)
						{
							bufferMascota.idRaza = idRaza;
							bufferMascota.idMascota = indice + 1;
							bufferMascota.isEmpty = 0;
							pMascotas[indice] = bufferMascota;
							retorno = 0;
							break;
						}
					}
				}
				if(retorno == -1)
				{
					printf("No existe ninguna raza con ese ID\n");
				}
			}
			else
			{
				printf("Ingresaste un dato inválido.\n");
			}
		}
		else
		{
			printf("Error. Todavía no se ingresó ninguna raza. Primero tiene que dar de alta una raza para añadir una mascota.\n");
		}
	}

	return retorno;
}

int borrarMascota(Mascota* pMascotas, Raza* pRazas, int limite)
{
	int retorno = -1;
	int numeroId;

	if(pMascotas != NULL && pRazas != NULL && limite > 0)
	{
		if(buscarMascotas(pMascotas, limite) == 1)
		{
			mostrarMascotasId(pMascotas, pRazas, limite);
			utn_getNumero(&numeroId, "Ingrese el ID de la mascota a eliminar: \n", "Error. Ese ID no es válido\n", 1, 10, 3);

			for(int i = 0; i < limite; i++)
			{
				if(numeroId == pMascotas[i].idMascota)
				{
					pMascotas[i].idMascota = 0;
					strncpy(pMascotas[i].nombre, "", sizeof(pMascotas[i].nombre));
					pMascotas[i].edad = 0;
					pMascotas[i].sexo = 0;
					pMascotas[i].tipo = 0;
					pMascotas[i].isEmpty = 1;

					//ordenarPorIsEmpty(pMascotas, limite);
					ordenarPorPeso(pMascotas, pRazas, limite);
					mostrarMascotas(pMascotas, pRazas, limite);
					break;
				}
			}
			retorno = 0;
		}
		else
		{
			printf("Todavía no ingresaste ninguna mascota\n");
		}
	}

	return retorno;
}

int mostrarMascotas(Mascota* pMascotas, Raza* pRazas, int limite)
{
	int retorno = -1;

	if(pMascotas != NULL && pRazas != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pMascotas[i].isEmpty)
			{
				printf("Nombre: %-10s Edad: %-10d Sexo: %-10d Tipo: %-10d Raza: %-10s\n", pMascotas[i].nombre, pMascotas[i].edad, pMascotas[i].sexo, pMascotas[i].tipo, pRazas[i].descripcion);
			}
		}
		retorno = 0;
	}

	return retorno;
}

int mostrarMascotasId(Mascota* pMascotas, Raza* pRazas, int limite)
{
	int retorno = -1;

	if(pMascotas != NULL && pRazas != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pMascotas[i].isEmpty)
			{
				printf("ID: %-10d Nombre: %-10s Edad: %-10d Sexo: %-10d Tipo: %-10d Raza: %-10s\n", pMascotas[i].idMascota, pMascotas[i].nombre, pMascotas[i].edad, pMascotas[i].sexo, pMascotas[i].tipo, pRazas[i].descripcion);
			}
		}
		retorno = 0;
	}

	return retorno;
}

int ordenarPorIsEmpty(Mascota* pMascotas, int limite)
{
	int retorno = -1;
	int flagSwap = 0;
	Mascota auxiliar;

	if(pMascotas != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 0; i < limite - 1; i++)
			{
				if(pMascotas[i].isEmpty > pMascotas[i + 1].isEmpty)
				{
					auxiliar = pMascotas[i];
					pMascotas[i] = pMascotas[i + 1];
					pMascotas[i + 1] = auxiliar;
					flagSwap = 1;
				}
			}
		}while(flagSwap);

		retorno = 0;
	}

	return retorno;
}

int ordenarPorPeso(Mascota* pMascotas, Raza* pRazas, int limite)
{
	int retorno = -1;
	int flagSwap = 0;
	Mascota auxiliar;

	if(pMascotas != NULL && pRazas != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 0; i < limite - 1; i++)
			{
				if(getPeso(pRazas, pMascotas, i, limite) > getPeso(pRazas, pMascotas, i + 1, limite))
				{
					auxiliar = pMascotas[i];
					pMascotas[i] = pMascotas[i + 1];
					pMascotas[i + 1] = auxiliar;
					flagSwap = 1;
				}
			}
		}while(flagSwap);

		retorno = 0;
	}

	return retorno;
}

static int getPeso(Raza* pRazas, Mascota* pMascotas, int indice, int limiteRaza)
{
	int retorno = -1;
	int idRaza;
	int indiceRaza;

	if(pRazas != NULL && pMascotas != NULL && indice >= 0 && limiteRaza > 0)
	{
		idRaza = pMascotas[indice].idRaza;
		indiceRaza = buscarIdRazas(pRazas, limiteRaza, idRaza);

		return pRazas[indiceRaza].tamanio;
	}

	return retorno;
}

static int buscarRazas(Raza* pRazas, int limite)
{
	int respuesta = -1;

	if(pRazas != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i ++)
		{
			if(!pRazas[i].isEmpty)
			{
				respuesta = 1;
				break;
			}
			respuesta = 0;
		}
	}

	return respuesta;
}

static int buscarMascotas(Mascota* pMascota, int limite)
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
