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
#include "Propietario.h"
#include "Automovil.h"
#include "Relacion.h"
#define CANT_PROPIETARIO 100
#define CANT_AUTOMOVIL 1000

/**
 * brief Pide al usuario que cargue los datos de un automovil
 * \param Automovil* pContratacion: Cadena donde se guardarán los datos
 * \param Propietario* pPropietario: Cadena para que se conecten los datos de una estructura con otra
 * \param int indice: La posición donde van a ser guardados los datos
 * \param int limiteProp: Limite de posiciones de propietarios
 * \return Retora 0 (EXITO) o -1 (ERROR) si no*/
int altaContratacion(Automovil* pAutomovil, Propietario* pPropietario, int indice, int limiteProp)
{
	int retorno = -1;
	Automovil bufferAutomovil;
	int idPropietario;

	if(pAutomovil != NULL && pPropietario != NULL && indice >= 0 && limiteProp > 0)
	{
		if(buscarPropietario(pPropietario, limiteProp) == 1)
		{
			mostrarPropietarioId(pPropietario, limiteProp);
			if(!utn_getNumero(&idPropietario, "Ingrese el ID de la pantalla: \n", "Error. Ese ID es inválido\n", 1, CANT_PROPIETARIO, 3))
			{
				if(!utn_getTexto(bufferAutomovil.patente, limiteProp, "Ingrese la patente\n", "Error. Esa patente es inválida\n") &&
				   !utn_getNumero(&bufferAutomovil.marca, "Ingrese la marca (1.Alpha Romeo - 2.Ferrari - 3.Audi - 4.Otro):\n", "Error. Solo puede ingresar (1.Alpha Romeo - 2.Ferrari - 3.Audi - 4.Otro)\n", 1, 4, 3))
				{

					for(int i = 0; i < limiteProp; i++)
					{
						if(idPropietario == pPropietario[i].idPropietario)
						{
							bufferAutomovil.idAutomovil = idPropietario;
							bufferAutomovil.idAutomovil = indice + 1;
							bufferAutomovil.isEmpty = 0;
							pAutomovil[indice] = bufferAutomovil;
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
int modificarPropietario(Automovil* pAutomovil, Propietario* pPropietario, int limiteAuto)
{
	int retorno = -1;
	int id;
	char cuit[TAM_PATENTE];
	int indicePant;
	int flagCuit = 0;

	if(pAutomovil != NULL && pPropietario != NULL && limiteAuto > 0)
	{
		if(buscarAutomovil(pAutomovil, limiteAuto) == 1)
		{
			if(!utn_getCuit(cuit, "Ingrese el CUIT del cliente\n", "Error. Ese CUIT es inválido\n"))
			{
				for(int i = 0; i < limiteAuto; i++)
				{
					if(strcmp(pAutomovil[i].cuitCliente, cuit) == 0)
					{
						flagCuit = 1;
						indicePant = buscarIdPantalla(pPropietario, CANT_PROPIETARIO, pAutomovil[i].idPantalla);
						printf("ID: %-10d Nombre pantalla: %-10s Tipo: %-10s Dirección: %-15s Precio: %-10f\n", pPropietario[indicePant].idPropietario, pPropietario[indicePant].nombre, pPropietario[indicePant].tipo, pPropietario[indicePant].direccion, pPropietario[indicePant].precioPorDia);

						if(!utn_getNumero(&id, "Ingrese el ID de la pantalla a modificar\n", "Error. Ese ID no existe\n", 1, CANT_PROPIETARIO, 3))
						{
							for(int i = 0; i < limiteAuto; i++)
							{
								if(id == pAutomovil[i].idContratacion)
								{
									if(!utn_getNumero(&pAutomovil[i].cantDias, "Ingrese la nueva cantidad de días de la contratación:\n", "Error. Ese número es inválido\n", 1, 365, 3))
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
int bajaPantalla(Propietario* pPropietario, Automovil* pContratacion, int limitePant)
{
	int retorno = -1;
	int numeroId;
	int indice;

	if(pPropietario != NULL && pContratacion != NULL && limitePant > 0)
	{
		if(buscarPantalla(pPropietario, limitePant) == 1)
		{
			mostrarPantallaId(pPropietario, limitePant);
			if(!utn_getNumero(&numeroId, "Ingrese el ID de la pantalla a eliminar: \n", "Error. Ese ID no es válido\n", 1, CANT_PROPIETARIO, 3))
			{
				for(int i = 0; i < limitePant; i++)
				{
					if(numeroId == pPropietario[i].idPropietario)
					{
						if(buscarContratacion(pContratacion, CANT_AUTOMOVIL) == 1)
						{
							for(int j = 0; j < CANT_AUTOMOVIL; j++)
							{
								indice = buscarIdPantalla(pPropietario, limitePant, pContratacion[j].idPropietario);
								if(numeroId == pContratacion[indice].idPantalla)
								{
									pContratacion[indice].idContratacion = 0;
									strncpy(pContratacion[indice].cuitCliente, "", sizeof(pContratacion[indice].cuitCliente));
									strncpy(pContratacion[indice].nombreArchivo, "", sizeof(pContratacion[indice].nombreArchivo));
									pContratacion[indice].cantDias = 0;
									pContratacion[indice].idPropietario = 0;
									pContratacion[indice].isEmpty = 1;
								}
							}
						}
						pPropietario[i].idPropietario = 0;
						strncpy(pPropietario[i].nombre, "", sizeof(pPropietario[i].nombre));
						pPropietario[i].precioPorDia = 0.0;
						strncpy(pPropietario[i].direccion, "", sizeof(pPropietario[i].direccion));
						strncpy(pPropietario[i].tipo, "", sizeof(pPropietario[i].tipo));
						pPropietario[i].isEmpty = 1;
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
int borrarContratacion(Automovil* pContratacion, Propietario* pPropietario, int limiteCont)
{
	int retorno = -1;
	int id;
	char cuit[TAM_PATENTE];
	int indicePant;
	int flagCuit = 0;
	Automovil bufferContratacion;

	if(pContratacion != NULL && pPropietario != NULL && limiteCont > 0)
	{
		if(buscarContratacion(pContratacion, limiteCont) == 1)
		{
			if(!utn_getCuit(cuit, "Ingrese el CUIT del cliente\n", "Error. Ese CUIT es inválido\n"))
			{
				for(int i = 0; i < limiteCont; i++)
				{
					if(strcmp(pContratacion[i].cuitCliente, cuit) == 0)
					{
						flagCuit = 1;
						indicePant = buscarIdPantalla(pPropietario, CANT_PROPIETARIO, pContratacion[i].idPantalla);
						printf("ID: %-10d Nombre pantalla: %-10s Tipo: %-10s Dirección: %-15s Precio: %-10f\n", pPropietario[indicePant].idPropietario, pPropietario[indicePant].nombre, pPropietario[indicePant].tipo, pPropietario[indicePant].direccion, pPantalla[indicePant].precioPorDia);

						if(!utn_getNumero(&id, "Ingrese el ID de la pantalla a modificar\n", "Error. Ese ID no existe\n", 1, CANT_PROPIETARIO, 3))
						{
							for(int i = 0; i < limiteCont; i++)
							{
								if(id == pContratacion[i].idContratacion)
								{
									bufferContratacion.cantDias = 0;
									strncpy(bufferContratacion.cuitCliente, "", sizeof(bufferContratacion.cuitCliente));
									strncpy(bufferContratacion.nombreArchivo, "", sizeof(bufferContratacion.nombreArchivo));
									bufferContratacion.idContratacion = 0;
									bufferContratacion.idPropietario = 0;
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

int consultaFacturacion(Automovil* pContratacion, Propietario* pPropietario, int limiteCont)
{
	int retorno = -1;
	char cuit[TAM_PATENTE];
	int indicePant;
	int flagCuit = 0;

	if(pContratacion != NULL && pPropietario != NULL && limiteCont > 0)
	{
		if(buscarContratacion(pContratacion, limiteCont) == 1)
		{
			if(!utn_getCuit(cuit, "Ingrese el CUIT del cliente\n", "Error. Ese CUIT es inválido\n"))
			{
				for(int i = 0; i < limiteCont; i++)
				{
					if(strcmp(pContratacion[i].cuitCliente, cuit) == 0)
					{
						flagCuit = 1;
						indicePant = buscarIdPropietario(pPropietario, CANT_PROPIETARIO, pContratacion[i].idPropietario);
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
int mostrarContratacion(Automovil* pContratacion, Propietario* pPropietario, int limite)
{
	int retorno = -1;
	int indicePant;

	if(pContratacion != NULL && pPropietario != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			indicePant = buscarIdPantalla(pPropietario, limite, pContratacion[i].idPantalla);
			if(!pContratacion[i].isEmpty)
			{
				printf("Nombre pantalla: %-10s Nombre archivo: %-10s Cantidad días: %-10d CUIT: %-15s\n", pPropietario[indicePant].nombre, pContratacion[i].nombreArchivo, pContratacion[i].cantDias, pContratacion[i].cuitCliente);
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
int mostrarContratacionId(Automovil* pContratacion, Propietario* pPropietario, int limite)
{
	int retorno = -1;

	if(pContratacion != NULL && pPropietario != NULL && limite > 0)
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
