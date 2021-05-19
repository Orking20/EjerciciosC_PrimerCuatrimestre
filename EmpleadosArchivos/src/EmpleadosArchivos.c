/*
 ============================================================================
 Name        : EmpleadosArchivos.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Empleado.h"
#include "utn.h"
#define CANT_EMPLEADO 100

int main(void)
{
	int opcionMenu;
	Empleado* auxEmpleado[CANT_EMPLEADO];

	empleado_inicializar(auxEmpleado, CANT_EMPLEADO);
	empleado_establecerDatos(auxEmpleado, CANT_EMPLEADO);

	do
	{
		utn_getNumero(&opcionMenu,  "\n\n1) Alta producto\n"
									"2) Baja producto\n"
									"3) Modificar producto\n"
									"4) Listado productos\n"
									"5) Guardar cambios\n"
									"6) Listado ordenado por descripción\n"
									"0) Salir",
									"\nError. Elija una de las opciónes del menú escribiendo el número correspondiente", 0, 6, 3);

		switch(opcionMenu)
		{
			case 1:
			{
				empleado_alta(auxEmpleado, CANT_EMPLEADO);
				break;
			}
			case 2:
			{
				empleado_baja(auxEmpleado, CANT_EMPLEADO);
				break;
			}
			case 3:
			{
				empleado_modificar(auxEmpleado, CANT_EMPLEADO);
				break;
			}
			case 4:
			{
				empleado_listado(auxEmpleado, CANT_EMPLEADO);
				break;
			}
			case 5:
			{
				empleado_guardarCambios(auxEmpleado, CANT_EMPLEADO);
				break;
			}
			case 6:
			{
				empleado_ordenarPorNombre(auxEmpleado, CANT_EMPLEADO);
				break;
			}
		}
	}while(opcionMenu != 0);

	return EXIT_SUCCESS;
}
