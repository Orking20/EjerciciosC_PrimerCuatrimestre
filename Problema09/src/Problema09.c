/*
 ============================================================================
 Name        : Problema09.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : En una tienda de artículos para caballeros al final del día se carga en
 	 	 	   la computadora las boletas que confeccionaron los distintos vendedores
 	 	 	   para saber cuánto fue la comisión del día de cada uno de ellos.
 	 	 	   Los datos que se ingresan (por boleta) son: el número de vendedor y el importe.
 	 	 	   Cuando no hay más boletas para cargar se ingresa 0. Teniendo en cuenta que
 	 	 	   el negocio tiene 3 vendedores y que el porcentaje sobre las ventas es del 5%,
 	 	 	   indicar cuánto ganó cada vendedor en el día
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int main(void)
{
	int opcionVendedor;
	float importe;
	float importeVendedor1 = 0;
	float importeVendedor2 = 0;
	float importeVendedor3 = 0;
	int opcionMenu;
	int comprobador;

	do
	{
		printf("1) Ingresar boleta\n0) Salir\n");
		__fpurge(stdin);
		comprobador = scanf("%d", &opcionMenu);
		while(comprobador == 0 || opcionMenu < 0 || opcionMenu > 1)
		{
			printf("\nError. Ingrese el número correspondiente a la opción que desea\n");
			printf("1) Ingresar boleta\n0) Salir\n");
			__fpurge(stdin);
			comprobador = scanf("%d", &opcionMenu);
		}

		if(opcionMenu == 1)
		{
			printf("\nElija un vendedor:\n1) 045\n2) 052\n3) 010\n");
			__fpurge(stdin);
			comprobador = scanf("%d", &opcionVendedor);
			while(comprobador == 0 || opcionVendedor < 1 || opcionVendedor > 3)
			{
				printf("\nError. Ingrese el número correspondiente a la opción que desea\n");
				printf("\nElija un vendedor:\n1) 045\n2) 052\n3) 010\n");
				__fpurge(stdin);
				comprobador = scanf("%d", &opcionVendedor);
			}

			switch(opcionVendedor)
			{
				case 1:
				{
					printf("\nIngrese el importe de esta boleta: ");
					__fpurge(stdin);
					comprobador = scanf("%f", &importe);
					while(comprobador == 0 || importe < 1)
					{
						printf("\nError. Ingrese el importe de la boleta\n");
						printf("\nIngrese el ingreso de esta boleta: ");
						__fpurge(stdin);
						comprobador = scanf("%f", &importe);
					}
					importeVendedor1 += importe;
					break;
				}
				case 2:
				{
					printf("\nIngrese el importe de esta boleta: ");
					__fpurge(stdin);
					comprobador = scanf("%f", &importe);
					while(comprobador == 0 || importe < 1)
					{
						printf("\nError. Ingrese el importe de la boleta\n");
						printf("\nIngrese el ingreso de esta boleta: ");
						__fpurge(stdin);
						comprobador = scanf("%f", &importe);
					}
					importeVendedor2 += importe;
					break;
				}
				case 3:
				{
					printf("\nIngrese el importe de esta boleta: ");
					__fpurge(stdin);
					comprobador = scanf("%f", &importe);
					while(comprobador == 0 || importe < 1)
					{
						printf("\nError. Ingrese el importe de la boleta\n");
						printf("\nIngrese el ingreso de esta boleta: ");
						__fpurge(stdin);
						comprobador = scanf("%f", &importe);
					}
					importeVendedor3 += importe;
					break;
				}
			}
		}

	}while(opcionMenu != 0);

	importeVendedor1 = (importeVendedor1 * 5) / 100;
	importeVendedor2 = (importeVendedor2 * 5) / 100;
	importeVendedor3 = (importeVendedor3 * 5) / 100;

	printf("El primer vendedor ganó %0.2f\n", importeVendedor1);
	printf("El segundo vendedor ganó %0.2f\n", importeVendedor2);
	printf("El tercer vendedor ganó %0.2f\n", importeVendedor3);

	return EXIT_SUCCESS;
}
