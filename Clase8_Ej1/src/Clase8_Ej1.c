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
	char nombre[100];
	char apellido[100];
	int legajo;
	int indice;

	do
	{
		utn_getNumero(&opcionMenu, "1) Mostrar personas\n2) Agregar/modificar persona\n3) Eliminar persona\n4) Salir\n", "Error. Debe ingresar un número según las opciónes del menú\n", 1, 5, 5);

		switch(opcionMenu)
		{
			case 1:
			{
				ordenarPersonas(arrayPersonas, CANT_PERSONAS);
				mostrarPersonas(arrayPersonas, CANT_PERSONAS);
				for(int i = 0; i < CANT_PERSONAS; i++)
				{
					printf("APELLIDO %s\n", arrayPersonas[i].apellido);
				}
				for(int i = 0; i < CANT_PERSONAS; i++)
				{
					printf("NOMBRE %s\n", arrayPersonas[i].nombre);
				}
				break;
			}
			case 2:
			{
				utn_getNumero(&indice, "Ingrese la posición de la nueva persona: \n", "Hubo un error\n", 0, 200, 5);
				utn_getTexto(nombre, TAM_ARRAY, "Ingrese el nombre: \n", "Hubo un error\n");
				utn_getTexto(apellido, TAM_ARRAY, "Ingrese el apellido: \n", "Hubo un error\n");
				utn_getNumero(&legajo, "Ingrese el legajo: \n", "Hubo un error\n", 1, 10000, 5);

				for(int i = 0; i < CANT_PERSONAS; i++)
				{
					while(arrayPersonas[i].legajo == legajo)
					{
						printf("Error. Ese legajo ya existe.\n");
						utn_getNumero(&legajo, "Ingrese el legajo: \n", "Hubo un error\n", 1, 10000, 5);
						i = -1;
						break;
					}
				}

				cargarPersonas(arrayPersonas, CANT_PERSONAS, indice, nombre, apellido, legajo);
				break;
			}
			case 3:
			{
				utn_getNumero(&indice, "Ingrese la posición de la persona a eliminar: \n", "Hubo un error\n", 1, 10000, 5);
				cargarPersonas(arrayPersonas, CANT_PERSONAS, indice, "", "", 0);
				arrayPersonas[indice].isEmpty = 1;
				printf("Eliminado con éxito\n");
				break;
			}
		}
	}while(opcionMenu != 4);

	return EXIT_SUCCESS;
}
