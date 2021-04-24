/*
 * Producto.c
 *
 *  Created on: 19 abr. 2021
 *      Author: mateo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Producto.h"
#define CANT_PRODUCTOS 200
#define TAM_DESCRIPCION 400

static int mostrarLista(Producto* pArray, int limite);

/**
 * brief Inicia los valores de todos los productos a valores vacíos
 * \param Producto* pArray: Cadena que contiene todos los productos y va a ser objetivo de la función
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) si pudo iniciar los valores o -1 (ERROR) si no*/
int inicializarProductos(Producto* pArray, int limite)
{
	int retorno = -1;

	if(pArray != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			pArray[i].idProducto = 0;
			strncpy(pArray[i].descripcion, "", sizeof(pArray[i].descripcion));
			pArray[i].nacionalidad = 0;
			pArray[i].tipo = 0;
			pArray[i].precio = 0.0;
			pArray[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

int cargarProductos(Producto* pArray, int indice)
{
	int retorno = -1;
	char descrpcion[TAM_DESCRIPCION];
	int nacionalidad;
	int tipo;
	float precio;
	Producto bufferProducto;

	if(pArray != NULL && indice >= 0)
	{
		if(!utn_getTexto(descrpcion, TAM_DESCRIPCION, "\nIngrese una descripción sobre el producto: ", "\nError. Esa descripción no es válida") &&
		   !utn_getNumero(&nacionalidad, "\nIngrese la nacionalidad del producto (1. EEUU - 2. CHINA - 3. OTRO): ", "\nError. Debe elegir un número segun la nacionalidad", 1, 3, 3) &&
		   !utn_getNumero(&tipo, "\nIngrese el tipo del producto (1. IPHONE - 2. MAC - 3. IPAD - 4. ACCESORIOS): ", "\nError. Debe elegir un número segun el tipo", 1, 4, 3) &&
		   !utn_getPrecio(&precio, "\nIngrese el precio del producto: ", "\nError. Ese precio no es válido"))
		{
			bufferProducto.idProducto = indice + 1;
			strncpy(bufferProducto.descripcion, descrpcion, sizeof(bufferProducto.descripcion));
			bufferProducto.nacionalidad = nacionalidad;
			bufferProducto.tipo = tipo;
			bufferProducto.precio = precio;
			bufferProducto.isEmpty = 0;

			pArray[indice] = bufferProducto;
			retorno = 0;
		}
	}

	return retorno;
}

int eliminarProducto(Producto* pArray, int limite)
{
	int retorno = -1;
	int id;

	if(pArray != NULL)
	{
		if(!utn_getNumero(&id, "\nIngrese el ID del producto que desea eliminar: ", "\nError. Ese ID no existe", 1, CANT_PRODUCTOS, 3))
		{
			for(int i = 0; i < limite; i++)
			{
				if(id == pArray[i].idProducto)
				{
					pArray[i].idProducto = 0;
					strncpy(pArray[i].descripcion, "", sizeof(pArray[i].descripcion));
					pArray[i].nacionalidad = 0;
					pArray[i].tipo = 0;
					pArray[i].precio = 0.0;
					pArray[i].isEmpty = 1;

					retorno = 0;
					break;
				}
			}
		}
	}

	return retorno;
}

int modificarProducto(Producto* pArray, int limite)
{
	int retorno = -1;
	int id;
	char descripcion[TAM_DESCRIPCION];
	int nacionalidad;
	int tipo;
	float precio;

	if(pArray != NULL)
	{
		if(!utn_getNumero(&id, "\nIngrese el ID del producto que desea modificar: ", "\nError. Ese ID no existe", 1, CANT_PRODUCTOS, 3))
		{
			for(int i = 0; i < limite; i++)
			{
				if(id == pArray[i].idProducto)
				{
					if(!utn_getTexto(descripcion, TAM_DESCRIPCION, "\nIngrese una descripción sobre el producto: ", "\nError. Esa descripción no es válida") &&
					   !utn_getNumero(&nacionalidad, "\nIngrese la nacionalidad del producto (1. EEUU - 2. CHINA - 3. OTRO): ", "\nError. Debe elegir un número segun la nacionalidad", 1, 3, 3) &&
					   !utn_getNumero(&tipo, "\nIngrese el tipo del producto (1. IPHONE - 2. MAC - 3. IPAD - 4. ACCESORIOS): ", "\nError. Debe elegir un número segun el tipo", 1, 4, 3) &&
					   !utn_getPrecio(&precio, "\nIngrese el precio del producto: ", "\nError. Ese precio no es válido"))
					{
						pArray[i].idProducto = i + 1;
						strncpy(pArray[i].descripcion, descripcion, sizeof(pArray[i].descripcion));
						pArray[i].nacionalidad = nacionalidad;
						pArray[i].tipo = tipo;
						pArray[i].precio = precio;
						pArray[i].isEmpty = 0;

						retorno = 0;
					}

					retorno = 0;
					break;
				}
			}
		}
	}

	return retorno;
}

int ordenadoId(Producto* pArray, int limite)
{
	int retorno = -1;
	Producto auxiliar;
	int flagSwap = 0;

	if(pArray != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 0; i < limite - 1; i++)
			{
				if(pArray[i].idProducto < pArray[i + 1].idProducto)
				{
					auxiliar = pArray[i];
					pArray[i] = pArray[i + 1];
					pArray[i + 1] = auxiliar;
					flagSwap = 1;
				}
			}
		}while(flagSwap);

		mostrarLista(pArray, limite);
		retorno = 0;
	}

	return retorno;
}

int ordenadoPrecio(Producto* pArray, int limite)
{
	int retorno = -1;
	Producto auxiliar;
	int flagSwap = 0;

	if(pArray != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 0; i < limite - 1; i++)
			{
				if(pArray[i].precio > pArray[i + 1].precio)
				{
					auxiliar = pArray[i];
					pArray[i] = pArray[i + 1];
					pArray[i + 1] = auxiliar;
					flagSwap = 1;
				}
			}
		}while(flagSwap);

		mostrarLista(pArray, limite);
		retorno = 0;
	}

	return retorno;
}

int ordenadoDescripcion(Producto* pArray, int limite)
{
	int retorno = -1;
	Producto auxiliar;
	int flagSwap = 0;

	if(pArray != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 0; i < limite - 1; i++)
			{
				if(strcmp(pArray[i].descripcion, pArray[i + 1].descripcion) > 0)
				{
					auxiliar = pArray[i];
					pArray[i] = pArray[i + 1];
					pArray[i + 1] = auxiliar;
					flagSwap = 1;
				}
			}
		}while(flagSwap);

		mostrarLista(pArray, limite);
		retorno = 0;
	}

	return retorno;
}

static int mostrarLista(Producto* pArray, int limite)
{
	int retorno = -1;

	if(pArray != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pArray[i].isEmpty)
			{
				printf("\nID: %d - Descripción: %s - Nacionalidad: %d - Tipo: %d - Precio: %.2f", pArray[i].idProducto, pArray[i].descripcion, pArray[i].nacionalidad, pArray[i].tipo, pArray[i].precio);
			}
		}
		retorno = 0;
	}

	return retorno;
}

int buscarIndiceVacio(Producto* pArray, int limite)
{
	int respuesta = -1;

	if(pArray != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pArray[i].isEmpty)
			{
				respuesta = i;
				break;
			}
		}
	}

	return respuesta;
}
