/*
 ============================================================================
 Name        : CicloPositivosNegativos.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Clase 01 - Ejercicio 04
 	 	 	   - Solicite al usuario 10 números
			   - Calcule cuántos son negativos y cuantos son positivos
			   - Muestre por pantalla la cantidad de negativos y la cantidad de positivos

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int numeroIngresado;
	int positivos = 0;
	int negativos = 0;

	for(int i = 0; i < 10; i++)
	{
		printf("Ingrese un número: \n");
		scanf("%d", &numeroIngresado);
		if(numeroIngresado > 0)
		{
			positivos++;
		}
		else if(numeroIngresado < 0)
		{
			negativos++;
		}
	}

	printf("\nCantidad de positivos: %d", positivos);
	printf("\nCantidad de negativos: %d", negativos);

	return EXIT_SUCCESS;
}
