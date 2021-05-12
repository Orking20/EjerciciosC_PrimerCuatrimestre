/*
 * Relacion.c
 *
 *  Created on: 28 abr. 2021
 *      Author: mateo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Producto.h"
#include "Relacion.h"
#include "Nacionalidad.h"


/**
 * brief Pide al usuario que borre una Nacionalidad y todas sus ProductoS mediante el ID de la Nacionalidad
 * \param Nacionalidad* pNacionalidad: Cadena donde se borrarán los datos
 * \param Producto* pProducto: Cadena donde se borrarán las ProductoS relacionadas con la Nacionalidad escogida
 * \param int limiteNacionalidad: Limite o tamaño de la cadena pNacionalidad
 * \param int limiteProducto: Limite o tamaño de la cadena pProducto
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int Nacionalidad_baja(Nacionalidad* pNacionalidad, Producto* pProducto, int limiteNacionalidad, int limiteProducto)
{
	int retorno = -1;
	int numeroId;
	int indice;

	if(pNacionalidad != NULL && pProducto != NULL && limiteNacionalidad > 0 && limiteProducto > 0)
	{
		if(Nacionalidad_buscar(pNacionalidad, limiteNacionalidad) == 1)
		{
			Nacionalidad_mostrarConId(pNacionalidad, limiteNacionalidad);
			if(!utn_getNumero(&numeroId, "\nIngrese el ID de la pantalla a eliminar: ", "\nError. Ese ID no es válido", 1, limiteNacionalidad, 3))
			{
				for(int i = 0; i < limiteNacionalidad; i++)
				{
					if(numeroId == pNacionalidad[i].id)
					{
						if(Producto_buscar(pProducto, limiteProducto) == 1)
						{
							for(int j = 0; j < limiteProducto; j++)
							{
								indice = Nacionalidad_buscarPorId(pNacionalidad, limiteNacionalidad, pProducto[j].id);
								if(numeroId == pProducto[indice].id)
								{
									pProducto[indice].id = 0;
									strncpy(pProducto[indice].cadena, "", sizeof(pProducto[indice].cadena));
									pProducto[indice].numero = 0;
									pProducto[indice].isEmpty = 1;
								}
							}
						}
						pNacionalidad[i].id = 0;
						strncpy(pNacionalidad[i].cadena, "", sizeof(pNacionalidad[i].cadena));
						pNacionalidad[i].numero = 0;
						pNacionalidad[i].isEmpty = 1;
						retorno = 0;
						break;
					}
				}
				if(retorno == -1)
				{
					printf("No existe ninguna Nacionalidad con ese ID\n");
				}
			}
			else
			{
				printf("Ingresaste un dato inválido.\n");
			}
		}
		else
		{
			printf("Todavía no ingresaste ninguna Nacionalidad\n");
		}
	}

	return retorno;
}

/**
 * brief Pide al usuario que borre una Producto ingresando su CADENA
 * \param Producto* pProducto: Cadena donde se borrarán los datos
 * \param Nacionalidad* pNacionalidad: Cadena que se usa para mostrar sus datos antes de borrar los de la Producto
 * \param int limiteProducto: Limite o tamaño de la cadena pProducto
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int Producto_baja(Producto* pProducto, Nacionalidad* pNacionalidad, int limiteProducto, int limiteNacionalidad)
{
	int retorno = -1;
	int id;
	char cadena[TAM_CADENA];
	int indiceNacionalidad;
	int flagCuit = 0;
	Producto bufferProducto;

	if(pProducto != NULL && pNacionalidad != NULL && limiteProducto > 0 && limiteNacionalidad > 0)
	{
		if(Producto_buscar(pProducto, limiteProducto) == 1)
		{
			if(!utn_getTexto(cadena, TAM_CADENA, "\nIngrese el NUMERO del cliente", "\nError. Ese NUMERO no es válido"))
			{
				for(int i = 0; i < limiteProducto; i++)
				{
					if(strcmp(pProducto[i].cadena, cadena) == 0)
					{
						flagCuit = 1;
						indiceNacionalidad = Nacionalidad_buscarPorId(pNacionalidad, limiteNacionalidad, pProducto[i].id);
						printf("\nID: %-10d CADENA: %-10s CADENA: %-10s CADENA: %-15s\n", pNacionalidad[indiceNacionalidad].id, pNacionalidad[indiceNacionalidad].cadena, pNacionalidad[indiceNacionalidad].cadena, pNacionalidad[indiceNacionalidad].cadena);

						if(!utn_getNumero(&id, "\nIngrese el ID de la Nacionalidad a modificar: ", "\nError. Ese ID no existe", 1, limiteNacionalidad, 3))
						{
							for(int i = 0; i < limiteProducto; i++)
							{
								if(id == pProducto[i].id)
								{
									bufferProducto.numero = 0;
									strncpy(bufferProducto.cadena, "", sizeof(bufferProducto.cadena));
									bufferProducto.id = 0;
									bufferProducto.isEmpty = 1;

									pProducto[i] = bufferProducto;
									retorno = 0;
									break;
								}
							}
							if(retorno == -1)
							{
								printf("\nNo existe ninguna Nacionalidad con ese ID");
							}
						}
						else
						{
							printf("\nError. Ingresaste un dato inválido");
						}
					}
				}
				if(flagCuit == 0)
				{
					printf("\nEsa CADENA no coincide con ninguna en el registro");
				}
			}
		}
		else
		{
			printf("\nError. Todavía no se ingresó ninguna Producto. Primero tiene que dar de alta una Producto para borrarla.");
		}
	}

	return retorno;
}

/**
 * brief Muestra una lista de todas las ProductoS, pero sin el ID y con algún dato de la Nacionalidad
 * \param Producto* pProducto: Cadena que va a ser recorrida
 * \param Nacionalidad* pNacionalidad: Cadena que sirve solo para mostrar el DATO que está en Nacionalidad
 * \param int limiteProducto: Limite o tamaño de la cadena pProducto
 * \param int limiteNacionalidad: Limite o tamaño de la cadena pNacionalidad
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int Producto_mostrar(Producto* pProducto, Nacionalidad* pNacionalidad, int limiteProducto, int limiteNacionalidad)
{
	int retorno = -1;
	int indiceNacionalidad;

	if(pProducto != NULL && pNacionalidad != NULL && limiteProducto > 0 && limiteNacionalidad > 0)
	{
		for(int i = 0; i < limiteProducto; i++)
		{
			indiceNacionalidad = Nacionalidad_buscarPorId(pNacionalidad, limiteNacionalidad, pProducto[i].id);
			if(!pProducto[i].isEmpty)
			{
				printf("CADENA: %-15s CADENA: %-15s NÚMERO: %-15d CADENA: %-15s\n", pNacionalidad[indiceNacionalidad].cadena, pProducto[i].cadena, pProducto[i].numero, pProducto[i].cadena);
			}
		}
		retorno = 0;
	}

	return retorno;
}

/*int ordenarPorPeso(Producto* pProducto, Nacionalidad* pNacionalidad, int limite)
{
	int retorno = -1;
	int flagSwap = 0;
	Producto auxiliar;
	int peso1;
	int peso2;

	if(pProducto != NULL && pNacionalidad != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 0; i < limite - 1; i++)
			{
				peso1 = getPeso(pNacionalidad, pProducto, i, limite);
				peso2 = getPeso(pNacionalidad, pProducto, i + 1, limite);
				if(peso1 != -1 && peso2 != -1 && peso1 > peso2)
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

static int getPeso(Nacionalidad* pNacionalidad, Producto* pProducto, int indice, int limiteNacionalidad)
{
	int retorno = -1;
	int indiceNacionalidad;

	if(pNacionalidad != NULL && pProducto != NULL && indice >= 0 && limiteNacionalidad > 0)
	{
		indiceNacionalidad = Nacionalidad_buscarPorId(pNacionalidad, limiteNacionalidad, pProducto[indice].id);

		return pNacionalidad[indiceNacionalidad].tamanio;
	}

	return retorno;
}*/
