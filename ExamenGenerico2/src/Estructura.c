/*
 * Estructura.c
 *
 *  Created on: 28 abr. 2021
 *      Author: mateo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Estructura.h"

/**
 * brief Inicia los valores de todos los datos de la ESTRUCTURA a valores vacíos
 * \param Estructura* pEstructura: Cadena que contiene todos los campos y va a ser objetivo de la función
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) si pudo iniciar los valores o -1 (ERROR) si no*/
int estructura_inicializar(Estructura* pEstructura, int limite)
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
 * brief Agrega datos a la cadena pESTRUCTURA
 * \param Estructura* pEstructura: Cadena que va a ser objetivo de la función
 * \param int limite: Limite o tamaño de la cadena*/
void estructura_harcodeo(Estructura* pEstructura, int limite)
{
	int id[7] = {1, 2, 3, 4, 5, 6, 7};
	char cadena[7][TAM_CADENA] = {"Pipo", "Lolo", "Iris", "Negro", "Sara", "Olivia", "Uclides"};
	int numero[7] = {13, 9, 7, 8, 4, 16, 3};
	int isEmpty[7] = {0, 0, 0, 0, 0, 0, 0};

	for(int i = 0; i < limite; i++)
	{
		pEstructura[i].id = id[i];
		strncpy(pEstructura[i].cadena, cadena[i], sizeof(pEstructura[i].cadena));
		pEstructura[i].numero = numero[i];
		pEstructura[i].isEmpty = isEmpty[i];
	}
}

/**
 * brief Ordena la lista pESTRUCTURA según el NÚMERO de mayor a menor
 * \param Estructura* pEstructura: Cadena que va a ser ordenada
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) si pudo ordenar correctamente o -1 (ERROR) si no*/
int ordenarPorNumero(Estructura* pEstructura, int limite)
{
	int retorno = -1;
	int flagSwap = 0;
	Estructura auxiliar;

	if(pEstructura != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 0; i < limite - 1; i++)
			{
				if(pEstructura[i].numero > pEstructura[i + 1].numero)
				{
					auxiliar = pEstructura[i];
					pEstructura[i] = pEstructura[i + 1];
					pEstructura[i + 1] = auxiliar;
					flagSwap = 1;
				}
			}
		}while(flagSwap);

		retorno = 0;
	}

	return retorno;
}

/**
 * brief Muestra una lista de todas las ESTRUCTURAS incluyendo el ID
 * \param Contratacion* pContratacion: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena pESTRUCTURA
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int estructura_mostrarId(Estructura* pEstructura, int limite)
{
	int retorno = -1;

	if(pEstructura != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pEstructura[i].isEmpty)
			{
				printf("ID: %-10d CADENA: %-15s CADENA: %-15s NÚMERO: %-15d\n", pEstructura[i].id, pEstructura[i].cadena, pEstructura[i].cadena, pEstructura[i].numero);
			}
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Busca dentro de pESTRUCTURA una posición vacía
 * \param Estructura* pEstructura: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora la posición más cercana al 0 que esté vacía o -1 si no hay posiciones vacías o si hubo un error*/
int estructura_buscarIndiceVacio(Estructura* pEstructura, int limite)
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
 * brief Busca la posición donde la estructura ESTRUCTURA y otra estructura tengan el mismo ID
 * \param Estructura* pEstructura: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena pESTRUCTURA
 * \param int id: ID que va a ser comparado con el ID de ESTRUCTURA
 * \return Retora la posición donde los IDs sean iguales o -1 en caso de error*/
int estructura_buscarPorId(Estructura* pEstructura, int limite, int id)
{
	int retorno = -1;

	if(pEstructura != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pEstructura[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

/**
 * brief Busca dentro de pESTRUCTURA si hay por lo menos un dato cargado
 * \param Estructura* pEstructura: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 1 si hay aunque sea una ESTRUCTURA, 0 si no hay ninguna o -1 en caso de error*/
int estructura_buscar(Estructura* pEstructura, int limite)
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
