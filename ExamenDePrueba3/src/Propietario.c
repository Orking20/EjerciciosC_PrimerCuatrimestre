/*
 * Razas.c
 *
 *  Created on: 20 abr. 2021
 *      Author: mateo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Propietario.h"
#include "utn.h"
#define CANT_PROPIETARIO 100
#define CANT_AUTOMOVIL 1000

/**
 * brief Inicia los valores de todas los propietarios a valores vacíos
 * \param Propietario* pPropietario: Cadena que contiene todos los propietario y va a ser objetivo de la función
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) si pudo iniciar los valores o -1 (ERROR) si no*/
int inicializarPropietario(Propietario* pPropietario, int limite)
{
	int retorno = -1;

	if(pPropietario != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			pPropietario[i].idPropietario = 0;
			strncpy(pPropietario[i].nombreApellido, "", sizeof(pPropietario[i].nombreApellido));
			strncpy(pPropietario[i].direccion, "", sizeof(pPropietario[i].direccion));
			strncpy(pPropietario[i].numTarjeta, "", sizeof(pPropietario[i].numTarjeta));
			pPropietario[i].isEmpty = 1;
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
int altaPropietario(Propietario* pPropietario, int indice)
{
	int retorno = -1;
	Propietario bufferPropietario;

	if(pPropietario != NULL && indice >= 0)
	{
		if(!utn_getTexto(bufferPropietario.nombreApellido, TAM_NOMBRE, "Ingrese el nombre y apellido:\n", "Error. El nombre y apellido no es válido\n") &&
		   !utn_getDireccion(bufferPropietario.direccion, "Ingrese la dirección (sin la altura): \n", "Ingrese la altura: \n", "Error. Esa no es una dirección válida\n", "Error. Esa no es una altura válida\n") &&
		   !utn_getTarjetaCredito(bufferPropietario.numTarjeta, "Ingrese el número de tarjeta de crédito:\n", "Error. Ese número de tarjeta de crédito no es válido\n"))
		{
			bufferPropietario.idPropietario = indice + 1;
			bufferPropietario.isEmpty = 0;
			pPropietario[indice] = bufferPropietario;
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
int modificarPropietario(Propietario* pPropietario, int limite)
{
	int retorno = -1;
	Propietario bufferPropietario;
	int id;

	if(pPropietario != NULL && limite > 0)
	{
		mostrarPantallaId(pPropietario, limite);
		if(!utn_getNumero(&id, "Ingrese el ID del propietario a modificar\n", "Error. Ese ID no existe\n", 1, CANT_PROPIETARIO, 3))
		{
			for(int i = 0; i < CANT_PROPIETARIO; i++)
			{
				if(id == pPropietario[i].idPropietario)
				{
					if(!utn_getTexto(bufferPropietario.nombreApellido, TAM_NOMBRE, "Ingrese el nombre y apellido: \n", "Error. Ese no es un nombre y apellido válido\n") &&
					   !utn_getDireccion(bufferPropietario.direccion, "Ingrese la dirección (sin la altura): \n", "Ingrese la altura: \n", "Error. Esa no es una dirección válida\n", "Error. Esa no es una altura válida\n") &&
					   !utn_getTarjetaCredito(bufferPropietario.numTarjeta, "Ingrese el número de tarjeta de crédito:\n", "Error. Ese número de tarjeta de crédito no es válido\n"))
					{
						bufferPropietario.isEmpty = 0;
						pPropietario[i] = bufferPropietario;
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
int mostrarPropietario(Propietario* pPropietario, int limite)
{
	int retorno = -1;

	if(pPropietario != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pPropietario[i].isEmpty)
			{
				printf("Nombre y apellido: %-15s Dirección: %-10s Número de tarjeta: %-15s\n", pPropietario[i].nombreApellido, pPropietario[i].direccion, pPropietario[i].numTarjeta);
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
int mostrarPropietarioId(Propietario* pPropietario, int limite)
{
	int retorno = -1;

	if(pPropietario != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pPropietario[i].isEmpty)
			{
				printf("ID: %-10d Nombre: %-15s Dirección: %-10s Número de tarjeta: %-15s\n", pPropietario[i].idPropietario, pPropietario[i].nombreApellido, pPropietario[i].direccion, pPropietario[i].numTarjeta);
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
int buscarIndiceVacioPropietario(Propietario* pPropietario, int limite)
{
	int respuesta = -1;

	if(pPropietario != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pPropietario[i].isEmpty)
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
int buscarIdPropietario(Propietario* pPropietario, int limite, int id)
{
	int retorno = -1;

	if(pPropietario != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pPropietario[i].idPropietario == id)
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
int buscarPropietario(Propietario* pPropietario, int limite)
{
	int respuesta = -1;

	if(pPropietario != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i ++)
		{
			if(!pPropietario[i].isEmpty)
			{
				respuesta = 1;
				break;
			}
			respuesta = 0;
		}
	}

	return respuesta;
}
