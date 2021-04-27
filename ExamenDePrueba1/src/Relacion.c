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
#define LIMITE_MASCOTAS 10

static int getPeso(Raza* pRazas, Mascota* pMascotas, int indice, int limiteRaza);

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
			   !utn_getCaracter(&bufferMascota.sexo, "Ingrese el sexo (1.Femenino - 2.Masculino):\n", "Error. Solo puede ingresar (1.Femenino - 2.Masculino):\n", 'a', 'z', 3) &&
			   !utn_getTexto(bufferMascota.tipo, LIMITE_MASCOTAS, "Ingrese el tipo (1.Gato - 2.Perro - 3.Raro):\n", "Error. Solo puede ingresar (1.Gato - 2.Perro - 3.Raro):\n"))
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

int modificarMascota(Mascota* pMascotas, Raza* pRazas, int limite)
{
	int retorno = -1;
	Mascota bufferMascota;
	int idRaza;
	int id;

	if(pMascotas != NULL && pRazas != NULL && limite > 0)
	{
		mostrarMascotasId(pMascotas, pRazas, LIMITE_MASCOTAS);
		if(!utn_getNumero(&id, "Ingrese el ID de la mascota a modificar\n", "Error. Ese ID no existe\n", 1, 10, 3))
		{
			for(int i = 0; i < LIMITE_MASCOTAS; i++)
			{
				if(id == pMascotas[i].idMascota)
				{
					if(!utn_getNombre(bufferMascota.nombre, "Ingrese el nombre: \n", "Error. Ese no es un nombre válido\n") &&
					   !utn_getEdad(&bufferMascota.edad, "Ingrese la edad: \n", "Error. Esa no es una edad válida\n") &&
					   !utn_getCaracter(&bufferMascota.sexo, "Ingrese el sexo (1.Femenino - 2.Masculino):\n", "Error. Solo puede ingresar (1.Femenino - 2.Masculino):\n", 'a', 'z', 3) &&
					   !utn_getTexto(bufferMascota.tipo, LIMITE_MASCOTAS, "Ingrese el tipo (1.Gato - 2.Perro - 3.Raro):\n", "Error. Solo puede ingresar (1.Gato - 2.Perro - 3.Raro):\n"))
					{
						mostrarRazas(pRazas, limite);
						if(!utn_getNumero(&idRaza, "Ingrese el ID de la raza: \n", "Error. Ese ID es inválido\n", 1, 10, 3))
						{
							for(int j = 0; j < limite; j++)
							{
								if(idRaza == pRazas[j].idRaza)
								{
									bufferMascota.idRaza = idRaza;
									bufferMascota.isEmpty = 0;
									pMascotas[i] = bufferMascota;
									retorno = 0;
									break;
								}
								else
								{
									printf("No existe ninguna raza con ese ID\n");
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
			}
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
					strncpy(pMascotas[i].tipo, "", sizeof(pMascotas[i].tipo));
					pMascotas[i].isEmpty = 1;

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
	int indiceRaza;

	if(pMascotas != NULL && pRazas != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			indiceRaza = buscarIdRazas(pRazas, limite, pMascotas[i].idRaza);
			if(!pMascotas[i].isEmpty)
			{
				printf("Nombre: %-10s Edad: %-10d Sexo: %-10c Tipo: %-10s Raza: %-10s\n", pMascotas[i].nombre, pMascotas[i].edad, pMascotas[i].sexo, pMascotas[i].tipo, pRazas[indiceRaza].descripcion);
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
				printf("ID: %-10d Nombre: %-10s Edad: %-10d Sexo: %-10c Tipo: %-10s Raza: %-10s\n", pMascotas[i].idMascota, pMascotas[i].nombre, pMascotas[i].edad, pMascotas[i].sexo, pMascotas[i].tipo, pRazas[i].descripcion);
			}
		}
		retorno = 0;
	}

	return retorno;
}

int ordenarPorPeso(Mascota* pMascotas, Raza* pRazas, int limite)
{
	int retorno = -1;
	int flagSwap = 0;
	Mascota auxiliar;
	int peso1;
	int peso2;

	if(pMascotas != NULL && pRazas != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 0; i < limite - 1; i++)
			{
				peso1 = getPeso(pRazas, pMascotas, i, limite);
				peso2 = getPeso(pRazas, pMascotas, i + 1, limite);
				if(peso1 != -1 && peso2 != -1 && peso1 > peso2)
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

int paisConMasMascotas(Mascota* pMascotas, Raza* pRazas, int limite, int cantPaises, int* pais)
{
	int retorno = -1;
	int indiceRaza;
	int paisMaxMascotas = 0;

	if(pMascotas != NULL && pRazas != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			indiceRaza = buscarIdRazas(pRazas, limite, pMascotas[i].idRaza);
			for(int j = 0; j < limite; i++)
			{
				if(pRazas[indiceRaza].paisOrigen == pRazas[j].paisOrigen)
				{
					paisMaxMascotas++;
				}
			}
		}
		retorno = 0;
	}

	return retorno;
}

static int getPeso(Raza* pRazas, Mascota* pMascotas, int indice, int limiteRaza)
{
	int retorno = -1;
	int indiceRaza;

	if(pRazas != NULL && pMascotas != NULL && indice >= 0 && limiteRaza > 0)
	{
		indiceRaza = buscarIdRazas(pRazas, limiteRaza, pMascotas[indice].idRaza);

		return pRazas[indiceRaza].tamanio;
	}

	return retorno;
}
