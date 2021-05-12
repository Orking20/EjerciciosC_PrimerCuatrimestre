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
int contratacion_inicializar(Contratacion* pContratacion, int limite)
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
int contratacion_buscarIndiceVacio(Contratacion* pContratacion, int limite)
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
int contratacion_buscar(Contratacion* pContratacion, int limite)
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

/*int getCantDias(Contratacion* pContrataciones, int indice, int* pCantDiasEncontrados)
{
	int retorno = -1;

	if(pContrataciones != NULL && indice >= 0 && pCantDiasEncontrados != NULL)
	{
		*pCantDiasEncontrados = pContrataciones[indice].cantDias;
		retorno = 0;
	}

	return retorno;
}

int setCantDias(Contratacion* pContrataciones, int indice, int* pCantDiasAGuardar)
{
	int retorno = -1;

	if(pContrataciones != NULL && indice >= 0 && validarDias(pCantDiasAGuardar) == 1)
	{
		pContrataciones[indice].cantDias = *pCantDiasAGuardar;
		retorno = 0;
	}

	return retorno;
}


int getCuit(Contratacion* pContrataciones, int indice, char* pCuitEncontrado)
{
	int retorno = -1;

	if(pContrataciones != NULL && indice >= 0 && pCuitEncontrado != NULL)
	{
		strncpy(pCuitEncontrado, pContrataciones[indice].cuitCliente, sizeof(TAM_CUIT));
		retorno = 0;
	}

	return retorno;
}

int setCuit(Contratacion* pContrataciones, int indice, char* pCuitAGuardar)
{
	int retorno = -1;

	if(pContrataciones != NULL && indice >= 0 && validarCuit(pCuitAGuardar) == 1)
	{
		strncpy(pContrataciones[indice].cuitCliente, pCuitAGuardar, sizeof(pContrataciones[indice].cuitCliente));
		retorno = 0;
	}

	return retorno;
}

int getNombreArchivo(Contratacion* pContrataciones, int indice, char* pNombreArchivoEncontrado)
{
	int retorno = -1;

	if(pContrataciones != NULL && indice >= 0 && pNombreArchivoEncontrado != NULL)
	{
		strncpy(pNombreArchivoEncontrado, pContrataciones[indice].nombreArchivo, sizeof(TAM_NOMBRE_ARCHIVO));
		retorno = 0;
	}

	return retorno;
}

int setNombreArchivo(Contratacion* pContrataciones, int indice, char* pNombreArchivoAGuardar)
{
	int retorno = -1;

	if(pContrataciones != NULL && indice >= 0 && validarNombreArchivo(pNombreArchivoAGuardar) == 1)
	{
		strncpy(pContrataciones[indice].nombreArchivo, pNombreArchivoAGuardar, sizeof(pContrataciones[indice].nombreArchivo));
		retorno = 0;
	}

	return retorno;
}*/
