/*
 ============================================================================
 Name        : Examen1.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Primer exámen de Programación y Laboratorio 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Automovil.h"
#include "utn.h"
#include "Propietario.h"
#include "Relacion.h"
#define CANT_PROPIETARIO 100
#define CANT_AUTOMOVIL 1000

int main(void)
{
	Propietario arrayPropietarios[CANT_PROPIETARIO];
	Automovil arrayContrataciones[CANT_AUTOMOVIL];
	int opcionMenu;

	inicializarPantalla(arrayPropietarios, CANT_PROPIETARIO);
	inicializarContratacion(arrayContrataciones, CANT_AUTOMOVIL);

	do
	{
		utn_getNumero(&opcionMenu, "\n1) Cargar pantalla\n2) Modificar pantalla\n3) Borrar pantalla\n4) Contratar publicidad\n5) Modificar condiciones de publicacion\n6) Cancelar contratación\n7) Listar pagos\n8) Listar contrataciones\n9) Listar pantallas\n10) Informe\n11) Salir\n", "Error. Ingrese un número de los del menú\n", 1, 11, 3);

		switch(opcionMenu)
		{
			case 1:
			{
				altaPropietario(arrayPropietarios, buscarIndiceVacioPropietario(arrayPropietarios, CANT_PROPIETARIO));
				break;
			}
			case 2:
			{
				modificarPropietario(arrayPropietarios, CANT_PROPIETARIO);

				break;
			}
			case 3:
			{
				bajaPropietario(arrayPropietarios, arrayContrataciones, CANT_PROPIETARIO);
				break;
			}
			case 4:
			{
				altaContratacion(arrayContrataciones, arrayPropietarios, buscarIndiceVacioContratacion(arrayContrataciones, CANT_AUTOMOVIL), CANT_PROPIETARIO);
				break;
			}
			case 5:
			{
				modificarContratacion(arrayContrataciones, arrayPropietarios, CANT_AUTOMOVIL);
				break;
			}
			case 6:
			{
				borrarContratacion(arrayContrataciones, arrayPropietarios, CANT_AUTOMOVIL);
				break;
			}
			case 7:
			{
				consultaFacturacion(arrayContrataciones, arrayPropietarios, CANT_AUTOMOVIL);
				break;
			}
			case 8:
			{
				mostrarContratacion(arrayContrataciones, arrayPropietarios, CANT_AUTOMOVIL);
				//listarContrataciones();
				break;
			}
			case 9:
			{
				mostrarPantalla(arrayPropietarios, CANT_PROPIETARIO);
				break;
			}
			case 10:
			{
				//Informe();
				break;
			}
		}
	}while(opcionMenu != 11);

	return EXIT_SUCCESS;
}
