/*
 * Empleado.c
 *
 *  Created on: 17 abr. 2021
 *      Author: mateo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "utn.h"
#define TAM_NOMBRE 100
#define TAM_PUESTO 64

int cargarEmpleados(Empleado* pEmpleados, int limite, int indice)
{
	int retorno = -1;
	Empleado bufferEmpleados;
	char nombre[TAM_NOMBRE];
	char puesto[TAM_PUESTO];
	long int sueldo;
	int esAnalista;
	int esTester;
	int comprobarError;

	if(pEmpleados != NULL && limite > 0 && indice >= 0)
	{
		printf("\nNuevo empleado\n");
		comprobarError = utn_getNombre(nombre, TAM_NOMBRE, "Ingrese el nombre: \n", "Ese no es un nombre válido\n");
		while(comprobarError == -1)
		{
			comprobarError = utn_getNombre(nombre, TAM_NOMBRE, "Ingrese el nombre nuevamente: \n", "Ese no es un nombre válido\n");
		}

		utn_getTexto(puesto, TAM_PUESTO, "Ingrese el puesto (programador, analista, tester): \n", "Error.\n");
		while(strcmp(puesto, "programador") != 0 && strcmp(puesto, "analista") != 0 && strcmp(puesto, "tester") != 0)
		{
			printf("Error. Los puestos de trabajo son programador, analista y tester.\n");
			utn_getTexto(puesto, TAM_PUESTO, "Ingrese el puesto nuevamente (programador, analista, tester): \n", "Error.\n");
		}

		comprobarError = utn_getPrecio(&sueldo, "Ingrese el sueldo: \n", "Error. Ese precio no es válido\n");
		while(comprobarError == -1)
		{
			comprobarError = utn_getPrecio(&sueldo, "Ingrese el sueldo nuevamente: \n", "Error. Ese precio no es válido\n");
		}

		if(strcmp(puesto, "analista") == 0)
		{
			esAnalista = 1;
			esTester = 0;
		}
		else if(strcmp(puesto, "tester") == 0)
		{
			esAnalista = 0;
			esTester = 1;
		}
		else
		{
			esAnalista = 0;
			esTester = 0;
		}

		bufferEmpleados.idEmpleado = indice + 1;
		strncpy(bufferEmpleados.nombre, nombre, sizeof(bufferEmpleados.nombre));
		strncpy(bufferEmpleados.puesto, puesto, sizeof(bufferEmpleados.puesto));
		bufferEmpleados.sueldo = sueldo;
		bufferEmpleados.esAnalista = esAnalista;
		bufferEmpleados.esTester = esTester;

		pEmpleados[indice] = bufferEmpleados;
		retorno = 0;
	}

	return retorno;
}

int mostrarEmpleados(Empleado* pEmpleados, int limite)
{
	int retorno = -1;

	if(pEmpleados != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			printf("ID: %d - Nombre: %s - Puesto: %s - Sueldo: %ld\n", pEmpleados[i].idEmpleado, pEmpleados[i].nombre, pEmpleados[i].puesto, pEmpleados[i].sueldo);
		}
		retorno = 0;
	}

	return retorno;
}

int ordenarPorPuestos(Empleado* pEmpleados, int limite)
{
	int retorno = -1;
	char auxNombre[TAM_NOMBRE];
	char auxPuesto[TAM_PUESTO];
	long int auxSueldo;
	int auxId;
	int auxEsAnalista;
	int flagSwap = 0;

	if(pEmpleados != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 0; i < limite - 1; i++)
			{
				if(strcmp(pEmpleados[i].puesto, pEmpleados[i + 1].puesto) > 0)
				{
					strncpy(auxNombre, pEmpleados[i].nombre, sizeof(auxPuesto));
					strncpy(pEmpleados[i].nombre, pEmpleados[i + 1].nombre, sizeof(pEmpleados[i].nombre));
					strncpy(pEmpleados[i + 1].nombre, auxNombre, sizeof(pEmpleados[i + 1].nombre));

					strncpy(auxPuesto, pEmpleados[i].puesto, sizeof(auxPuesto));
					strncpy(pEmpleados[i].puesto, pEmpleados[i + 1].puesto, sizeof(pEmpleados[i].puesto));
					strncpy(pEmpleados[i + 1].puesto, auxPuesto, sizeof(pEmpleados[i + 1].puesto));

					auxSueldo = pEmpleados[i].sueldo;
					pEmpleados[i].sueldo = pEmpleados[i + 1].sueldo;
					pEmpleados[i + 1].sueldo = auxSueldo;

					auxId = pEmpleados[i].idEmpleado;
					pEmpleados[i].idEmpleado = pEmpleados[i + 1].idEmpleado;
					pEmpleados[i + 1].idEmpleado = auxId;

					auxEsAnalista = pEmpleados[i].esAnalista;
					pEmpleados[i].esAnalista = pEmpleados[i + 1].esAnalista;
					pEmpleados[i + 1].esAnalista = auxEsAnalista;

					flagSwap = 1;
				}
			}
		}while(flagSwap);

		retorno = 0;
	}

	return retorno;
}

int mostrarAnalistas(Empleado* pEmpleados, int limite)
{
	int retorno = -1;

	if(pEmpleados != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(pEmpleados[i].esAnalista)
			{
				printf("ID: %d - Nombre: %s - Puesto: %s - Sueldo: %ld\n", pEmpleados[i].idEmpleado, pEmpleados[i].nombre, pEmpleados[i].puesto, pEmpleados[i].sueldo);
			}
		}

		retorno = 0;
	}

	return retorno;
}
