#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compra.h"
#include "utn.h"

/**
 * brief Inicia los valores de todas las compras a valores vacíos
 * \param Compra* pCompra: Cadena que contiene todas las compras y va a ser objetivo de la función
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) si pudo iniciar los valores o -1 (ERROR) si no*/
int compra_inicializar(Compra* pCompra, int limite)
{
	int retorno = -1;

	if(pCompra != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			pCompra[i].idCompra = 0;
			strncpy(pCompra[i].direccion, "", sizeof(pCompra[i].direccion));
			strncpy(pCompra[i].color, "", sizeof(pCompra[i].color));
			pCompra[i].cantBarbijos = 0;
			pCompra[i].importe = 0;
			pCompra[i].estado = VACIO;
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Agrega datos a la cadena pCompra
 * \param Compra* pCompra: Cadena que va a ser objetivo de la función
 * \param int limite: Limite o tamaño de la cadena*/
void compra_harcodeo(Compra* pCompra, int limite)
{
	int idCompra[7] = {1, 2, 3, 4, 5, 6, 7};
	int idCliente[7] = {1, 1, 1, 2, 2, 3, 3};
	char direccion[7][TAM_DIRECCION] = {"Carranza 1410", "Cabrera 2020", "Bompland 1624", "Cabildo 282", "Fitz Roy 2121", "Cordoba 5234", "Santa Fe 4268"};
	char color[7][TAM_COLOR] = {"Negro", "Blanco", "Blanco", "Negro", "Verde", "Blanco", "Verde"};
	int cantBarbijos[7] = {3, 5, 9, 12, 2, 4, 7};
	int importe[7] = {0, 0, 0, 0, 0, 0, 0};

	for(int i = 0; i < limite; i++)
	{
		pCompra[i].idCompra = idCompra[i];
		pCompra[i].idCliente = idCliente[i];
		strncpy(pCompra[i].direccion, direccion[i], sizeof(pCompra[i].direccion));
		strncpy(pCompra[i].color, color[i], sizeof(pCompra[i].color));
		pCompra[i].cantBarbijos = cantBarbijos[i];
		pCompra[i].importe = importe[i];
		pCompra[i].estado = PENDIENTE_COBRAR;
	}
}

/**
 * brief Muestra el ID de una compra
 * \param Compra* pCompra: Cadena que va a ser recorrida
 * \param int indice: La posición donde está el ID a mostrar
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int compra_mostrarId(Compra* pCompra, int indice)
{
	int retorno = -1;

	if(pCompra != NULL && indice >= 0)
	{
		printf("\nEl ID de la nueva compra es %d\n", pCompra[indice].idCompra);
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Muestra una lista de todas las compras, pero sin el ID
 * \param Compra* pCompra: Cadena que va a ser recorrida
 * \param int limiteCompra: Limite o tamaño de la cadena pCompra
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int compra_mostrar(Compra* pCompra, int limite)
{
	int retorno = -1;

	if(pCompra != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pCompra[i].estado != VACIO)
			{
				printf("Dirección: %-15s Color: %-15s Cantidad de días: %-15d\n", pCompra[i].direccion, pCompra[i].color, pCompra[i].cantBarbijos);
			}
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Muestra todos los datos de las ENTIDADES incluyendo el id
 * \param Entidad* pEntidad: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int compra_mostrarConId(Compra* pCompra, int limite)
{
	int retorno = -1;

	if(pCompra != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pCompra[i].estado == PENDIENTE_COBRAR)
			{
				printf("ID: %-10d Dirección: %-15s Color: %-10s Cantidad de barbijos: %-15d\n", pCompra[i].idCompra, pCompra[i].direccion, pCompra[i].color, pCompra[i].cantBarbijos);
			}
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Busca dentro de pCompra una posición vacía
 * \param Compra* pCompra: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora la posición más cercana al 0 que esté vacía o -1 si no hay posiciones vacías o si hubo un error*/
int compra_buscarIndiceVacio(Compra* pCompra, int limite)
{
	int respuesta = -1;

	if(pCompra != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pCompra[i].estado == VACIO)
			{
				respuesta = i;
				break;
			}
		}
	}

	return respuesta;
}

/**
 * brief Busca la posición donde las estructuras Compra y Cliente tienen el mismo ID
 * \param Compra* pCompra: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \param int id: ID que va a ser comparado con el ID de Compra
 * \return Retora la posición donde los IDs sean iguales o -1 en caso de error*/
int compra_buscarPorId(Compra* pCompra, int limite, int idCliente)
{
	int retorno = -1;

	if(pCompra != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pCompra[i].estado != VACIO && pCompra[i].idCliente == idCliente)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

/**
 * brief Busca dentro de pCompra si hay por lo menos un dato cargado
 * \param Compra* pCompra: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 1 si hay aunque sea una compra, 0 si no hay ninguna o -1 en caso de error*/
int compra_buscar(Compra* pCompra, int limite)
{
	int respuesta = -1;

	if(pCompra != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i ++)
		{
			if(pCompra[i].estado != VACIO)
			{
				respuesta = 1;
				break;
			}
			respuesta = 0;
		}
	}

	return respuesta;
}
