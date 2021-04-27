/*
 ============================================================================
 Name        : ExamenGenerico.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Estructura2.h"
#include "Estructura.h"
#include "Relacion.h"
#define CANT_ESTRUCTURA 100
#define CANT_ESTRUCTURA2 100

int main(void)
{
	//Estructura arrayEstructuras[CANT_ESTRUCTURA];
	//Estructura2 arrayEstructuras2[CANT_ESTRUCTURA2];
	int opcionMenu;

	do
	{
		utn_getNumero(&opcionMenu, "\n1) Alta\n2) Modificar\n3) Baja\n4) Alta\n5) Modificar\n6) Baja\n7) Listar\n8) Listar\n9) Listar\n10) Informe\n11) Salir\n", "Error. Ingrese un número de los del menú\n", 1, 11, 3);

		switch(opcionMenu)
		{
			case 1:
			{
				//altaEstructura(arrayEstructuras, arrayEstructuras2, buscarIndiceVacioEstructura(arrayEstructuras, CANT_ESTRUCTURA), CANT_ESTRUCTURA2);
				//alta
				break;
			}
			case 2:
			{
				//modificar

				break;
			}
			case 3:
			{
				//baja
				break;
			}
			case 4:
			{
				//alta
				break;
			}
			case 5:
			{
				//modificar
				break;
			}
			case 6:
			{
				//baja
				break;
			}
			case 7:
			{
				//lista
				break;
			}
			case 8:
			{
				//lista
				break;
			}
			case 9:
			{
				//lista
				break;
			}
			case 10:
			{
				//Informe
				break;
			}
		}
	}while(opcionMenu != 11);

	return EXIT_SUCCESS;
}
