/*
 * Producto.c
 *
 *  Created on: 15 abr. 2021
 *      Author: mateo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Producto.h"
#define CANT_PRODUCTOS 200
#define TAM_NOMBRE 50
#define TAM_DESCRIPCION 200

/**
 * \brief Inicializa las variables dentro de Producto para que no tengan basura
 * \param Producto* pProducto: Cadena que va a ser analizada
 * \param int limite: Limite o tamaño de la cadena
 * \return Retorna 0 (EXITO) o -1 (ERROR)*/
int inicializarProductos(Producto* pProducto, int limite)
{
	int retorno = -1;

	if(pProducto != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			strncpy(pProducto[i].nombre, "", sizeof(pProducto[i].nombre));
			strncpy(pProducto[i].descripcion, "", sizeof(pProducto[i].descripcion));
			pProducto[i].precio = 0;
			pProducto[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * \brief Le pide al usuario que cargue un producto al array
 * \param Producto* pProducto: Cadena que va a ser analizada
 * \param int limite: Limite o tamaño de la cadena
 * \param int indice: Posición del array donde se cargará el producto
 * \return Retorna 0 (EXITO) o -1 (ERROR)*/
int cargarProductos(Producto* pProducto, int indice)
{
	int retorno = -1;
	char nombre[TAM_NOMBRE];
	char descripcion[TAM_DESCRIPCION];
	float precio;
	Producto bufferProducto;

	if(pProducto != NULL && indice >= 0)
	{
		if(utn_getNombre(nombre, TAM_NOMBRE, "Ingrese el nombre del producto: \n", "Error. Ese no es un nombre válido\n") == 0)
		{
			if(utn_getTexto(descripcion, TAM_DESCRIPCION, "Ingrese una descripción del producto: \n", "Error.\n") == 0)
			{
				if(utn_getDecimal(&precio, "Ingrese el precio: \n", "Error.\n", 1, 100000000, 3) == 0)
				{
					bufferProducto.id = indice + 1;
					strncpy(bufferProducto.nombre, nombre, sizeof(bufferProducto.nombre));
					strncpy(bufferProducto.descripcion, descripcion, sizeof(bufferProducto.descripcion));
					bufferProducto.precio = precio;
					bufferProducto.isEmpty = 0;

					pProducto[indice] = bufferProducto;
					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

/**
 * \brief Muestra todos los productos en el array
 * \param Producto* pProducto: Cadena que va a ser analizada
 * \param int limite: Limite o tamaño de la cadena
 * \return Retorna 0 (EXITO) o -1 (ERROR)*/
int mostrarProductos(Producto* pProducto, int limite)
{
	int retorno = -1;

	if(pProducto != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pProducto[i].isEmpty == 0)
			{
				printf("ID: %d - Nombre: %s - Descripción: %s - Precio: %.2f\n", pProducto[i].id, pProducto[i].nombre, pProducto[i].descripcion, pProducto[i].precio);
			}
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * \brief Busca en el array el primer indice vacío
 * \param Producto* pProducto: Cadena que va a ser analizada
 * \param int limite: Limite o tamaño de la cadena
 * \return Retorna el primer indice vacío o -1 en caso de error o si ya está lleno el array*/
int buscarIndiceVacio(Producto* pProducto, int limite)
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
