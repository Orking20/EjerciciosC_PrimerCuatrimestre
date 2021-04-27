/*
 * Mascotas.c
 *
 *  Created on: 20 abr. 2021
 *      Author: mateo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contratacion.h"

/**
 * brief Inicia los valores de todas las contrataciones a valores vacíos
 * \param Contratacion* pContratacion: Cadena que contiene todas las contrataciones y va a ser objetivo de la función
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) si pudo iniciar los valores o -1 (ERROR) si no*/
int inicializarContratacion(Contratacion* pContratacion, int limite)
{
	int retorno = -1;

	if(pContratacion != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			pContratacion[i].idContratacion = 0;
			strncpy(pContratacion[i].nombreArchivo, "", sizeof(pContratacion[i].nombreArchivo));
			pContratacion[i].cantDias = 0;
			strncpy(pContratacion[i].cuitCliente, "", sizeof(pContratacion[i].cuitCliente));
			pContratacion[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Busca dentro de pContratacion una posición vacía
 * \param Contratacion* pContratacion: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora la posición más cercana al 0 que esté vacía o -1 si no hay posiciones vacías o si hubo un error*/
int buscarIndiceVacioContratacion(Contratacion* pContratacion, int limite)
{
	int respuesta = -1;

	if(pContratacion != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pContratacion[i].isEmpty)
			{
				respuesta = i;
				break;
			}
		}
	}

	return respuesta;
}

/**
 * brief Busca dentro de pContratacion si hay por lo menos un dato cargado
 * \param Contratacion* pContratacion: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 1 si hay aunque sea una contratación, 0 si no hay ninguna o -1 en caso de error*/
int buscarContratacion(Contratacion* pContratacion, int limite)
{
	int respuesta = -1;

	if(pContratacion != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pContratacion[i].isEmpty)
			{
				respuesta = 1;
				break;
			}
			respuesta = 0;
		}
	}

	return respuesta;
}
