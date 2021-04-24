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
	int idMascotas = 0;
	//int idRazas = 0;
	
	inicializarMascotas(arrayMascotas, CANT_MASCOTAS);
	inicializarRazas(arrayRazas, CANT_MASCOTAS);

	strncpy(arrayMascotas[0].nombre, "Pipo", sizeof(arrayMascotas[0].nombre));
	arrayMascotas[0].edad = 13;
	arrayMascotas[0].sexo = 1;
	arrayMascotas[0].tipo = 1;
	arrayMascotas[0].isEmpty = 0;
	arrayMascotas[0].idMascota = 1;
	strncpy(arrayRazas[0].descripcion, "siames", sizeof(arrayRazas[0].descripcion));
	arrayRazas[0].tamanio = 3;
	strncpy(arrayRazas[0].paisOrigen, "tailandia", sizeof(arrayRazas[0].paisOrigen));
	arrayRazas[0].isEmpty = 0;
	arrayRazas[0].idRaza = 1;
	idMascotas++;
	
	strncpy(arrayMascotas[1].nombre, "Lolo", sizeof(arrayMascotas[0].nombre));
	arrayMascotas[1].edad = 9;
	arrayMascotas[1].sexo = 2;
	arrayMascotas[1].tipo = 1;
	arrayMascotas[1].isEmpty = 0;
	arrayMascotas[1].idMascota = 2;
	strncpy(arrayRazas[1].descripcion, "doberman", sizeof(arrayRazas[0].descripcion));
	arrayRazas[1].tamanio = 2;
	strncpy(arrayRazas[1].paisOrigen, "alemania", sizeof(arrayRazas[0].paisOrigen));
	arrayRazas[1].isEmpty = 0;
	arrayRazas[1].idRaza = 2;
	idMascotas++;
	
	strncpy(arrayMascotas[2].nombre, "Iris", sizeof(arrayMascotas[0].nombre));
	arrayMascotas[2].edad = 7;
	arrayMascotas[2].sexo = 1;
	arrayMascotas[2].tipo = 1;
	arrayMascotas[2].isEmpty = 0;
	arrayMascotas[2].idMascota = 3;
	strncpy(arrayRazas[2].descripcion, "persa", sizeof(arrayRazas[0].descripcion));
	arrayRazas[2].tamanio = 1;
	strncpy(arrayRazas[2].paisOrigen, "persia", sizeof(arrayRazas[0].paisOrigen));
	arrayRazas[2].isEmpty = 0;
	arrayRazas[2].idRaza = 3;
	idMascotas++;
	
	strncpy(arrayMascotas[3].nombre, "Negro", sizeof(arrayMascotas[0].nombre));
	arrayMascotas[3].edad = 8;
	arrayMascotas[3].sexo = 2;
	arrayMascotas[3].tipo = 3;
	arrayMascotas[3].isEmpty = 0;
	arrayMascotas[3].idMascota = 4;
	strncpy(arrayRazas[3].descripcion, "pastor belga", sizeof(arrayRazas[0].descripcion));
	arrayRazas[3].tamanio = 1;
	strncpy(arrayRazas[3].paisOrigen, "bélgica", sizeof(arrayRazas[0].paisOrigen));
	arrayRazas[3].isEmpty = 0;
	arrayRazas[3].idRaza = 4;
	idMascotas++;

	strncpy(arrayMascotas[4].nombre, "Sara", sizeof(arrayMascotas[0].nombre));
	arrayMascotas[4].edad = 4;
	arrayMascotas[4].sexo = 2;
	arrayMascotas[4].tipo = 2;
	arrayMascotas[4].isEmpty = 0;
	arrayMascotas[4].idMascota = 5;
	strncpy(arrayRazas[4].descripcion, "bengala", sizeof(arrayRazas[0].descripcion));
	arrayRazas[4].tamanio = 3;
	strncpy(arrayRazas[4].paisOrigen, "EEUU", sizeof(arrayRazas[0].paisOrigen));
	arrayRazas[4].isEmpty = 0;
	arrayRazas[4].idRaza = 5;
	idMascotas++;

	mostrarRazas(arrayRazas, CANT_MASCOTAS);



	do
	{
		utn_getNumero(&opcionMenu, "1) Cargar mascota\n2) Borrar mascota\n3) Cargar raza\n4) Lista mascotas\n5) Lista razas\n", "Error. Ingrese un número de los del menú\n", 1, 7, 3);

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
				altaRaza(arrayRazas, buscarIndiceVacioRaza(arrayRazas, CANT_MASCOTAS));
				break;
			}
			case 4:
			{
				mostrarMascotas(arrayMascotas, arrayRazas, CANT_MASCOTAS);
				break;
			}
			case 5:
			{
				mostrarRazas(arrayRazas, CANT_MASCOTAS);
				break;
			}
			case 6:
			{
				break;
			}
		}
	}while(opcionMenu != 7);


	/*for(int i = 0; i < CANT_MASCOTAS; i++)
	{
		printf("\nNombre: %s - Edad: %d - Sexo: %s - Tipo: %s - Descripción: %s - Tamaño: %s - Pais de origen: %s\n", arrayMascotas[i].nombre, arrayMascotas[i].edad, arrayMascotas[i].sexo, arrayMascotas[i].tipo, arrayRazas[i].descripcion, arrayRazas[i].tamanio, arrayRazas[i].paisOrigen);
	}*/

	return EXIT_SUCCESS;
}
