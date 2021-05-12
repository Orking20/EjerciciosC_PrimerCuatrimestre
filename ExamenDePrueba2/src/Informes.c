/*
 * Informes.c
 *
 *  Created on: 25 abr. 2021
 *      Author: mateo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contratacion.h"
#include "Pantalla.h"
#include "Informes.h"
#define CANT_PANTALLAS 100
#define CANT_CONTRATACIONES 1000
/*
static int calcularImporte(Pantalla* pPantalla, int limite, float* precioPorDia);

int listaClientes(Contratacion* pContratacion, Pantalla* pPantalla, int limiteCont)
{
	int retorno = -1;
	int cantContratos = 1;
	float importe;

	if(pContratacion != NULL && pPantalla != NULL && limiteCont > 0)
	{
		printf("Cliente CUIT: %-10s ",);
	}

	return retorno;
}

static int calcularImporte(Pantalla* pPantalla, Contratacion* pContratacion, int limiteCont, int* cantContratos, float* precioPorDia)
{
	int retorno = -1;
	int flagCuit = 0;
	char cuit[TAM_CUIT];
	int indicePant;

	if(precioPorDia != NULL)
	{
		for(int i = 0; i < limiteCont; i++)
		{
			for(int j = 0; j < limiteCont; j++)
			{
				if(strcmp(pContratacion[i].cuitCliente, pContratacion[j].cuitCliente) == 0)
				{
					cantContratos++;
				}
			}
		}
	}

	return retorno;
}




*/

/*
 *
int cuitSinRepetir(Pantalla* pPantalla, Contratacion* pContratacion, int limiteCont)
{
	int retorno = -1;
	int flagLoEncontre = 0;
	char cuit[TAM_CUIT];
	int indicePant;
	char listaCuits[];

	if(pPantalla != NULL && pContratacion != NULL && limiteCont > 0)
	{
		for(int i = 0; i < limiteCont; i++)
		{
			flagLoEncontre = 0;
			strncpy(cuit, pContratacion[i].cuitCliente, sizeof(cuit));
			listaCuits = buscarCuitEnListaCuits();
			for(int j = 0; j < limiteCont; j++)
			{
				if(strcmp(cuit, pContratacion[j].cuitCliente) == 0)
				{
					flagLoEncontre = 1;
				}
			}
			if(flagLoEncontre == 0)
			{
				cuit = listaCuits;
			}
		}
	}

	return retorno;
}
*/



/*
int cliente_setClient(Cliente* listClient, int lenClient, Contratacion* listCont, int lenCont){
	int result = -1;
	int flagExiste;
	int indiceLibreCliente = 0;
	if(listClient!=NULL && lenClient>0 && listCont!=NULL && lenCont>0){
		for(int i=0; i<lenCont; i++){
			if(!cliente_esRepetido(listClient, listCont, indiceLibreCliente, i)){
				cliente_copiarCuitContrataciones(listClient, lenClient, listCont, lenCont, indiceLibreCliente, i);
				indiceLibreCliente++;
			}
		}
		cliente_printList(listClient, CANT_CLIENT);
	}
	return result;
}
void cliente_copiarCuitContrataciones(Cliente* listClient, int lenClient, Contratacion* listCont, int lenCont, int indiceCliente, int indiceCont){
	strncpy(listClient[indiceCliente].cuit_cliente, listCont[indiceCont].cuitCliente, CUIT_LEN);
	cliente_setClienteVacio(listClient, lenClient, indiceCliente);
}
int cliente_esRepetido(Cliente* listClient, Contratacion* listCont, int indiceLibreCliente, int indexCont){
	int result = 0;
	for(int j=0; j<=indiceLibreCliente; j++){
		if(strncmp(listCont[indexCont].cuitCliente, listClient[j].cuit_cliente, CUIT_LEN) == 0)
		{
			result = 1;
			break;
		}
	}
	return result;
}
int cliente_setClienteVacio(Cliente* list, int len, int index){
	int result = -1;
	if(list!=NULL && len>0 && index>0){
		list[index].id = index +1;
		list[index].facturacion = 0;
		list[index].cant_contratacion = 0;
		list[index].isEmpty = 0;
		result = 0;
	}
	return result;
}
*/


#define CANT_CLIENTES 1000

int infoContratacionesConImportePorCliente(Contratacion* pContrataciones, Pantalla* pPantallas, int limiteContrataciones, int limitePantalla)
{
	int retorno = -1;
	char listaCuit[CANT_CLIENTES][TAM_CUIT];
	int flagExisteCuit;
	int indiceCuitLibre = 0;

	if(pContrataciones != NULL && pPantallas != NULL && limiteContrataciones > 0 && limitePantalla > 0)
	{
		for(int i = 0; i < limiteContrataciones; i++)
		{
			flagExisteCuit = 0;
			if(pContrataciones[i].isEmpty == 0)
			{
				for(int j = 0; j < indiceCuitLibre; j++)
				{
					if(strncmp(pContrataciones[i].cuitCliente, listaCuit[j], TAM_CUIT) == 0)
					{
						flagExisteCuit = 1;
						break;
					}
				}
				if(flagExisteCuit == 0)
				{
					strncpy(listaCuit[indiceCuitLibre], pContrataciones[i].cuitCliente, TAM_CUIT);
					indiceCuitLibre++;
				}
			}
		}
		for(int i = 0; i < indiceCuitLibre; i++)
		{
			printf("\nCliente con cuit %s:", listaCuit[i]);
			info_imprimirContratacionesConImporte(pContrataciones, pPantallas, limiteContrataciones, limitePantalla, listaCuit[i]);
		}
	}

	return retorno;
}

int info_imprimirContratacionesConImporte(Contratacion* pContrataciones, Pantalla* pPantallas, int limiteContrataciones, int limitePantalla, char* auxiliarCuit)
{
	int retorno = -1;
	int indiceArrayPantalla;
	int idPantalla;
	float auxiliarImporte;

	if(pContrataciones != NULL && pPantallas != NULL && limiteContrataciones > 0 && limitePantalla > 0)
	{
		for(int i = 0; i < limiteContrataciones; i++)
		{
			if(pContrataciones[i].isEmpty)
			{
				continue;
			}
			if(strncmp(pContrataciones[i].cuitCliente, auxiliarCuit, TAM_CUIT) == 0)
			{
				retorno = 0;
				idPantalla = pContrataciones[i].idPantalla;
				indiceArrayPantalla = pantalla_buscarId(pPantallas, limitePantalla, idPantalla);
				auxiliarImporte = pContrataciones[i].cantDias * pPantallas[indiceArrayPantalla].precioPorDia;
				printf("\nID: %-10d Archivo: %-15s CUIT: %-15s Cantidad días: %-15d Importe: %-15.2f", pContrataciones[i].idContratacion,
																									   pContrataciones[i].nombreArchivo,
																									   pContrataciones[i].cuitCliente,
																									   pContrataciones[i].cantDias,
																									   auxiliarImporte);
			}
		}
	}

	return retorno;
}
