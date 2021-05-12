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
#include "Estructura.h"
#include "Entidad.h"
#include "Relacion.h"

/**
 * brief Pide al usuario que cargue los datos de una ESTRUCTURA para que se relacione con la ENTIDAD
 * \param Estructura* pEstructura: Cadena donde se guardarán los datos
 * \param Entidad* pEntidad: Cadena para que se conecten los datos de una estructura con otra
 * \param int limiteEstructura: Limite o tamaño de la cadena pESTRUCTURA
 * \param int limiteEntidad: Limite o tamaño de la cadena pENTIDAD
 * \param int indice: La posición donde van a ser guardados los datos
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int estructura_alta(Estructura* pEstructura, Entidad* pEntidad, int limiteEstructura, int limiteEntidad, int indice)
{
	int retorno = -1;
	Estructura bufferEstructura;
	int idEntidad;

	if(pEstructura != NULL && pEntidad != NULL && limiteEstructura > 0 && limiteEntidad > 0 && indice >= 0)
	{
		if(entidad_buscar(pEntidad, limiteEntidad) == 1)
		{
			entidad_mostrarConId(pEntidad, limiteEntidad);
			if(!utn_getNumero(&idEntidad, "Ingrese el ID de la ENTIDAD: \n", "Error. Ese ID es inválido\n", 1, limiteEstructura, 3))
			{
				if(!utn_getTexto(bufferEstructura.cadena, limiteEntidad, "Ingrese la CADENA:\n", "Error. La CADENA no es válido\n") &&
				   !utn_getNumero(&bufferEstructura.numero, "Ingrese un NÚMERO:\n", "Error. Ese NÚMERO es inválido\n", 1, 100, 3))
				{

					for(int i = 0; i < limiteEntidad; i++)
					{
						if(idEntidad == pEntidad[i].id)
						{
							bufferEstructura.id = idEntidad;
							bufferEstructura.id = indice + 1;
							bufferEstructura.isEmpty = 0;
							pEstructura[indice] = bufferEstructura;
							retorno = 0;
							break;
						}
					}
					if(retorno == -1)
					{
						printf("No existe ninguna ENTIDAD con ese ID\n");
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
			printf("Error. Todavía no se ingresó ninguna ENTIDAD. Primero tiene que dar de alta una ENTIDAD para añadir una ESTRUCTURA.\n");
		}
	}

	return retorno;
}

/**
 * brief Pide al usuario que modifique los datos de una ESTRUCTURA ingresando el NUMERO de la ENTIDAD
 * \param Estructura* pEstructura: Cadena donde se guardarán los nuevos datos
 * \param Entidad* pEntidad: Cadena para que se conecten los datos de una estructura con otra
 * \param int limiteEstructura: Limite o tamaño de la cadena pESTRUCTURA
 * \param int limiteEntidad: Limite o tamaño de la cadena pENTIDAD
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int estructura_modificar(Estructura* pEstructura, Entidad* pEntidad, int limiteEstructura, int limiteEntidad)
{
	int retorno = -1;
	int idEntidad;
	char cadena[TAM_CADENA];
	int indiceEntidad;
	int flagCadena = 0;

	if(pEstructura != NULL && pEntidad != NULL && limiteEstructura > 0 && limiteEntidad > 0)
	{
		if(estructura_buscar(pEstructura, limiteEstructura) == 1)
		{
			if(!utn_getTexto(cadena, TAM_CADENA, "\nIngrese el NÚMERO de la ENTIDAD: ", "\nError. Ese NÚMERO no es válido"))
			{
				for(int i = 0; i < limiteEstructura; i++)
				{
					if(strcmp(pEstructura[i].cadena, cadena) == 0)
					{
						flagCadena = 1;
						indiceEntidad = entidad_buscarPorId(pEntidad, limiteEntidad, pEstructura[i].id);
						printf("\nID: %-10d CADENA: %-15s CADENA: %-15s CADENA: %-15s\n", pEntidad[indiceEntidad].id, pEntidad[indiceEntidad].cadena, pEntidad[indiceEntidad].cadena, pEntidad[indiceEntidad].cadena);

						if(!utn_getNumero(&idEntidad, "\nIngrese el ID de la ENTIDAD a modificar: ", "\nError. Ese ID no existe", 1, limiteEntidad, 3))
						{
							for(int i = 0; i < limiteEstructura; i++)
							{
								if(idEntidad == pEstructura[i].id)
								{
									if(!utn_getNumero(&pEstructura[i].numero, "\nIngrese el NUEVO DATO A MODIFICAR de la ESTRUCTURA: ", "\nError. Ese DATO no es válido", 1, 365, 3))
									{
										retorno = 0;
									}
									else
									{
										printf("\nIngresaste un dato inválido.");
									}
								}
							}
							if(retorno == -1)
							{
								printf("\nNo existe ninguna ENTIDAD con ese ID");
							}
						}
						else
						{
							printf("\nError. Ingresaste un dato inválido");
						}
					}
				}
				if(flagCadena == 0)
				{
					printf("\nEsa CADENA no coincide con ninguna en el registro");
				}
			}
		}
		else
		{
			printf("\nError. Todavía no se ingresó ninguna ESTRUCTURA. Primero tiene que dar de alta una ESTRUCTURA para poder modificarla.");
		}
	}

	return retorno;
}

/**
 * brief Pide al usuario que borre una ENTIDAD y todas sus ESTRUCTURAS mediante el ID de la ENTIDAD
 * \param Entidad* pEntidad: Cadena donde se borrarán los datos
 * \param Estructura* pEstructura: Cadena donde se borrarán las ESTRUCTURAS relacionadas con la ENTIDAD escogida
 * \param int limiteEntidad: Limite o tamaño de la cadena pENTIDAD
 * \param int limiteEstructura: Limite o tamaño de la cadena pESTRUCTURA
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int entidad_baja(Entidad* pEntidad, Estructura* pEstructura, int limiteEntidad, int limiteEstructura)
{
	int retorno = -1;
	int numeroId;
	int indice;

	if(pEntidad != NULL && pEstructura != NULL && limiteEntidad > 0 && limiteEstructura > 0)
	{
		if(entidad_buscar(pEntidad, limiteEntidad) == 1)
		{
			entidad_mostrarConId(pEntidad, limiteEntidad);
			if(!utn_getNumero(&numeroId, "\nIngrese el ID de la pantalla a eliminar: ", "\nError. Ese ID no es válido", 1, limiteEntidad, 3))
			{
				for(int i = 0; i < limiteEntidad; i++)
				{
					if(numeroId == pEntidad[i].id)
					{
						if(estructura_buscar(pEstructura, limiteEstructura) == 1)
						{
							for(int j = 0; j < limiteEstructura; j++)
							{
								indice = entidad_buscarPorId(pEntidad, limiteEntidad, pEstructura[j].id);
								if(numeroId == pEstructura[indice].id)
								{
									pEstructura[indice].id = 0;
									strncpy(pEstructura[indice].cadena, "", sizeof(pEstructura[indice].cadena));
									pEstructura[indice].numero = 0;
									pEstructura[indice].isEmpty = 1;
								}
							}
						}
						pEntidad[i].id = 0;
						strncpy(pEntidad[i].cadena, "", sizeof(pEntidad[i].cadena));
						pEntidad[i].numero = 0;
						pEntidad[i].isEmpty = 1;
						retorno = 0;
						break;
					}
				}
				if(retorno == -1)
				{
					printf("No existe ninguna ENTIDAD con ese ID\n");
				}
			}
			else
			{
				printf("Ingresaste un dato inválido.\n");
			}
		}
		else
		{
			printf("Todavía no ingresaste ninguna ENTIDAD\n");
		}
	}

	return retorno;
}

/**
 * brief Pide al usuario que borre una ESTRUCTURA ingresando su CADENA
 * \param Estructura* pEstructura: Cadena donde se borrarán los datos
 * \param Entidad* pEntidad: Cadena que se usa para mostrar sus datos antes de borrar los de la ESTRUCTURA
 * \param int limiteEstructura: Limite o tamaño de la cadena pESTRUCTURA
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int estructura_baja(Estructura* pEstructura, Entidad* pEntidad, int limiteEstructura, int limiteEntidad)
{
	int retorno = -1;
	int id;
	char cadena[TAM_CADENA];
	int indiceEntidad;
	int flagCuit = 0;
	Estructura bufferEstructura;

	if(pEstructura != NULL && pEntidad != NULL && limiteEstructura > 0 && limiteEntidad > 0)
	{
		if(estructura_buscar(pEstructura, limiteEstructura) == 1)
		{
			if(!utn_getTexto(cadena, TAM_CADENA, "\nIngrese el NUMERO del cliente", "\nError. Ese NUMERO no es válido"))
			{
				for(int i = 0; i < limiteEstructura; i++)
				{
					if(strcmp(pEstructura[i].cadena, cadena) == 0)
					{
						flagCuit = 1;
						indiceEntidad = entidad_buscarPorId(pEntidad, limiteEntidad, pEstructura[i].id);
						printf("\nID: %-10d CADENA: %-10s CADENA: %-10s CADENA: %-15s\n", pEntidad[indiceEntidad].id, pEntidad[indiceEntidad].cadena, pEntidad[indiceEntidad].cadena, pEntidad[indiceEntidad].cadena);

						if(!utn_getNumero(&id, "\nIngrese el ID de la ENTIDAD a modificar: ", "\nError. Ese ID no existe", 1, limiteEntidad, 3))
						{
							for(int i = 0; i < limiteEstructura; i++)
							{
								if(id == pEstructura[i].id)
								{
									bufferEstructura.numero = 0;
									strncpy(bufferEstructura.cadena, "", sizeof(bufferEstructura.cadena));
									bufferEstructura.id = 0;
									bufferEstructura.isEmpty = 1;

									pEstructura[i] = bufferEstructura;
									retorno = 0;
									break;
								}
							}
							if(retorno == -1)
							{
								printf("\nNo existe ninguna ENTIDAD con ese ID");
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
			printf("\nError. Todavía no se ingresó ninguna ESTRUCTURA. Primero tiene que dar de alta una ESTRUCTURA para borrarla.");
		}
	}

	return retorno;
}

/**
 * brief Muestra una lista de todas las ESTRUCTURAS, pero sin el ID y con algún dato de la ENTIDAD
 * \param Estructura* pEstructura: Cadena que va a ser recorrida
 * \param Entidad* pEntidad: Cadena que sirve solo para mostrar el DATO que está en ENTIDAD
 * \param int limiteEstructura: Limite o tamaño de la cadena pESTRUCTURA
 * \param int limiteEntidad: Limite o tamaño de la cadena pENTIDAD
 * \return Retora 0 (EXITO) o -1 (ERROR)*/
int estructura_mostrar(Estructura* pEstructura, Entidad* pEntidad, int limiteEstructura, int limiteEntidad)
{
	int retorno = -1;
	int indiceEntidad;

	if(pEstructura != NULL && pEntidad != NULL && limiteEstructura > 0 && limiteEntidad > 0)
	{
		for(int i = 0; i < limiteEstructura; i++)
		{
			indiceEntidad = entidad_buscarPorId(pEntidad, limiteEntidad, pEstructura[i].id);
			if(!pEstructura[i].isEmpty)
			{
				printf("CADENA: %-15s CADENA: %-15s NÚMERO: %-15d CADENA: %-15s\n", pEntidad[indiceEntidad].cadena, pEstructura[i].cadena, pEstructura[i].numero, pEstructura[i].cadena);
			}
		}
		retorno = 0;
	}

	return retorno;
}

/*int ordenarPorPeso(Estructura* pEstructura, Entidad* pEntidad, int limite)
{
	int retorno = -1;
	int flagSwap = 0;
	Estructura auxiliar;
	int peso1;
	int peso2;

	if(pEstructura != NULL && pEntidad != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 0; i < limite - 1; i++)
			{
				peso1 = getPeso(pEntidad, pEstructura, i, limite);
				peso2 = getPeso(pEntidad, pEstructura, i + 1, limite);
				if(peso1 != -1 && peso2 != -1 && peso1 > peso2)
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

static int getPeso(Entidad* pEntidad, Estructura* pEstructura, int indice, int limiteEntidad)
{
	int retorno = -1;
	int indiceEntidad;

	if(pEntidad != NULL && pEstructura != NULL && indice >= 0 && limiteEntidad > 0)
	{
		indiceEntidad = entidad_buscarPorId(pEntidad, limiteEntidad, pEstructura[indice].id);

		return pEntidad[indiceEntidad].tamanio;
	}

	return retorno;
}*/
