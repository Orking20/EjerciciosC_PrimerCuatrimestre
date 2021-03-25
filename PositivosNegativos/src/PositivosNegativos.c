/*
 ============================================================================
 Name        : PositivosNegativos.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : De 10 números ingresados indicar cuantos son mayores a cero
 	 	 	   y cuantos son menores a cero
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int numero;
	int contPositivos;
	int contNegativos;

	contPositivos = 0;
	contNegativos = 0;

	for(int i = 0; i < 10; i++)
	{
		printf("Ingrese un número: ");
		scanf("%d", &numero);

		if(numero > 0)
		{
			contPositivos++;
		}
		else if(numero < 0)
		{
			contNegativos++;
		}
	}

	printf("\nCantidad de números positivos: %d\nCantidad de números negativos: %d", contPositivos, contNegativos);

	return EXIT_SUCCESS;
}
