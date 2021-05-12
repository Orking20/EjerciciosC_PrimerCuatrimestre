/*
 ============================================================================
 Name        : EmpresaTextiles.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "Nacionalidad.h"
#include "utn.h"
#include "Producto.h"
#include "Relacion.h"
#define CANT_PRODUCTO 100
#define CANT_NACIONALIDAD 100

int main(void)
{
	int opcionMenu;
	Producto arrayProducto[CANT_PRODUCTO];
	Nacionalidad arrayNacionalidad[CANT_NACIONALIDAD];

	Producto_inicializar(arrayProducto, CANT_PRODUCTO);
	Nacionalidad_inicializar(arrayNacionalidad, CANT_NACIONALIDAD);

	do
	{
		utn_getNumero(&opcionMenu,  "\n\n1) Alta producto\n"
									"2) Baja producto\n"
									"3) Modificar producto\n"
									"4) Listado productos\n"
									"5) Listado ordenado por precio\n"
									"6) Listado ordenado por descripción\n",
									"\nError. Elija una de las opciónes del menú escribiendo el número correspondiente", 0, 6, 3);

		switch(opcionMenu)
		{
			case 1:
			{
				Producto_alta(arrayProducto, arrayNacionalidad, CANT_PRODUCTO, CANT_NACIONALIDAD, Producto_buscarIndiceVacio(arrayProducto, CANT_PRODUCTO));
				break;
			}
			case 2:
			{
				Producto_modificar(arrayProducto, arrayNacionalidad, CANT_PRODUCTO, CANT_NACIONALIDAD);

				break;
			}
			case 3:
			{
				Producto_baja(arrayProducto, arrayNacionalidad, CANT_PRODUCTO, CANT_NACIONALIDAD);
				break;
			}
			case 4:
			{
				Nacionalidad_alta(arrayNacionalidad, Nacionalidad_buscarIndiceVacio(arrayNacionalidad, CANT_NACIONALIDAD));
				break;
			}
			case 5:
			{
				Nacionalidad_modificar(arrayNacionalidad, CANT_NACIONALIDAD);
				break;
			}
			case 6:
			{
				Nacionalidad_baja(arrayNacionalidad, arrayProducto, CANT_NACIONALIDAD, CANT_PRODUCTO);
				break;
			}
		}
	}while(opcionMenu != 0);

	return EXIT_SUCCESS;
}
