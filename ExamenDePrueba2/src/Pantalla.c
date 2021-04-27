/*
 * Razas.c
 *
 *  Created on: 20 abr. 2021
 *      Author: mateo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Pantalla.h"
#define CANT_PANTALLAS 100
#define CANT_CONTRATACIONES 1000

/**
 * brief Inicia los valores de todas las pantallas a valores vacíos
 * \param Pantalla* pPantalla: Cadena que contiene todas las pantallas y va a ser objetivo de la función
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) si pudo iniciar los valores o -1 (ERROR) si no*/
int inicializarPantalla(Pantalla* pPantalla, int limite)
{
	int retorno = -1;

	if(pPantalla != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			pPantalla[i].idPantalla = 0;
			strncpy(pPantalla[i].nombre, "", sizeof(pPantalla[i].nombre));
			pPantalla[i].precioPorDia = 0.0;
			strncpy(pPantalla[i].direccion, "", sizeof(pPantalla[i].direccion));
			strncpy(pPantalla[i].tipo, "", sizeof(pPantalla[i].tipo));
			pPantalla[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Pide al usuario que cargue los datos de una pantalla
 * \param Pantalla* pPantalla: Cadena donde se guardarán los valores
 * \param int indice: La posición donde van a ser guardados los datos
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int altaPantalla(Pantalla* pPantalla, int indice)
{
	int retorno = -1;
	Pantalla bufferPantalla;

	if(pPantalla != NULL && indice >= 0)
	{
		if(!utn_getTexto(bufferPantalla.nombre, TAM_DESCRIPCION, "Ingrese el nombre:\n", "Error. El nombre no es válido\n") &&
		   !utn_getPrecio(&bufferPantalla.precioPorDia, "Ingrese el precio por día:\n", "Error. Ese precio no es válido\n") &&
		   !utn_getDireccion(bufferPantalla.direccion, "Ingrese la dirección (sin la altura): \n", "Ingrese la altura: \n", "Error. Esa no es una dirección válida\n", "Error. Esa no es una altura válida\n") &&
		   !utn_getTexto(bufferPantalla.tipo, TAM_TIPO, "Ingrese el tipo (LCD/LED):\n", "Error. Ese tipo no es válido\n") &&
		   (strcmp(bufferPantalla.tipo, "LCD") == 0 || strcmp(bufferPantalla.tipo, "LED") == 0))
		{
			bufferPantalla.idPantalla = indice + 1;
			bufferPantalla.isEmpty = 0;
			pPantalla[indice] = bufferPantalla;
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
 * brief Pide al usuario que modifique los valores de una pantalla
 * \param Pantalla* pPantalla: Cadena donde se guardarán los nuevos valores
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int modificarPantalla(Pantalla* pPantalla, int limite)
{
	int retorno = -1;
	Pantalla bufferPantalla;
	int id;

	if(pPantalla != NULL && limite > 0)
	{
		mostrarPantallaId(pPantalla, limite);
		if(!utn_getNumero(&id, "Ingrese el ID de la pantalla a modificar\n", "Error. Ese ID no existe\n", 1, CANT_PANTALLAS, 3))
		{
			for(int i = 0; i < CANT_PANTALLAS; i++)
			{
				if(id == pPantalla[i].idPantalla)
				{
					if(!utn_getTexto(bufferPantalla.nombre, TAM_DESCRIPCION, "Ingrese el nombre del archivo: \n", "Error. Ese no es un nombre de archivo válido\n") &&
					   !utn_getPrecio(&bufferPantalla.precioPorDia, "Ingrese el precio por día:\n", "Error. Ese precio no es válido\n") &&
					   !utn_getDireccion(bufferPantalla.direccion, "Ingrese la dirección (sin la altura): \n", "Ingrese la altura: \n", "Error. Esa no es una dirección válida\n", "Error. Esa no es una altura válida\n") &&
					   !utn_getTexto(bufferPantalla.tipo, TAM_TIPO, "Ingrese el tipo (LCD/LED):\n", "Error. Ese tipo no es válido\n") &&
					   (strcmp(bufferPantalla.tipo, "LCD") == 0 || strcmp(bufferPantalla.tipo, "LED") == 0))
					{
						bufferPantalla.isEmpty = 0;
						pPantalla[i] = bufferPantalla;
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
 * brief Muestra todos los datos de las pantallas excepto el id
 * \param Pantalla* pPantalla: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int mostrarPantalla(Pantalla* pPantalla, int limite)
{
	int retorno = -1;

	if(pPantalla != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pPantalla[i].isEmpty)
			{
				printf("Nombre: %-15s Tipo: %-10s Dirección: %-15s Precio/día: %-10.2f\n", pPantalla[i].nombre, pPantalla[i].tipo, pPantalla[i].direccion, pPantalla[i].precioPorDia);
			}
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Muestra todos los datos de las pantallas incluyendo el id
 * \param Pantalla* pPantalla: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int mostrarPantallaId(Pantalla* pPantalla, int limite)
{
	int retorno = -1;

	if(pPantalla != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pPantalla[i].isEmpty)
			{
				printf("ID: %-10d Nombre: %-15s Tipo: %-10s Dirección: %-15s Precio/día: %-10.2f\n", pPantalla[i].idPantalla, pPantalla[i].nombre, pPantalla[i].tipo, pPantalla[i].direccion, pPantalla[i].precioPorDia);
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
 * brief Busca dentro de pPantalla una posición vacía
 * \param Pantalla* pPantalla: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora la posición más cercana al 0 que esté vacía o -1 si no hay posiciones vacías o si hubo un error*/
int buscarIndiceVacioPantalla(Pantalla* pPantalla, int limite)
{
	int respuesta = -1;

	if(pPantalla != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pPantalla[i].isEmpty)
			{
				respuesta = i;
				break;
			}
		}
	}

	return respuesta;
}

/**
 * brief Busca la posición donde la estructura Pantalla y otra estructura tengan el mismo ID
 * \param Pantalla* pPantalla: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \param int id: ID que va a ser comparado con el ID de Pantalla
 * \return Retora la posición donde los IDs sean iguales o -1 en caso de error*/
int buscarIdPantalla(Pantalla* pPantalla, int limite, int id)
{
	int retorno = -1;

	if(pPantalla != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pPantalla[i].idPantalla == id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

/**
 * brief Busca dentro de pPantalla si hay por lo menos un dato cargado
 * \param Pantalla* pPantalla: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 1 si hay aunque sea una pantalla, 0 si no hay ninguna o -1 en caso de error*/
int buscarPantalla(Pantalla* pPantalla, int limite)
{
	int respuesta = -1;

	if(pPantalla != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i ++)
		{
			if(!pPantalla[i].isEmpty)
			{
				respuesta = 1;
				break;
			}
			respuesta = 0;
		}
	}

	return respuesta;
}
