/*
 ============================================================================
 Name        : NumeroMayor.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Diseñar en un programa que permita registrar de los empleados
 	 	 	   de una fábrica (no se sabe cuántos) su peso y saber cuántos
 	 	 	   pesan hasta 80 kg. inclusive y cuantos pesan más de 80 kg.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int main(void)
{
	int peso;
	int cantPesoDebajoOchenta;
	int cantPesoMayorOchenta;
	char continuar;

	cantPesoMayorOchenta = 0;

	do
	{
		printf("Ingrese el peso: ");
		scanf("%d", &peso);

		if(peso > 80)
		{
			cantPesoMayorOchenta++;
		}
		else
		{
			cantPesoDebajoOchenta++;
		}

		printf("¿Desea registrar otro empleado (s/n)? ");
		__fpurge(stdin);
		scanf("%c", &continuar);
	}while(continuar == 's');

	printf("Empleados con 80 kg. o menos: %d\n", cantPesoDebajoOchenta);
	printf("Empleados con más de 80 Kg.: %d", cantPesoMayorOchenta);

	return EXIT_SUCCESS;
}
