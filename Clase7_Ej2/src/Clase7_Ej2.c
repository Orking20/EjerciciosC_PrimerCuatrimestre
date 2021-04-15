/*
 ============================================================================
 Name        : Clase7_Ej2.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Crear un programa que permita registrar el valor de temperatura máxima de cada día de un
 	 	 	   mes. Definir un array de floats de 31 posiciones. Cada posición corresponderá a un día del
 	 	 	   mes. Deberá tener un menú con 2 opciones, 1.Imprimir array y 2.Cargar array.
 	 	 	   Al elegir la opción 1, se imprimirá el índice y el valor de cada posición del array.
 	 	 	   Al elegir la opción 2, que le pida al usuario que ingrese un número de día (1 a 31) y luego
 	 	 	   que ingrese un valor de temperatura. Almacenar el valor en el índice correspondiente.
 	 	 	   Ambas opciones deben volver al menú principal. Utilizar la función utn_getFloat() de utn.h
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define DIAS_DEL_MES 31

int main(void)
{
	float dias[31];
	int opcionMenu;
	int indice;
	float temperatura;

	for(int i = 0; i < DIAS_DEL_MES; i++)
	{
		dias[i] = 0.00;
	}

	while(1)
	{
		/*printf("1. Imprimir array\n2. Cargar array\n");
		scanf("%d", &opcionMenu);
		while(opcionMenu != 1 && opcionMenu != 2)
		{
			printf("1. Imprimir array\n2. Cargar array\n");
			scanf("%d", &opcionMenu);
		}*/

		utn_getNumero(&opcionMenu, "1. Imprimir array\n2. Cargar array\n", "Error. Ingrese 1 o 2 según lo que desea\n", 1, 2, 5);

		switch(opcionMenu)
		{
			case 1:
			{
				for(int i = 0; i < DIAS_DEL_MES; i++)
				{
					printf("Día %d: %0.2f\n", i + 1, dias[i]);
				}
				break;
			}
			case 2:
			{
				utn_getNumero(&indice, "Ingrese el día [1-31]: \n", "Hubo un error", 1, 31, 3);
				utn_getFloat(&temperatura, "Ingrese la temperatura: \n", "Hubo un error", -60, 60, 3);

				dias[indice - 1] = temperatura;
				break;
			}
		}
	}

	return EXIT_SUCCESS;
}
