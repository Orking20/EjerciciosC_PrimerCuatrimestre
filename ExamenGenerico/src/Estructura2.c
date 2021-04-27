/*
 * Estructura2.c
 *
 *  Created on: 27 abr. 2021
 *      Author: mateo
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estructura2.h"
#include "utn.h"
#define CANT_PROPIETARIO 100
#define CANT_AUTOMOVIL 1000

/**
 * brief Inicia los valores de todas los propietarios a valores vacíos
 * \param Propietario* pPropietario: Cadena que contiene todos los propietario y va a ser objetivo de la función
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) si pudo iniciar los valores o -1 (ERROR) si no*/
int inicializarEstructura2(Estructura2* pEstructura2, int limite)
{
	int retorno = -1;

	if(pEstructura2 != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			pEstructura2[i].id = 0;
			strncpy(pEstructura2[i].cadena, "", sizeof(pEstructura2[i].cadena));
			strncpy(pEstructura2[i].cadena, "", sizeof(pEstructura2[i].cadena));
			strncpy(pEstructura2[i].cadena, "", sizeof(pEstructura2[i].cadena));
			pEstructura2[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Pide al usuario que cargue los datos de un propietario
 * \param Propietario* pPropietario: Cadena donde se guardarán los valores
 * \param int indice: La posición donde van a ser guardados los datos
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int altaEstructura2(Estructura2* pEstructura2, int indice)
{
	int retorno = -1;
	Estructura2 bufferEstructura2;

	if(pEstructura2 != NULL && indice >= 0)
	{
		if(!utn_getTexto(bufferEstructura2.cadena, TAM_Y, "Ingrese el nombre y apellido:\n", "Error. El nombre y apellido no es válido\n") &&
		   !utn_getDireccion(bufferEstructura2.cadena, "Ingrese la dirección (sin la altura): \n", "Ingrese la altura: \n", "Error. Esa no es una dirección válida\n", "Error. Esa no es una altura válida\n") &&
		   !utn_getTarjetaCredito(bufferEstructura2.cadena, "Ingrese el número de tarjeta de crédito:\n", "Error. Ese número de tarjeta de crédito no es válido\n"))
		{
			bufferEstructura2.id = indice + 1;
			bufferEstructura2.isEmpty = 0;
			pEstructura2[indice] = bufferEstructura2;
			retorno = 0;
		}
		else
		{
			printf("Ingresaste un dato inválido.\n");
		}
	}

	return retorno;
}

/**
 * brief Pide al usuario que modifique los valores de un propietario
 * \param Propietario* pPropietario: Cadena donde se guardarán los nuevos valores
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int modificarEstructura2(Estructura2* pEstructura2, int limite)
{
	int retorno = -1;
	Estructura2 bufferEstructura2;
	int id;

	if(pEstructura2 != NULL && limite > 0)
	{
		mostrarEstructura2Id(pEstructura2, limite);
		if(!utn_getNumero(&id, "Ingrese el ID del propietario a modificar\n", "Error. Ese ID no existe\n", 1, CANT_PROPIETARIO, 3))
		{
			for(int i = 0; i < CANT_PROPIETARIO; i++)
			{
				if(id == pEstructura2[i].id)
				{
					if(!utn_getTexto(bufferEstructura2.cadena, TAM_Y, "Ingrese el nombre y apellido: \n", "Error. Ese no es un nombre y apellido válido\n") &&
					   !utn_getDireccion(bufferEstructura2.cadena, "Ingrese la dirección (sin la altura): \n", "Ingrese la altura: \n", "Error. Esa no es una dirección válida\n", "Error. Esa no es una altura válida\n") &&
					   !utn_getTarjetaCredito(bufferEstructura2.cadena, "Ingrese el número de tarjeta de crédito:\n", "Error. Ese número de tarjeta de crédito no es válido\n"))
					{
						bufferEstructura2.isEmpty = 0;
						pEstructura2[i] = bufferEstructura2;
						retorno = 0;
						break;
					}
				}
			}
		}
	}

	return retorno;
}

/**
 * brief Muestra todos los datos de los propietarios excepto el id
 * \param Pantalla* pPantalla: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int mostrarEstructura2(Estructura2* pEstructura2, int limite)
{
	int retorno = -1;

	if(pEstructura2 != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pEstructura2[i].isEmpty)
			{
				printf("Nombre y apellido: %-15s Dirección: %-10s Número de tarjeta: %-15s\n", pEstructura2[i].cadena, pEstructura2[i].cadena, pEstructura2[i].cadena);
			}
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Muestra todos los datos de los propietarios incluyendo el id
 * \param Pantalla* pPantalla: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int mostrarEstructura2Id(Estructura2* pEstructura2, int limite)
{
	int retorno = -1;

	if(pEstructura2 != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pEstructura2[i].isEmpty)
			{
				printf("ID: %-10d Nombre: %-15s Dirección: %-10s Número de tarjeta: %-15s\n", pEstructura2[i].id, pEstructura2[i].cadena, pEstructura2[i].cadena, pEstructura2[i].cadena);
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

/**
 * brief Busca dentro de pPropietario una posición vacía
 * \param Propietario* pPropietario: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora la posición más cercana al 0 que esté vacía o -1 si no hay posiciones vacías o si hubo un error*/
int buscarIndiceVacioEstructura2(Estructura2* pEstructura2, int limite)
{
	int respuesta = -1;

	if(pEstructura2 != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pEstructura2[i].isEmpty)
			{
				respuesta = i;
				break;
			}
		}
	}

	return respuesta;
}

/**
 * brief Busca la posición donde la estructura Propietario y otra estructura tengan el mismo ID
 * \param Propietario* pPropietario: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \param int id: ID que va a ser comparado con el ID de Pantalla
 * \return Retora la posición donde los IDs sean iguales o -1 en caso de error*/
int buscarIdEstructura2(Estructura2* pEstructura2, int limite, int idArgumento)
{
	int retorno = -1;

	if(pEstructura2 != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pEstructura2[i].id == idArgumento)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

/**
 * brief Busca dentro de pPropietario si hay por lo menos un dato cargado
 * \param Propietario* pPropietario: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 1 si hay aunque sea un propietario, 0 si no hay ninguna o -1 en caso de error*/
int buscarEstructura2(Estructura2* pEstructura2, int limite)
{
	int respuesta = -1;

	if(pEstructura2 != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i ++)
		{
			if(!pEstructura2[i].isEmpty)
			{
				respuesta = 1;
				break;
			}
			respuesta = 0;
		}
	}

	return respuesta;
}
