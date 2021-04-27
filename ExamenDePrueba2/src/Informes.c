/*
 * Informes.c
 *
 *  Created on: 25 abr. 2021
 *      Author: mateo
 */

#include <stdio.h>
#include <stdlib.h>
#include "Contratacion.h"
#include "Pantalla.h"
#define CANT_PANTALLAS 100
#define CANT_CONTRATACIONES 1000

static int calcularImporte(Pantalla* pPantalla, int limite, float* precioPorDia);

int listaClientes(Contratacion* pContratacion, Pantalla* pPantalla, int limiteCont)
{
	int retorno = -1;
	int cantContratos = 1;
	float importe;

	if(pContratacion != NULL && pPantalla != NULL && limiteCont > 0)
	{
		printf("Cliente CUIT: %-10s ");
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
