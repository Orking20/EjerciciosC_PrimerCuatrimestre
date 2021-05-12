/*
 * Relacion.c
 *
 *  Created on: 27 abr. 2021
 *      Author: mateo
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Estructura2.h"
#include "Estructura.h"
#include "Relacion.h"
#define CANT_PROPIETARIO 100
#define CANT_AUTOMOVIL 1000

/**
 * brief Pide al usuario que cargue los datos de una estructura
 * \param Estructura* pEstructura: Cadena donde se guardarán los datos
 * \param Estructura2* pEstructura2: Cadena para que se conecten los datos de una estructura con otra
 * \param int indice: La posición donde van a ser guardados los datos
 * \param int limiteEstruct2: Limite de posiciones de pEstructura2
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int estructura_alta(Estructura* pEstructura, Estructura2* pEstructura2, int indice, int limiteEstruct2)
{
	int retorno = -1;
	Estructura bufferEstructura;
	int idEstruct2;

	if(pEstructura != NULL && pEstructura2 != NULL && indice >= 0 && limiteEstruct2 > 0)
	{
		if(estructura2_buscar(pEstructura2, limiteEstruct2) == 1)
		{
			estructura2_mostrarConId(pEstructura2, limiteEstruct2);
			if(!utn_getNumero(&idEstruct2, "Ingrese el ID de la pantalla: \n", "Error. Ese ID es inválido\n", 1, CANT_PROPIETARIO, 3))
			{
				if(!utn_getTexto(bufferEstructura.cadena, limiteEstruct2, "Ingrese la cadena:\n", "Error. La cadena no es válido\n") &&
				   !utn_getNumero(&bufferEstructura.numero, "Ingrese un número:\n", "Error. Ese número es inválido\n", 1, 4, 3))
				{

					for(int i = 0; i < limiteEstruct2; i++)
					{
						if(idEstruct2 == pEstructura2[i].id)
						{
							bufferEstructura.id = idEstruct2;
							bufferEstructura.id = indice + 1;
							bufferEstructura.isEmpty = 0;
							pEstructura[indice] = bufferEstructura;
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
 * brief Pide al usuario que modifique los datos de un automovil
 * \param Automovil* pAutomovil: Cadena donde se guardarán los nuevos datos
 * \param Propietario* pPropietario: Cadena para que se conecten los datos de una estructura con otra
 * \param int limite: Limite de posiciones de pAutomovil
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int estructura_modificar(Estructura* pEstructura, Estructura2* pEstructura2, int limiteAuto)
{
	int retorno = -1;
	int id;
	char cuit[TAM_X];
	int indicePant;
	int flagCuit = 0;

	if(pEstructura != NULL && pEstructura2 != NULL && limiteAuto > 0)
	{
		if(estructura_buscar(pEstructura, limiteAuto) == 1)
		{
			if(!utn_getCuit(cuit, "Ingrese el CUIT del cliente\n", "Error. Ese CUIT es inválido\n"))
			{
				for(int i = 0; i < limiteAuto; i++)
				{
					if(strcmp(pEstructura[i].cadena, cuit) == 0)
					{
						flagCuit = 1;
						indicePant = estructura2_buscarPorId(pEstructura2, CANT_PROPIETARIO, pEstructura[i].id);
						printf("ID: %-10d Nombre pantalla: %-10s Tipo: %-10s Dirección: %-15s Precio: %-10s\n", pEstructura2[indicePant].id, pEstructura2[indicePant].cadena, pEstructura2[indicePant].cadena, pEstructura2[indicePant].cadena, pEstructura2[indicePant].cadena);

						if(!utn_getNumero(&id, "Ingrese el ID de la pantalla a modificar\n", "Error. Ese ID no existe\n", 1, CANT_PROPIETARIO, 3))
						{
							for(int i = 0; i < limiteAuto; i++)
							{
								if(id == pEstructura[i].id)
								{
									if(!utn_getNumero(&pEstructura[i].numero, "Ingrese la nueva cantidad de días de la contratación:\n", "Error. Ese número es inválido\n", 1, 365, 3))
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
int estructura2_baja(Estructura2* pEstructura2, Estructura* pEstructura, int limitePant)
{
	int retorno = -1;
	int numeroId;
	int indice;

	if(pEstructura2 != NULL && pEstructura != NULL && limitePant > 0)
	{
		if(estructura2_buscar(pEstructura2, limitePant) == 1)
		{
			estructura2_mostrarConId(pEstructura2, limitePant);
			if(!utn_getNumero(&numeroId, "Ingrese el ID de la pantalla a eliminar: \n", "Error. Ese ID no es válido\n", 1, CANT_PROPIETARIO, 3))
			{
				for(int i = 0; i < limitePant; i++)
				{
					if(numeroId == pEstructura2[i].id)
					{
						if(estructura_buscar(pEstructura, CANT_AUTOMOVIL) == 1)
						{
							for(int j = 0; j < CANT_AUTOMOVIL; j++)
							{
								indice = estructura2_buscarPorId(pEstructura2, limitePant, pEstructura[j].id);
								if(numeroId == pEstructura[indice].id)
								{
									pEstructura[indice].id = 0;
									strncpy(pEstructura[indice].cadena, "", sizeof(pEstructura[indice].cadena));
									strncpy(pEstructura[indice].cadena, "", sizeof(pEstructura[indice].cadena));
									pEstructura[indice].numero = 0;
									pEstructura[indice].id = 0;
									pEstructura[indice].isEmpty = 1;
								}
							}
						}
						pEstructura2[i].id = 0;
						strncpy(pEstructura2[i].cadena, "", sizeof(pEstructura2[i].cadena));
						pEstructura2[i].numero = 0;
						strncpy(pEstructura2[i].cadena, "", sizeof(pEstructura2[i].cadena));
						strncpy(pEstructura2[i].cadena, "", sizeof(pEstructura2[i].cadena));
						pEstructura2[i].isEmpty = 1;
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
int estructura_borrar(Estructura* pEstructura, Estructura2* pEstructura2, int limiteCont)
{
	int retorno = -1;
	int id;
	char cuit[TAM_X];
	int indicePant;
	int flagCuit = 0;
	Estructura bufferEstructura;

	if(pEstructura != NULL && pEstructura2 != NULL && limiteCont > 0)
	{
		if(estructura_buscar(pEstructura, limiteCont) == 1)
		{
			if(!utn_getCuit(cuit, "Ingrese el CUIT del cliente\n", "Error. Ese CUIT es inválido\n"))
			{
				for(int i = 0; i < limiteCont; i++)
				{
					if(strcmp(pEstructura[i].cadena, cuit) == 0)
					{
						flagCuit = 1;
						indicePant = estructura2_buscarPorId(pEstructura2, CANT_PROPIETARIO, pEstructura[i].id);
						printf("ID: %-10d Nombre pantalla: %-10s Tipo: %-10s Dirección: %-15s Precio: %-10s\n", pEstructura2[indicePant].id, pEstructura2[indicePant].cadena, pEstructura2[indicePant].cadena, pEstructura2[indicePant].cadena, pEstructura2[indicePant].cadena);

						if(!utn_getNumero(&id, "Ingrese el ID de la pantalla a modificar\n", "Error. Ese ID no existe\n", 1, CANT_PROPIETARIO, 3))
						{
							for(int i = 0; i < limiteCont; i++)
							{
								if(id == pEstructura[i].id)
								{
									bufferEstructura.numero = 0;
									strncpy(bufferEstructura.cadena, "", sizeof(bufferEstructura.cadena));
									strncpy(bufferEstructura.cadena, "", sizeof(bufferEstructura.cadena));
									bufferEstructura.id = 0;
									bufferEstructura.id = 0;
									bufferEstructura.isEmpty = 1;

									pEstructura[i] = bufferEstructura;
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

int consultaFacturacion(Estructura* pEstructura, Estructura2* pEstructura2, int limiteCont)
{
	int retorno = -1;
	char cuit[TAM_X];
	int indicePant;
	int flagCuit = 0;

	if(pEstructura != NULL && pEstructura2 != NULL && limiteCont > 0)
	{
		if(estructura_buscar(pEstructura, limiteCont) == 1)
		{
			if(!utn_getCuit(cuit, "Ingrese el CUIT del cliente\n", "Error. Ese CUIT es inválido\n"))
			{
				for(int i = 0; i < limiteCont; i++)
				{
					if(strcmp(pEstructura[i].cadena, cuit) == 0)
					{
						flagCuit = 1;
						indicePant = estructura2_buscarPorId(pEstructura2, CANT_PROPIETARIO, pEstructura[i].id);
						printf("Nombre archivo: %-10s Precio por día: %-10.2s\n", pEstructura[i].cadena, pEstructura2[indicePant].cadena);
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
int estructura_mostrar(Estructura* pEstructura, Estructura2* pEstructura2, int limite)
{
	int retorno = -1;
	int indicePant;

	if(pEstructura != NULL && pEstructura2 != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			indicePant = estructura2_buscarPorId(pEstructura2, limite, pEstructura[i].id);
			if(!pEstructura[i].isEmpty)
			{
				printf("Nombre pantalla: %-10s Nombre archivo: %-10s Cantidad días: %-10s CUIT: %-15s\n", pEstructura2[indicePant].cadena, pEstructura[i].cadena, pEstructura[i].cadena, pEstructura[i].cadena);
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
int estructura_mostrarConId(Estructura* pEstructura, Estructura2* pEstructura2, int limite)
{
	int retorno = -1;

	if(pEstructura != NULL && pEstructura2 != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(!pEstructura[i].isEmpty)
			{
				printf("ID: %-10d Nombre archivo: %-10s CUIT: %-15s Cantidad días: %-10s\n", pEstructura[i].id, pEstructura[i].cadena, pEstructura[i].cadena, pEstructura[i].cadena);
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
/*{
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
}*/

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
