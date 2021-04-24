/*
 ============================================================================
 Name        : Clase9_Ej1.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : 1) Definir un tipo de dato que represente un producto. El producto tiene un nombre, una descripcion y un precio
 	 	 	   2) Definir un array de 200 productos, indicar de alguna manera que la info de cada item no esta cargada.
 	 	 	   3) Realizar una funcion que reciba el array, un indice, y le permita al usuario cargar los datos en el
 	 	 	   item de la posicion especificada por el indice.
 	 	 	   4) Realizar una funcion que reciba el array y un indice e imprima los
 	 	 	   datos del item de la posicion especificada por el indice.
 	 	 	   5) Realizar una funcion que me devuelva el indice de un item vacio (sin cargar).
 	 	 	   6) Realizar un menu con dos opciones: Cargar un producto e Imprimir lista productos
 	 	 	   7) Agregar al tipo de dato el campo ID que represente un identificador unico.
 	 	 	   Modificar el codigo anterior para que el ID se genere automaticamente. Se debera cargar el
 	 	 	   ID automaticamente al cargar un producto, y se debera imprimir al imprimir la lista.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Producto.h"
#define CANT_PRODUCTOS 200
#define TAM_NOMBRE 50
#define TAM_DESCRIPCION 200

int main(void)
{
	Producto productos[CANT_PRODUCTOS];
	int opcionMenu;
	inicializarProductos(productos, CANT_PRODUCTOS);

	do
	{
		utn_getNumero(&opcionMenu, "\n1) Ver productos\n2) Cargar producto\n3) Salir\n", "Error. Eliga una de las opciónes del menú\n", 1, 3, 5);

		switch(opcionMenu)
		{
			case 1:
			{
				mostrarProductos(productos, CANT_PRODUCTOS);
				break;
			}
			case 2:
			{
				cargarProductos(productos, buscarIndiceVacio(productos, CANT_PRODUCTOS));
				break;
			}
		}
	}while(opcionMenu != 3);

	return EXIT_SUCCESS;
}

