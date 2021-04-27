/*
 * Mascotas.c
 *
 *  Created on: 20 abr. 2021
 *      Author: mateo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Automovil.h"

/**
 * brief Inicia los valores de todas los automoviles a valores vacíos
 * \param Automovil* pAutomovil: Cadena que contiene todas los automoviles y va a ser objetivo de la función
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) si pudo iniciar los valores o -1 (ERROR) si no*/
int inicializarAutomovil(Automovil* pAutomovil, int limite)
{
	int retorno = -1;

	if(pAutomovil != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			pAutomovil[i].idAutomovil = 0;
			strncpy(pAutomovil[i].patente, "", sizeof(pAutomovil[i].patente));
			pAutomovil[i].marca = 0;
			pAutomovil[i].isEmpty = 1;
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
int buscarIndiceVacioAutomovil(Automovil* pAutomovil, int limite)
{
	int respuesta = -1;

	if(pAutomovil != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pAutomovil[i].isEmpty)
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
int buscarAutomovil(Automovil* pAutomovil, int limite)
{
	int respuesta = -1;

	if(pAutomovil != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pAutomovil[i].isEmpty)
			{
				respuesta = 1;
				break;
			}
			respuesta = 0;
		}
	}

	return respuesta;
}
