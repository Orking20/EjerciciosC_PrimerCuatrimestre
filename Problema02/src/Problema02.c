/*
 ============================================================================
 Name        : Problema02.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Ingresar números enteros, hasta que el usuario lo decida. Calcular y mostrar:
				a) El promedio de los números positivos.
				b) El promedio de los números negativos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int numeroIngresados;
	char continuar;
	int sumaPositivos;
	int sumaNegativos;
	int contPositivos;
	int contNegativos;
	float promedioPositivos;
	float promedioNegativos;

	sumaPositivos = 0;
	sumaNegativos = 0;
	contPositivos = 0;
	contNegativos = 0;

	do
	{
		printf("Ingrese un número: ");
		scanf("%d", &numeroIngresados);

		if(numeroIngresados > 0)
		{
			contPositivos++;
			sumaPositivos += numeroIngresados;
		}
		else
		{
			contNegativos++;
			sumaNegativos += numeroIngresados;
		}

		printf("¿Desea continuar ingrsando números (s/n)? ");
		__fpurge(stdin);
		scanf("%c", &continuar);
	}while(continuar == 's');

	if(contPositivos > 0)
	{
		promedioPositivos = (float)sumaPositivos / contPositivos;
	}
	else
	{
		promedioPositivos = 0;
	}
	if(contNegativos > 0)
	{
		promedioNegativos = (float)sumaNegativos / contNegativos;
	}
	else
	{
		promedioNegativos = 0;
	}

	printf("Promedio de números positivos: %0.2f\n", promedioPositivos);
	printf("Promedio de números negativos: %0.2f\n", promedioNegativos);

	return EXIT_SUCCESS;
}
