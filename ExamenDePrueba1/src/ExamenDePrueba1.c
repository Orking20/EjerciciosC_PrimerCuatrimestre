/*
 ============================================================================
 Name        : ExamenDePrueba1.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Exámen de prueba número 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Mascotas.h"
#include "Razas.h"
#include "Relacion.h"
#define CANT_MASCOTAS 10

int main(void)
{
	Mascota arrayMascotas[CANT_MASCOTAS];
	Raza arrayRazas[CANT_MASCOTAS];
	int opcionMenu;
	int cantPaises = 0;
	
	inicializarMascotas(arrayMascotas, CANT_MASCOTAS);
	inicializarRazas(arrayRazas, CANT_MASCOTAS);

	harcodeoMascotas(arrayMascotas, 5);
	harcodeoRazas(arrayRazas, 5);

	mostrarRazas(arrayRazas, CANT_MASCOTAS);

	do
	{
		utn_getNumero(&opcionMenu, "\n1) Cargar mascota\n2) Borrar mascota\n3) Modificar mascota\n4) Cargar raza\n5) Lista mascotas\n6) Lista razas\n7)\n9) Salir\n", "Error. Ingrese un número de los del menú\n", 1, 9, 3);

		switch(opcionMenu)
		{
			case 1:
			{
				altaMascota(arrayMascotas, arrayRazas, buscarIndiceVacioMascota(arrayMascotas, CANT_MASCOTAS), CANT_MASCOTAS);
				break;
			}
			case 2:
			{
				borrarMascota(arrayMascotas, arrayRazas, CANT_MASCOTAS);
				break;
			}
			case 3:
			{
				modificarMascota(arrayMascotas, arrayRazas, CANT_MASCOTAS);
				break;
			}
			case 4:
			{
				altaRaza(arrayRazas, buscarIndiceVacioRaza(arrayRazas, CANT_MASCOTAS), &cantPaises);
				break;
			}
			case 5:
			{
				mostrarMascotas(arrayMascotas, arrayRazas, CANT_MASCOTAS);
				break;
			}
			case 6:
			{
				mostrarRazas(arrayRazas, CANT_MASCOTAS);
				break;
			}
			case 7:
			{
				break;
			}
		}
	}while(opcionMenu != 9);

	return EXIT_SUCCESS;
}
