/*
 ============================================================================
 Name        : PrimerExamenMemoriaDinamica.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Compra.h"
#include "Relacion.h"
#include "Informes.h"
#include "utn.h"
int main(void)
{
	int opcionMenu;
	int cantClientes = 100;
	int cantCompras = 1000;
	Cliente* arrayClientes[cantClientes];
	Compra* arrayCompras[cantCompras];

	cliente_inicializar(arrayClientes, cantClientes);
	compra_inicializar(arrayCompras, cantCompras);
	cliente_harcodeo(arrayClientes, 3);
	compra_harcodeo(arrayCompras, 7);

	do
	{
		utn_getNumero(&opcionMenu,  "\n\n1) Alta cliente\n"
									"2) Modificar datos de cliente\n"
									"3) Baja cliente\n"
									"4) Realizar compra\n"
									"5) Pagar compra\n"
									"6) Cancelar compra\n"
									"7) Mostrar clientes\n"
									"8) Informe\n"
									"0) Salir\n",
									"\nError. Elija una de las opciónes del menú escribiendo el número correspondiente", 0, 8, 3);

		switch(opcionMenu)
		{
			case 1:
			{
				cliente_alta(arrayClientes, cliente_buscarIndiceVacio(arrayClientes, cantClientes));
				break;
			}
			case 2:
			{
				cliente_modificar(arrayClientes, cantClientes);
				break;
			}
			case 3:
			{
				cliente_baja(arrayClientes, arrayCompras, cantClientes, cantCompras);
				break;
			}
			case 4:
			{
				compra_alta(arrayCompras, arrayClientes, cantCompras, cantClientes, compra_buscarIndiceVacio(arrayCompras, cantCompras));
				break;
			}
			case 5:
			{
				compra_pagarImporte(arrayCompras, arrayClientes, cantCompras, cantClientes);
				break;
			}
			case 6:
			{
				compra_baja(arrayCompras, arrayClientes, cantCompras, cantClientes);
				break;
			}
			case 7:
			{
				info_mostrarTodo(arrayClientes, arrayCompras, cantClientes, cantCompras);
				break;
			}
			case 8:
			{
				info_mostrarInformes(arrayCompras, cantCompras);
				break;
			}
		}
	}while(opcionMenu != 0);

	return EXIT_SUCCESS;
}
