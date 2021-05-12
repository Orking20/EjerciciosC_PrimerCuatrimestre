/*
 ============================================================================
 Name        : ExamenGenerico2.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Estructura.h"
#include "Entidad.h"
#include "Relacion.h"
#define CANT_ESTRUCTURA 100
#define CANT_ENTIDAD 100

int main(void)
{
	int opcionMenu;
	Estructura arrayEstructura[CANT_ESTRUCTURA];
	Entidad arrayEntidad[CANT_ENTIDAD];

	estructura_inicializar(arrayEstructura, CANT_ESTRUCTURA);
	entidad_inicializar(arrayEntidad, CANT_ENTIDAD);

	do
	{
		utn_getNumero(&opcionMenu,  "\n\n1) Alta\n"
									"2) Modificar\n"
									"3) Baja\n"
									"4) Alta\n"
									"5) Modificar\n"
									"6) Baja\n"
									"7) Listar\n"
									"8) Listar\n"
									"9) Listar\n"
									"10) Informe\n"
									"0) Salir\n",
									"\nError. Elija una de las opciónes del menú escribiendo el número correspondiente", 0, 10, 3);

		switch(opcionMenu)
		{
			case 1:
			{
				estructura_alta(arrayEstructura, arrayEntidad, CANT_ESTRUCTURA, CANT_ENTIDAD, estructura_buscarIndiceVacio(arrayEstructura, CANT_ESTRUCTURA));
				break;
			}
			case 2:
			{
				estructura_modificar(arrayEstructura, arrayEntidad, CANT_ESTRUCTURA, CANT_ENTIDAD);

				break;
			}
			case 3:
			{
				estructura_baja(arrayEstructura, arrayEntidad, CANT_ESTRUCTURA, CANT_ENTIDAD);
				break;
			}
			case 4:
			{
				entidad_alta(arrayEntidad, entidad_buscarIndiceVacio(arrayEntidad, CANT_ENTIDAD));
				break;
			}
			case 5:
			{
				entidad_modificar(arrayEntidad, CANT_ENTIDAD);
				break;
			}
			case 6:
			{
				entidad_baja(arrayEntidad, arrayEstructura, CANT_ENTIDAD, CANT_ESTRUCTURA);
				break;
			}
			case 7:
			{
				estructura_mostrar(arrayEstructura, arrayEntidad, CANT_ESTRUCTURA, CANT_ENTIDAD);
				break;
			}
			case 8:
			{
				entidad_mostrar(arrayEntidad, CANT_ENTIDAD);
				break;
			}
			case 9:
			{
				//lista
				break;
			}
			case 10:
			{

				break;
			}
		}
	}while(opcionMenu != 0);

	return EXIT_SUCCESS;
}
