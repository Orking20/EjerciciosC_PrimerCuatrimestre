/*
 * Producto.c
 *
 *  Created on: 28 abr. 2021
 *      Author: mateo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Producto.h"

/**
 * brief Inicia los valores de todos los datos de la Producto a valores vacíos
 * \param Producto* pProducto: Cadena que contiene todos los campos y va a ser objetivo de la función
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) si pudo iniciar los valores o -1 (ERROR) si no*/
int Producto_inicializar(Producto* pProducto, int limite)
{
	int retorno = -1;

	if(pProducto != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			pProducto[i].idProducto = 0;
			strncpy(pProducto[i].descripcion, "", sizeof(pProducto[i].descripcion));
			pProducto[i].idNacionalidad = 0;
			pProducto[i].idTipo = 0;
			pProducto[i].precioPorUnidad = 0.0;
			pProducto[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Agrega datos a la cadena pProducto
 * \param Producto* pProducto: Cadena que va a ser objetivo de la función
 * \param int limite: Limite o tamaño de la cadena*/
void Producto_harcodeo(Producto* pProducto, int limite)
{
	int id[7] = {1, 2, 3, 4, 5, 6, 7};
	char cadena[7][TAM_CADENA] = {"Pipo", "Lolo", "Iris", "Negro", "Sara", "Olivia", "Uclides"};
	int numero[7] = {13, 9, 7, 8, 4, 16, 3};
	int isEmpty[7] = {0, 0, 0, 0, 0, 0, 0};

	for(int i = 0; i < limite; i++)
	{
		pProducto[i].idProducto = id[i];
		strncpy(pProducto[i].descripcion, cadena[i], sizeof(pProducto[i].descripcion));
		pProducto[i].numero = numero[i];
		pProducto[i].isEmpty = isEmpty[i];
	}
}

/**
 * brief Pide al usuario que cargue los datos de una Producto
 * \param Producto* pProducto: Cadena donde se guardarán los valores
 * \param int indice: La posición donde van a ser guardados los datos
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int Producto_alta(Producto* pProducto, int indice)
{
	int retorno = -1;
	Producto bufferProducto;

	if(pProducto != NULL && indice >= 0)
	{
		if(!utn_getTexto(bufferProducto.cadena, TAM_CADENA, "\nIngrese la CADENA: ", "\nError. La CADENA no es válida ") &&
		   !utn_getNumero(&bufferProducto.numero, "\nIngrese un NÚMERO: ", "\nError. Ese NÚMERO no es válido", 0, 100, 3))
		{
			bufferProducto.id = indice + 1;
			bufferProducto.isEmpty = 0;
			pProducto[indice] = bufferProducto;
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
 * brief Pide al usuario que modifique los valores de una Producto
 * \param Producto* pProducto: Cadena donde se guardarán los nuevos valores
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int Producto_modificar(Producto* pProducto, int limite)
{
	int retorno = -1;
	Producto bufferProducto;
	int idProducto;

	if(pProducto != NULL && limite > 0)
	{
		Producto_mostrarConId(pProducto, limite);
		if(!utn_getNumero(&idProducto, "\nIngrese el ID de la Producto a modificar\n", "\nError. Ese ID no existe\n", 1, limite, 3))
		{
			for(int i = 0; i < limite; i++)
			{
				if(idProducto == pProducto[i].id)
				{
					if(!utn_getTexto(bufferProducto.cadena, TAM_CADENA, "\nIngrese la CADENA: ", "\nError. La CADENA no es válida") &&
					   !utn_getTarjetaCredito(bufferProducto.cadena, "\nIngrese la CADENA: ", "\nError. La CADENA no es válida"))
					{
						bufferProducto.isEmpty = 0;
						pProducto[i] = bufferProducto;
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
 * brief Ordena la lista pProducto según el NÚMERO de mayor a menor
 * \param Producto* pProducto: Cadena que va a ser ordenada
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) si pudo ordenar correctamente o -1 (ERROR) si no*/
int ordenarPorNumero(Producto* pProducto, int limite)
{
	int retorno = -1;
	int flagSwap = 0;
	Producto auxiliar;

	if(pProducto != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 0; i < limite - 1; i++)
			{
				if(pProducto[i].numero > pProducto[i + 1].numero)
				{
					auxiliar = pProducto[i];
					pProducto[i] = pProducto[i + 1];
					pProducto[i + 1] = auxiliar;
					flagSwap = 1;
				}
			}
		}while(flagSwap);

		retorno = 0;
	}

	return retorno;
}

/**
 * brief Muestra una lista de todas las ProductoS incluyendo el ID
 * \param Contratacion* pContratacion: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena pProducto
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int Producto_mostrarId(Producto* pProducto, int limite)
{
	int retorno = -1;

	if(pProducto != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pProducto[i].isEmpty)
			{
				printf("ID: %-10d CADENA: %-15s CADENA: %-15s NÚMERO: %-15d\n", pProducto[i].id, pProducto[i].cadena, pProducto[i].cadena, pProducto[i].numero);
			}
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Muestra todos los datos de las ProductoES incluyendo el id
 * \param Producto* pProducto: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int Producto_mostrarConId(Producto* pProducto, int limite)
{
	int retorno = -1;

	if(pProducto != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pProducto[i].isEmpty)
			{
				printf("ID: %-10d CADENA: %-15s CADENA: %-10s CADENA: %-15s\n", pProducto[i].id, pProducto[i].cadena, pProducto[i].cadena, pProducto[i].cadena);
			}
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Busca dentro de pProducto una posición vacía
 * \param Producto* pProducto: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora la posición más cercana al 0 que esté vacía o -1 si no hay posiciones vacías o si hubo un error*/
int Producto_buscarIndiceVacio(Producto* pProducto, int limite)
{
	int respuesta = -1;

	if(pProducto != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pProducto[i].isEmpty)
			{
				respuesta = i;
				break;
			}
		}
	}

	return respuesta;
}

/**
 * brief Busca la posición donde la Producto Producto y otra Producto tengan el mismo ID
 * \param Producto* pProducto: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena pProducto
 * \param int id: ID que va a ser comparado con el ID de Producto
 * \return Retora la posición donde los IDs sean iguales o -1 en caso de error*/
int Producto_buscarPorId(Producto* pProducto, int limite, int id)
{
	int retorno = -1;

	if(pProducto != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pProducto[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

/**
 * brief Busca dentro de pProducto si hay por lo menos un dato cargado
 * \param Producto* pProducto: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 1 si hay aunque sea una Producto, 0 si no hay ninguna o -1 en caso de error*/
int Producto_buscar(Producto* pProducto, int limite)
{
	int respuesta = -1;

	if(pProducto != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pProducto[i].isEmpty)
			{
				respuesta = 1;
				break;
			}
			respuesta = 0;
		}
	}

	return respuesta;
}
