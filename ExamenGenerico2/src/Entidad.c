/*
 * Entidad.c
 *
 *  Created on: 28 abr. 2021
 *      Author: mateo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Entidad.h"

/**
 * brief Inicia los valores de todas las ENTIDADES a valores vacíos
 * \param Entidad* pEntidad: Cadena que contiene todas las ENTIDADES y va a ser objetivo de la función
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) si pudo iniciar los valores o -1 (ERROR) si no*/
int entidad_inicializar(Entidad* pEntidad, int limite)
{
	int retorno = -1;

	if(pEntidad != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			pEntidad[i].id = 0;
			strncpy(pEntidad[i].cadena, "", sizeof(pEntidad[i].cadena));
			strncpy(pEntidad[i].cadena, "", sizeof(pEntidad[i].cadena));
			strncpy(pEntidad[i].cadena, "", sizeof(pEntidad[i].cadena));
			pEntidad[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Pide al usuario que cargue los datos de una ENTIDAD
 * \param Entidad* pEntidad: Cadena donde se guardarán los valores
 * \param int indice: La posición donde van a ser guardados los datos
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int entidad_alta(Entidad* pEntidad, int indice)
{
	int retorno = -1;
	Entidad bufferEntidad;

	if(pEntidad != NULL && indice >= 0)
	{
		if(!utn_getTexto(bufferEntidad.cadena, TAM_CADENA, "\nIngrese la CADENA: ", "\nError. La CADENA no es válida ") &&
		   !utn_getNumero(&bufferEntidad.numero, "\nIngrese un NÚMERO: ", "\nError. Ese NÚMERO no es válido", 0, 100, 3))
		{
			bufferEntidad.id = indice + 1;
			bufferEntidad.isEmpty = 0;
			pEntidad[indice] = bufferEntidad;
			retorno = 0;
		}
		else
		{
			printf("\nIngresaste un dato inválido.");
		}
	}

	return retorno;
}

/**
 * brief Pide al usuario que modifique los valores de una ENTIDAD
 * \param Entidad* pEntidad: Cadena donde se guardarán los nuevos valores
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int entidad_modificar(Entidad* pEntidad, int limite)
{
	int retorno = -1;
	Entidad bufferEntidad;
	int idEntidad;

	if(pEntidad != NULL && limite > 0)
	{
		entidad_mostrarConId(pEntidad, limite);
		if(!utn_getNumero(&idEntidad, "\nIngrese el ID de la ENTIDAD a modificar\n", "\nError. Ese ID no existe\n", 1, limite, 3))
		{
			for(int i = 0; i < limite; i++)
			{
				if(idEntidad == pEntidad[i].id)
				{
					if(!utn_getTexto(bufferEntidad.cadena, TAM_CADENA, "\nIngrese la CADENA: ", "\nError. La CADENA no es válida") &&
					   !utn_getTarjetaCredito(bufferEntidad.cadena, "\nIngrese la CADENA: ", "\nError. La CADENA no es válida"))
					{
						bufferEntidad.isEmpty = 0;
						pEntidad[i] = bufferEntidad;
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
 * brief Muestra todos los datos de las ENTIDADES excepto el id
 * \param Entidad* pEntidad: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int entidad_mostrar(Entidad* pEntidad, int limite)
{
	int retorno = -1;

	if(pEntidad != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pEntidad[i].isEmpty)
			{
				printf("CADENA: %-15s CADENA: %-15s CADENA: %-15s\n", pEntidad[i].cadena, pEntidad[i].cadena, pEntidad[i].cadena);
			}
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Muestra todos los datos de las ENTIDADES incluyendo el id
 * \param Entidad* pEntidad: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int entidad_mostrarConId(Entidad* pEntidad, int limite)
{
	int retorno = -1;

	if(pEntidad != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pEntidad[i].isEmpty)
			{
				printf("ID: %-10d CADENA: %-15s CADENA: %-10s CADENA: %-15s\n", pEntidad[i].id, pEntidad[i].cadena, pEntidad[i].cadena, pEntidad[i].cadena);
			}
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Busca dentro de pENTIDAD una posición vacía
 * \param Entidad* pEntidad: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora la posición más cercana al 0 que esté vacía o -1 si no hay posiciones vacías o si hubo un error*/
int entidad_buscarIndiceVacio(Entidad* pEntidad, int limite)
{
	int respuesta = -1;

	if(pEntidad != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pEntidad[i].isEmpty)
			{
				respuesta = i;
				break;
			}
		}
	}

	return respuesta;
}

/**
 * brief Busca la posición donde la estructura ENTIDAD y otra estructura tengan el mismo ID
 * \param Entidad* pEntidad: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \param int id: ID que va a ser comparado con el ID de OTRA ESTRUCTURA
 * \return Retora la posición donde los IDs sean iguales o -1 en caso de error*/
int entidad_buscarPorId(Entidad* pEntidad, int limite, int id)
{
	int retorno = -1;

	if(pEntidad != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pEntidad[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

/**
 * brief Busca dentro de pENTIDAD si hay por lo menos un dato cargado
 * \param Entidad* pEntidad: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 1 si hay aunque sea una ENTIDAD, 0 si no hay ninguna o -1 en caso de error*/
int entidad_buscar(Entidad* pEntidad, int limite)
{
	int respuesta = -1;

	if(pEntidad != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i ++)
		{
			if(!pEntidad[i].isEmpty)
			{
				respuesta = 1;
				break;
			}
			respuesta = 0;
		}
	}

	return respuesta;
}
