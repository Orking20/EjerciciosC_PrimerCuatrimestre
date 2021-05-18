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
#include <string.h>
#include "Nacionalidad.h"
#include "utn.h"
#include "Producto.h"
#include "Nacionalidad.h"
#include "Tipo.h"
#define CANT_PRODUCTO 100
#define CANT_NACIONALIDAD 100

int main(void)
{
	int opcionMenu;
	Producto* auxProducto[CANT_PRODUCTO];

	producto_inicializar(auxProducto, CANT_PRODUCTO);

	do
	{
		utn_getNumero(&opcionMenu,  "\n\n1) Alta producto\n"
									"2) Baja producto\n"
									"3) Modificar producto\n"
									"4) Listado productos\n"
									"5) Listado ordenado por precio\n"
									"6) Listado ordenado por descripción\n"
									"0) Salir",
									"\nError. Elija una de las opciónes del menú escribiendo el número correspondiente", 0, 6, 3);

		switch(opcionMenu)
		{
			case 1:
			{
				producto_alta(auxProducto, CANT_PRODUCTO);
				break;
			}
			case 2:
			{
				producto_baja(auxProducto, CANT_PRODUCTO);
				break;
			}
			case 3:
			{
				producto_modificar(auxProducto, CANT_PRODUCTO);
				break;
			}
			case 4:
			{
				producto_ordenarPorId(auxProducto, CANT_PRODUCTO);
				producto_listado(auxProducto, CANT_PRODUCTO);
				break;
			}
			case 5:
			{
				producto_ordenarPorPrecio(auxProducto, CANT_PRODUCTO);
				break;
			}
			case 6:
			{
				producto_ordenarPorDescripcion(auxProducto, CANT_PRODUCTO);
				break;
			}
		}
	}while(opcionMenu != 0);

	return EXIT_SUCCESS;
}
