/*
 * Estructura.c
 *
 *  Created on: 27 abr. 2021
 *      Author: mateo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estructura.h"

/**
 * brief Inicia los valores de todas los automoviles a valores vacíos
 * \param Automovil* pAutomovil: Cadena que contiene todas los automoviles y va a ser objetivo de la función
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) si pudo iniciar los valores o -1 (ERROR) si no*/
int inicializarEstructura(Estructura* pEstructura, int limite)
{
	int retorno = -1;

	if(pEstructura != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			strncpy(pEstructura[i].cadena, "", sizeof(pEstructura[i].cadena));
			pEstructura[i].numero = 0;
			pEstructura[i].id = 0;
			pEstructura[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Busca dentro de pAutomovil una posición vacía
 * \param Automovil* pAutomovil: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora la posición más cercana al 0 que esté vacía o -1 si no hay posiciones vacías o si hubo un error*/
int buscarIndiceVacioEstructura(Estructura* pEstructura, int limite)
{
	int respuesta = -1;

	if(pEstructura != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pEstructura[i].isEmpty)
			{
				respuesta = i;
				break;
			}
		}
	}

	return respuesta;
}

/**
 * brief Busca dentro de pAutomovil si hay por lo menos un dato cargado
 * \param Automovil* pAutomovil: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 1 si hay aunque sea un automovil, 0 si no hay ninguna o -1 en caso de error*/
int buscarEstructura(Estructura* pEstructura, int limite)
{
	int respuesta = -1;

	if(pEstructura != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pEstructura[i].isEmpty)
			{
				respuesta = 1;
				break;
			}
			respuesta = 0;
		}
	}

	return respuesta;
}
