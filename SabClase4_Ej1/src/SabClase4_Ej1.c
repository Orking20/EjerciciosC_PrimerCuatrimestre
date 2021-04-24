/*
 ============================================================================
 Name        : SabClase4_Ej1.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Crear la estructura empleado con idEmpleado, nombre, sueldo y puesto (programador, analista, tester).
 	 	 	   Crear un menu con las siguientes opciones:
 	 	 	   1. Cargar empleados. Carga secuencial.
 	 	 	   2. Mostrar empleados. Ordenados por puesto.
 	 	 	   3. Mostrar solo los empleados analistas.
 	 	 	   4. Mostrar cuantos empleados tester hay.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "utn.h"
#define CANT_EMPLEADOS 5

int main(void)
{
	int opcionMenu;
	int flagCarga = 0;
	int cantTesters = 0;
	Empleado arrayEmpleados[CANT_EMPLEADOS];

	do
	{
		utn_getNumero(&opcionMenu, "\n1) Cargar empleados\n2) Mostrar empleados ordenador por puesto\n3) Mostrar solo analistas\n4) Mostrar cantidad de testers\n5) Salir\n", "Error. Ingrese una de las opciones del menú con los números", 1, 5, 3);

		switch(opcionMenu)
		{
			case 1:
			{
				for(int i = 0; i < CANT_EMPLEADOS; i++)
				{
					cargarEmpleados(arrayEmpleados, CANT_EMPLEADOS, i);
					if(arrayEmpleados[i].esTester)
					{
						cantTesters++;
					}
				}
				flagCarga = 1;

				ordenarPorPuestos(arrayEmpleados, CANT_EMPLEADOS);
				break;
			}
			case 2:
			{
				if(flagCarga)
				{
					mostrarEmpleados(arrayEmpleados, CANT_EMPLEADOS);
				}
				else
				{
					printf("Antes de mostrar los empleados hay que cargarlos\n");
				}
				break;
			}
			case 3:
			{
				if(flagCarga)
				{
					mostrarAnalistas(arrayEmpleados, CANT_EMPLEADOS);
				}
				else
				{
					printf("Antes de mostrar los empleados hay que cargarlos\n");
				}
				break;
			}
			case 4:
			{
				if(flagCarga)
				{
					printf("Cantidad de testers: %d", cantTesters);
				}
				else
				{
					printf("Antes de mostrar los empleados hay que cargarlos\n");
				}
				break;
			}
		}
	}while(opcionMenu != 5);

	return EXIT_SUCCESS;
}
