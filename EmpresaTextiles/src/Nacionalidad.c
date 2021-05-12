/*
 * Nacionalidad.c
 *
 *  Created on: 28 abr. 2021
 *      Author: mateo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Nacionalidad.h"
#include "utn.h"

/**
 * brief Inicia los valores de todas las NacionalidadES a valores vacíos
 * \param Nacionalidad* pNacionalidad: Cadena que contiene todas las NacionalidadES y va a ser objetivo de la función
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) si pudo iniciar los valores o -1 (ERROR) si no*/
int Nacionalidad_inicializar(Nacionalidad* pNacionalidad, int limite)
{
	int retorno = -1;

	if(pNacionalidad != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			pNacionalidad[i].id = 0;
			strncpy(pNacionalidad[i].cadena, "", sizeof(pNacionalidad[i].cadena));
			strncpy(pNacionalidad[i].cadena, "", sizeof(pNacionalidad[i].cadena));
			strncpy(pNacionalidad[i].cadena, "", sizeof(pNacionalidad[i].cadena));
			pNacionalidad[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Pide al usuario que cargue los datos de una Nacionalidad
 * \param Nacionalidad* pNacionalidad: Cadena donde se guardarán los valores
 * \param int indice: La posición donde van a ser guardados los datos
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int Nacionalidad_alta(Nacionalidad* pNacionalidad, int indice)
{
	int retorno = -1;
	Nacionalidad bufferNacionalidad;

	if(pNacionalidad != NULL && indice >= 0)
	{
		if(!utn_getTexto(bufferNacionalidad.cadena, TAM_CADENA, "\nIngrese la CADENA: ", "\nError. La CADENA no es válida ") &&
		   !utn_getNumero(&bufferNacionalidad.numero, "\nIngrese un NÚMERO: ", "\nError. Ese NÚMERO no es válido", 0, 100, 3))
		{
			bufferNacionalidad.id = indice + 1;
			bufferNacionalidad.isEmpty = 0;
			pNacionalidad[indice] = bufferNacionalidad;
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
 * brief Pide al usuario que modifique los valores de una Nacionalidad
 * \param Nacionalidad* pNacionalidad: Cadena donde se guardarán los nuevos valores
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int Nacionalidad_modificar(Nacionalidad* pNacionalidad, int limite)
{
	int retorno = -1;
	Nacionalidad bufferNacionalidad;
	int idNacionalidad;

	if(pNacionalidad != NULL && limite > 0)
	{
		Nacionalidad_mostrarConId(pNacionalidad, limite);
		if(!utn_getNumero(&idNacionalidad, "\nIngrese el ID de la Nacionalidad a modificar\n", "\nError. Ese ID no existe\n", 1, limite, 3))
		{
			for(int i = 0; i < limite; i++)
			{
				if(idNacionalidad == pNacionalidad[i].id)
				{
					if(!utn_getTexto(bufferNacionalidad.cadena, TAM_CADENA, "\nIngrese la CADENA: ", "\nError. La CADENA no es válida") &&
					   !utn_getTarjetaCredito(bufferNacionalidad.cadena, "\nIngrese la CADENA: ", "\nError. La CADENA no es válida"))
					{
						bufferNacionalidad.isEmpty = 0;
						pNacionalidad[i] = bufferNacionalidad;
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
 * brief Muestra todos los datos de las NacionalidadES excepto el id
 * \param Nacionalidad* pNacionalidad: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int Nacionalidad_mostrar(Nacionalidad* pNacionalidad, int limite)
{
	int retorno = -1;

	if(pNacionalidad != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pNacionalidad[i].isEmpty)
			{
				printf("CADENA: %-15s CADENA: %-15s CADENA: %-15s\n", pNacionalidad[i].cadena, pNacionalidad[i].cadena, pNacionalidad[i].cadena);
			}
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Muestra todos los datos de las NacionalidadES incluyendo el id
 * \param Nacionalidad* pNacionalidad: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int Nacionalidad_mostrarConId(Nacionalidad* pNacionalidad, int limite)
{
	int retorno = -1;

	if(pNacionalidad != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pNacionalidad[i].isEmpty)
			{
				printf("ID: %-10d CADENA: %-15s CADENA: %-10s CADENA: %-15s\n", pNacionalidad[i].id, pNacionalidad[i].cadena, pNacionalidad[i].cadena, pNacionalidad[i].cadena);
			}
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Busca dentro de pNacionalidad una posición vacía
 * \param Nacionalidad* pNacionalidad: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora la posición más cercana al 0 que esté vacía o -1 si no hay posiciones vacías o si hubo un error*/
int Nacionalidad_buscarIndiceVacio(Nacionalidad* pNacionalidad, int limite)
{
	int respuesta = -1;

	if(pNacionalidad != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pNacionalidad[i].isEmpty)
			{
				respuesta = i;
				break;
			}
		}
	}

	return respuesta;
}

/**
 * brief Busca la posición donde la estructura Nacionalidad y otra estructura tengan el mismo ID
 * \param Nacionalidad* pNacionalidad: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \param int id: ID que va a ser comparado con el ID de OTRA ESTRUCTURA
 * \return Retora la posición donde los IDs sean iguales o -1 en caso de error*/
int Nacionalidad_buscarPorId(Nacionalidad* pNacionalidad, int limite, int id)
{
	int retorno = -1;

	if(pNacionalidad != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pNacionalidad[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

/**
 * brief Busca dentro de pNacionalidad si hay por lo menos un dato cargado
 * \param Nacionalidad* pNacionalidad: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 1 si hay aunque sea una Nacionalidad, 0 si no hay ninguna o -1 en caso de error*/
int Nacionalidad_buscar(Nacionalidad* pNacionalidad, int limite)
{
	int respuesta = -1;

	if(pNacionalidad != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i ++)
		{
			if(!pNacionalidad[i].isEmpty)
			{
				respuesta = 1;
				break;
			}
			respuesta = 0;
		}
	}

	return respuesta;
}
