/*
 ============================================================================
 Name        : SabClase4_Ej2.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Una empresa importadora que comercializa productos Apple,
 	 	 	   decide registrar de sus productos los siguientes datos:
 	 	 	   1. idProducto (numerico)
 	 	 	   2. descripcion (alfanumérico)
 	 	 	   3. nacionalidad (numérico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
 	 	 	   4. tipo (numérico, por el momento utilizaremos un define: IPHONE - MAC - IPAD - ACCESORIOS)
 	 	 	   5. precio (numérico decimal)
 	 	 	   Realizar un programa que permita interactuar con un menú de usuarios con las siguientes opciones:
 	 	 	   1. ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando
 	 	 	   haya espacio disponible en el array.
 	 	 	   2. BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de
 	 	 	   la lista, dejando espacio disponible para un nuevo producto.
 	 	 	   3. MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá
 	 	 	   modificar el precio o el tipo.
 	 	 	   4. LISTADO Productos.
 	 	 	   5. LISTADO ordenado por precio.
 	 	 	   6. LISTADO ordenado por descripción.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Producto.h"
#define CANT_PRODUCTOS 200
#define EEUU 1
#define CHINA 2
#define OTRO 3
#define IPHONE 1
#define MAC 2
#define IPAD 3
#define ACCESORIOS 4

int main(void)
{
	int opcionMenu;
	int flagPrimeraCarga = 0;
	Producto aProductos[CANT_PRODUCTOS];

	inicializarProductos(aProductos, CANT_PRODUCTOS);

	do
	{
		printf("\n1) Cargar producto\n2) Eliminar producto\n3) Modificar producto\n4) Listado productos\n5) Listado ordenado por precio\n6) Listado ordenado por descripción\n7) Salir\n");
		utn_getNumero(&opcionMenu, "\nElija una opción del menú: ", "\nError. Las opciones del menú se eljien escribiendo el número al lado de cada opción", 1, 7, 3);

		switch(opcionMenu)
		{
			case 1:
			{
				cargarProductos(aProductos, buscarIndiceVacio(aProductos, CANT_PRODUCTOS));
				flagPrimeraCarga = 1;
				break;
			}
			case 2:
			{
				if(flagPrimeraCarga)
				{
					eliminarProducto(aProductos, CANT_PRODUCTOS);
				}
				else
				{
					printf("\nNo hay ningún producto cargado");
				}
				break;
			}
			case 3:
			{
				if(flagPrimeraCarga)
				{
					modificarProducto(aProductos, CANT_PRODUCTOS);
					flagPrimeraCarga = 1;
				}
				else
				{
					printf("\nNo hay ningún producto cargado");
				}
				break;
			}
			case 4:
			{
				if(flagPrimeraCarga)
				{
					ordenadoId(aProductos, CANT_PRODUCTOS);
					flagPrimeraCarga = 1;
				}
				else
				{
					printf("\nNo hay ningún producto cargado");
				}
				break;
			}
			case 5:
			{
				if(flagPrimeraCarga)
				{
					ordenadoPrecio(aProductos, CANT_PRODUCTOS);
					flagPrimeraCarga = 1;
				}
				else
				{
					printf("\nNo hay ningún producto cargado");
				}
				break;
			}
			case 6:
			{
				if(flagPrimeraCarga)
				{
					ordenadoDescripcion(aProductos, CANT_PRODUCTOS);
					flagPrimeraCarga = 1;
				}
				else
				{
					printf("\nNo hay ningún producto cargado");
				}
				break;
			}
		}
	}while(opcionMenu != 7);

	return EXIT_SUCCESS;
}
