/*
 ============================================================================
 Name        : Clase8_Ej1.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Realizar una agenda para guardar los datos de hasta 200 personas de las cuales se toman
 	 	 	   los siguientes datos (utilizar una estructura para representar a la persona):
 	 	 	   Nombre - Apellido - Legajo (NO SE PUEDE REPETIR)
 	 	 	   a- Realizar un programa con un menú de opciones para hacer altas , bajas y modificaciones (ABM) de una agenda.
 	 	 	   b- Mostrar un listado ordenado por Apellido
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Persona.h"
#include "utn.h"
#define TAM_ARRAY 100
#define CANT_PERSONAS 200

int main(void)
{
	Persona arrayPersonas[CANT_PERSONAS];
	inicializarPersonas(arrayPersonas, CANT_PERSONAS);
	int opcionMenu;

	do
	{
		utn_getNumero(&opcionMenu, "1) Mostrar personas\n2) Agregar/modificar persona\n3) Eliminar persona\n4) Salir\n", "Error. Debe ingresar un número según las opciónes del menú\n", 1, 5, 5);

		switch(opcionMenu)
		{
			case 1:
			{
				ordenarPersonas(arrayPersonas, CANT_PERSONAS);
				mostrarPersonas(arrayPersonas, CANT_PERSONAS);
				break;
			}
			case 2:
			{
				cargarPersonas(arrayPersonas, CANT_PERSONAS, buscarIndiceVacio(arrayPersonas, CANT_PERSONAS));
				break;
			}
			case 3:
			{
				eliminarPersonas(arrayPersonas, CANT_PERSONAS);
				break;
			}
		}
	}while(opcionMenu != 4);

	return EXIT_SUCCESS;
}
