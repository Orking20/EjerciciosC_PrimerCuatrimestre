/*
 * Relacion.c
 *
 *  Created on: 23 abr. 2021
 *      Author: mateo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Contratacion.h"
#include "Pantalla.h"
#include "Relacion.h"
#define CANT_PANTALLAS 100
#define CANT_CONTRATACIONES 1000

//static int getPeso(Pantalla* pPantalla, Contratacion* pContratacion, int indice, int limitePant);

/**
 * brief Pide al usuario que cargue los datos de una contratación
 * \param Contratacion* pContratacion: Cadena donde se guardarán los datos
 * \param Pantalla* pPantalla: Cadena para que se conecten los datos de una estructura con otra
 * \param int indice: La posición donde van a ser guardados los datos
 * \param int limitePant: Limite de posiciones de pantallas
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int contratacion_alta(Contratacion* pContratacion, Pantalla* pPantalla, int indice, int limitePant)
{
	int retorno = -1;
	Contratacion bufferContratacion;
	int idPantalla;

	if(pContratacion != NULL && pPantalla != NULL && indice >= 0 && limitePant > 0)
	{
		if(pantalla_buscar(pPantalla, limitePant) == 1)
		{
			pantalla_mostrarConId(pPantalla, limitePant);
			if(!utn_getNumero(&idPantalla, "Ingrese el ID de la pantalla: \n", "Error. Ese ID es inválido\n", 1, CANT_PANTALLAS, 3))
			{
				if(!utn_getNombre(bufferContratacion.nombreArchivo, "Ingrese el nombre del archivo:\n", "Error. Ese no es un nombre de archivo válido\n") &&
				   !utn_getCuit(bufferContratacion.cuitCliente, "Ingrese el CUIT:\n", "Error. Ese CUIT es inválido\n") &&
				   !utn_getNumero(&bufferContratacion.cantDias, "Ingrese la cantidad de días de la contratación:\n", "Error. Ese número es inválido\n", 1, 365, 3))
				{

					for(int i = 0; i < limitePant; i++)
					{
						if(idPantalla == pPantalla[i].idPantalla)
						{
							bufferContratacion.idPantalla = idPantalla;
							bufferContratacion.idContratacion = indice + 1;
							bufferContratacion.isEmpty = 0;
							pContratacion[indice] = bufferContratacion;
							retorno = 0;
							break;
						}
					}
					if(retorno == -1)
					{
						printf("No existe ninguna pantalla con ese ID\n");
					}
				}
			}
			else
			{
				printf("Ingresaste un dato inválido.\n");
			}
		}
		else
		{
			printf("Error. Todavía no se ingresó ninguna pantalla. Primero tiene que dar de alta una pantalla para añadir una publicación.\n");
		}
	}

	return retorno;
}

/**
 * brief Pide al usuario que modifique los datos de una contratación
 * \param Contratacion* pContratacion: Cadena donde se guardarán los nuevos datos
 * \param Pantalla* pPantalla: Cadena para que se conecten los datos de una estructura con otra
 * \param int limite: Limite de posiciones de contrataciones
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int contratacion_modificar(Contratacion* pContratacion, Pantalla* pPantalla, int limiteCont)
{
	int retorno = -1;
	int id;
	char cuit[TAM_CUIT];
	int indicePant;
	int flagCuit = 0;

	if(pContratacion != NULL && pPantalla != NULL && limiteCont > 0)
	{
		if(contratacion_buscar(pContratacion, limiteCont) == 1)
		{
			if(!utn_getCuit(cuit, "Ingrese el CUIT del cliente\n", "Error. Ese CUIT es inválido\n"))
			{
				for(int i = 0; i < limiteCont; i++)
				{
					if(strcmp(pContratacion[i].cuitCliente, cuit) == 0)
					{
						flagCuit = 1;
						indicePant = pantalla_buscarId(pPantalla, CANT_PANTALLAS, pContratacion[i].idPantalla);
						printf("ID: %-10d Nombre pantalla: %-10s Tipo: %-10s Dirección: %-15s Precio: %-10f\n", pPantalla[indicePant].idPantalla, pPantalla[indicePant].nombre, pPantalla[indicePant].tipo, pPantalla[indicePant].direccion, pPantalla[indicePant].precioPorDia);

						if(!utn_getNumero(&id, "Ingrese el ID de la pantalla a modificar\n", "Error. Ese ID no existe\n", 1, CANT_PANTALLAS, 3))
						{
							for(int i = 0; i < limiteCont; i++)
							{
								if(id == pContratacion[i].idContratacion)
								{
									if(!utn_getNumero(&pContratacion[i].cantDias, "Ingrese la nueva cantidad de días de la contratación:\n", "Error. Ese número es inválido\n", 1, 365, 3))
									{
										retorno = 0;
									}
									else
									{
										printf("Ingresaste un dato inválido.\n");
									}
								}
							}
							if(retorno == -1)
							{
								printf("No existe ninguna pantalla con ese ID\n");
							}
						}
						else
						{
							printf("Error. Ingresaste un dato inválido\n");
						}
					}
				}
				if(flagCuit == 0)
				{
					printf("Ese cuit no coincide con ninguno en el registro\n");
				}
			}
		}
		else
		{
			printf("Error. Todavía no se ingresó ninguna contratación. Primero tiene que dar de alta una contratación para modificarla.\n");
		}
	}

	return retorno;
}

/**
 * brief Pide al usuario que borre una pantalla y todas sus contrataciones
 * \param Pantalla* pPantalla: Cadena donde se borrarán los datos
 * \param Contratacion* pContratacion: Cadena donde se borrarán las contrataciones relacionadas con la pantalla escogida
 * \param int limite: Limite o tamaño de la cadena
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int pantalla_baja(Pantalla* pPantalla, Contratacion* pContratacion, int limitePant)
{
	int retorno = -1;
	int numeroId;
	int indice;

	if(pPantalla != NULL && pContratacion != NULL && limitePant > 0)
	{
		if(pantalla_buscar(pPantalla, limitePant) == 1)
		{
			pantalla_mostrarConId(pPantalla, limitePant);
			if(!utn_getNumero(&numeroId, "Ingrese el ID de la pantalla a eliminar: \n", "Error. Ese ID no es válido\n", 1, CANT_PANTALLAS, 3))
			{
				for(int i = 0; i < limitePant; i++)
				{
					if(numeroId == pPantalla[i].idPantalla)
					{
						if(contratacion_buscar(pContratacion, CANT_CONTRATACIONES) == 1)
						{
							for(int j = 0; j < CANT_CONTRATACIONES; j++)
							{
								indice = pantalla_buscarId(pPantalla, limitePant, pContratacion[j].idPantalla);
								if(numeroId == pContratacion[indice].idPantalla)
								{
									pContratacion[indice].idContratacion = 0;
									strncpy(pContratacion[indice].cuitCliente, "", sizeof(pContratacion[indice].cuitCliente));
									strncpy(pContratacion[indice].nombreArchivo, "", sizeof(pContratacion[indice].nombreArchivo));
									pContratacion[indice].cantDias = 0;
									pContratacion[indice].idPantalla = 0;
									pContratacion[indice].isEmpty = 1;
								}
							}
						}
						pPantalla[i].idPantalla = 0;
						strncpy(pPantalla[i].nombre, "", sizeof(pPantalla[i].nombre));
						pPantalla[i].precioPorDia = 0.0;
						strncpy(pPantalla[i].direccion, "", sizeof(pPantalla[i].direccion));
						strncpy(pPantalla[i].tipo, "", sizeof(pPantalla[i].tipo));
						pPantalla[i].isEmpty = 1;
						retorno = 0;
						break;
					}
				}
				if(retorno == -1)
				{
					printf("No existe ninguna pantalla con ese ID\n");
				}
			}
			else
			{
				printf("Ingresaste un dato inválido.\n");
			}
		}
		else
		{
			printf("Todavía no ingresaste ninguna pantalla\n");
		}
	}

	return retorno;
}

/**
 * brief Pide al usuario que borre una contratación
 * \param Contratacion* pContratacion: Cadena donde se borrarán los datos
 * \param int limiteCont: Limite de posiciones de contrataciones
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int contratacion_borrar(Contratacion* pContratacion, Pantalla* pPantalla, int limiteCont)
{
	int retorno = -1;
	int id;
	char cuit[TAM_CUIT];
	int indicePant;
	int flagCuit = 0;
	Contratacion bufferContratacion;

	if(pContratacion != NULL && pPantalla != NULL && limiteCont > 0)
	{
		if(contratacion_buscar(pContratacion, limiteCont) == 1)
		{
			if(!utn_getCuit(cuit, "Ingrese el CUIT del cliente\n", "Error. Ese CUIT es inválido\n"))
			{
				for(int i = 0; i < limiteCont; i++)
				{
					if(strcmp(pContratacion[i].cuitCliente, cuit) == 0)
					{
						flagCuit = 1;
						indicePant = pantalla_buscarId(pPantalla, CANT_PANTALLAS, pContratacion[i].idPantalla);
						printf("ID: %-10d Nombre pantalla: %-10s Tipo: %-10s Dirección: %-15s Precio: %-10f\n", pPantalla[indicePant].idPantalla, pPantalla[indicePant].nombre, pPantalla[indicePant].tipo, pPantalla[indicePant].direccion, pPantalla[indicePant].precioPorDia);

						if(!utn_getNumero(&id, "Ingrese el ID de la pantalla a modificar\n", "Error. Ese ID no existe\n", 1, CANT_PANTALLAS, 3))
						{
							for(int i = 0; i < limiteCont; i++)
							{
								if(id == pContratacion[i].idContratacion)
								{
									bufferContratacion.cantDias = 0;
									strncpy(bufferContratacion.cuitCliente, "", sizeof(bufferContratacion.cuitCliente));
									strncpy(bufferContratacion.nombreArchivo, "", sizeof(bufferContratacion.nombreArchivo));
									bufferContratacion.idContratacion = 0;
									bufferContratacion.idPantalla = 0;
									bufferContratacion.isEmpty = 1;

									pContratacion[i] = bufferContratacion;
									retorno = 0;
									break;
								}
							}
							if(retorno == -1)
							{
								printf("No existe ninguna pantalla con ese ID\n");
							}
						}
						else
						{
							printf("Error. Ingresaste un dato inválido\n");
						}
					}
				}
				if(flagCuit == 0)
				{
					printf("Ese cuit no coincide con ninguno en el registro\n");
				}
			}
		}
		else
		{
			printf("Error. Todavía no se ingresó ninguna contratación. Primero tiene que dar de alta una contratación para cancelarla.\n");
		}
	}

	return retorno;
}

int consultaFacturacion(Contratacion* pContratacion, Pantalla* pPantalla, int limiteCont)
{
	int retorno = -1;
	char cuit[TAM_CUIT];
	int indicePant;
	int flagCuit = 0;

	if(pContratacion != NULL && pPantalla != NULL && limiteCont > 0)
	{
		if(contratacion_buscar(pContratacion, limiteCont) == 1)
		{
			if(!utn_getCuit(cuit, "Ingrese el CUIT del cliente\n", "Error. Ese CUIT es inválido\n"))
			{
				for(int i = 0; i < limiteCont; i++)
				{
					if(strcmp(pContratacion[i].cuitCliente, cuit) == 0)
					{
						flagCuit = 1;
						indicePant = pantalla_buscarId(pPantalla, CANT_PANTALLAS, pContratacion[i].idPantalla);
						printf("Nombre archivo: %-10s Precio por día: %-10.2f\n", pContratacion[i].nombreArchivo, pPantalla[indicePant].precioPorDia);
					}
				}
				if(flagCuit == 0)
				{
					printf("Ese cuit no coincide con ninguno en el registro\n");
				}
			}
		}
		else
		{
			printf("Error. Todavía no se ingresó ninguna contratación. Primero tiene que dar de alta una contratación para cancelarla.\n");
		}
	}

	return retorno;
}

/**
 * brief Muestra una lista de todas las contrataciones, pero sin el ID
 * \param Contratacion* pContratacion: Cadena que va a ser recorrida
 * \param Pantalla* pPantalla: Cadena que sirve solo para mostrar el nombre de la pantalla que está en otra estructura
 * \param int limite: Limite o tamaño de la cadena pContratacion
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int contratacion_mostrar(Contratacion* pContratacion, Pantalla* pPantalla, int limite)
{
	int retorno = -1;
	int indicePant;

	if(pContratacion != NULL && pPantalla != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			indicePant = pantalla_buscarId(pPantalla, limite, pContratacion[i].idPantalla);
			if(!pContratacion[i].isEmpty)
			{
				printf("Nombre pantalla: %-10s Nombre archivo: %-10s Cantidad días: %-10d CUIT: %-15s\n", pPantalla[indicePant].nombre, pContratacion[i].nombreArchivo, pContratacion[i].cantDias, pContratacion[i].cuitCliente);
			}
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Muestra una lista de todas las contrataciones incluyendo el ID
 * \param Contratacion* pContratacion: Cadena que va a ser recorrida
 * \param Pantalla* pPantalla: Cadena que sirve solo para mostrar el nombre de la pantalla que está en otra estructura
 * \param int limite: Limite o tamaño de la cadena pContratacion
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int contratacion_mostrarId(Contratacion* pContratacion, Pantalla* pPantalla, int limite)
{
	int retorno = -1;

	if(pContratacion != NULL && pPantalla != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pContratacion[i].isEmpty)
			{
				printf("ID: %-10d Nombre archivo: %-10s CUIT: %-15s Cantidad días: %-10d\n", pContratacion[i].idContratacion, pContratacion[i].nombreArchivo, pContratacion[i].cuitCliente, pContratacion[i].cantDias);
			}
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * brief Busca la posición donde la estructura Contratacion y otra estructura tengan el mismo ID
 * \param Pantalla* pPantalla: Cadena que va a ser recorrida
 * \param int limite: Limite o tamaño de la cadena
 * \param int id: ID que va a ser comparado con el ID de Pantalla
 * \return Retora la posición donde los IDs sean iguales o -1 en caso de error*/
int contratacion_buscarId(Contratacion* pContratacion, int limite, int id)
{
	int retorno = -1;

	if(pContratacion != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pContratacion[i].idContratacion == id)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

/*int ordenarPorPeso(Contratacion* pContratacion, Pantalla* pPantalla, int limite)
{
	int retorno = -1;
	int flagSwap = 0;
	Contratacion auxiliar;
	int peso1;
	int peso2;

	if(pContratacion != NULL && pPantalla != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 0; i < limite - 1; i++)
			{
				peso1 = getPeso(pPantalla, pContratacion, i, limite);
				peso2 = getPeso(pPantalla, pContratacion, i + 1, limite);
				if(peso1 != -1 && peso2 != -1 && peso1 > peso2)
				{
					auxiliar = pContratacion[i];
					pContratacion[i] = pContratacion[i + 1];
					pContratacion[i + 1] = auxiliar;
					flagSwap = 1;
				}
			}
		}while(flagSwap);

		retorno = 0;
	}

	return retorno;
}*/

/*int paisConMasMascotas(Contratacion* pMascotas, Pantalla* pRazas, int limite, int cantPaises, int* pais)
{
	int retorno = -1;
	int indiceRaza;
	int paisMaxMascotas = 0;

	if(pMascotas != NULL && pRazas != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			indiceRaza = buscarIdRazas(pRazas, limite, pMascotas[i].idPantalla);
			for(int j = 0; j < limite; i++)
			{
				if(pRazas[indiceRaza].direccion == pRazas[j].direccion)
				{
					paisMaxMascotas++;
				}
			}
		}
		retorno = 0;
	}

	return retorno;
}*/

/*static int getPeso(Pantalla* pPantalla, Contratacion* pContratacion, int indice, int limitePant)
{
	int retorno = -1;
	int indiceRaza;

	if(pPantalla != NULL && pContratacion != NULL && indice >= 0 && limitePant > 0)
	{
		indiceRaza = buscarIdRazas(pPantalla, limitePant, pContratacion[indice].idPantalla);

		return pPantalla[indiceRaza].tamanio;
	}

	return retorno;
}*/
