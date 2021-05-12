/*
 * Tipo.c
 *
 *  Created on: 28 abr. 2021
 *      Author: mateo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Tipo.h"
#include "utn.h"

/**
 * brief Inicia los valores de todos los datos de la Tipo a valores vacíos
 * \param Tipo* pTipo: Cadena que contiene todos los campos y va a ser objetivo de la función
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) si pudo iniciar los valores o -1 (ERROR) si no*/
int Tipo_inicializar(Tipo* pTipo, int limite)
{
	int retorno = -1;

	if(pTipo != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			strncpy(pTipo[i].cadena, "", sizeof(pTipo[i].cadena));
			pTipo[i].numero = 0;
			pTipo[i].id = 0;
			pTipo[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Agrega datos a la cadena pTipo
 * \param Tipo* pTipo: Cadena que va a ser objetivo de la función
 * \param int limite: Limite o tamaño de la cadena*/
void Tipo_harcodeo(Tipo* pTipo, int limite)
{
	int id[7] = {1, 2, 3, 4, 5, 6, 7};
	char cadena[7][TAM_CADENA] = {"Pipo", "Lolo", "Iris", "Negro", "Sara", "Olivia", "Uclides"};
	int numero[7] = {13, 9, 7, 8, 4, 16, 3};
	int isEmpty[7] = {0, 0, 0, 0, 0, 0, 0};

	for(int i = 0; i < limite; i++)
	{
		pTipo[i].id = id[i];
		strncpy(pTipo[i].cadena, cadena[i], sizeof(pTipo[i].cadena));
		pTipo[i].numero = numero[i];
		pTipo[i].isEmpty = isEmpty[i];
	}
}

/**
 * brief Ordena la lista pTipo según el NÚMERO de mayor a menor
 * \param Tipo* pTipo: Cadena que va a ser ordenada
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) si pudo ordenar correctamente o -1 (ERROR) si no*/
int ordenarPorNumero(Tipo* pTipo, int limite)
{
	int retorno = -1;
	int flagSwap = 0;
	Tipo auxiliar;

	if(pTipo != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 0; i < limite - 1; i++)
			{
				if(pTipo[i].numero > pTipo[i + 1].numero)
				{
					auxiliar = pTipo[i];
					pTipo[i] = pTipo[i + 1];
					pTipo[i + 1] = auxiliar;
					flagSwap = 1;
				}
			}
		}while(flagSwap);

		retorno = 0;
	}

	return retorno;
}

/**
 * brief Muestra una lista de todas las TipoS incluyendo el ID
 * \param Contratacion* pContratacion: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena pTipo
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int Tipo_mostrarId(Tipo* pTipo, int limite)
{
	int retorno = -1;

	if(pTipo != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pTipo[i].isEmpty)
			{
				printf("ID: %-10d CADENA: %-15s CADENA: %-15s NÚMERO: %-15d\n", pTipo[i].id, pTipo[i].cadena, pTipo[i].cadena, pTipo[i].numero);
			}
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Busca dentro de pTipo una posición vacía
 * \param Tipo* pTipo: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora la posición más cercana al 0 que esté vacía o -1 si no hay posiciones vacías o si hubo un error*/
int Tipo_buscarIndiceVacio(Tipo* pTipo, int limite)
{
	int respuesta = -1;

	if(pTipo != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pTipo[i].isEmpty)
			{
				respuesta = i;
				break;
			}
		}
	}

	return respuesta;
}

/**
 * brief Busca la posición donde la Tipo Tipo y otra Tipo tengan el mismo ID
 * \param Tipo* pTipo: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena pTipo
 * \param int id: ID que va a ser comparado con el ID de Tipo
 * \return Retora la posición donde los IDs sean iguales o -1 en caso de error*/
int Tipo_buscarPorId(Tipo* pTipo, int limite, int id)
{
	int retorno = -1;

	if(pTipo != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pTipo[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

/**
 * brief Busca dentro de pTipo si hay por lo menos un dato cargado
 * \param Tipo* pTipo: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 1 si hay aunque sea una Tipo, 0 si no hay ninguna o -1 en caso de error*/
int Tipo_buscar(Tipo* pTipo, int limite)
{
	int respuesta = -1;

	if(pTipo != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pTipo[i].isEmpty)
			{
				respuesta = 1;
				break;
			}
			respuesta = 0;
		}
	}

	return respuesta;
}
