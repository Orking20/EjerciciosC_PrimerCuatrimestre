/*
 ============================================================================
 Name        : DivisionPuntero.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

float dividir(float dividendo, float divisor, float* punteroResultado);

int main(void)
{
	float resultado;
	float dividendo;
	float divisor;
	char continuar;

	do
	{
		printf("\nEsciba el dividendo: ");
		__fpurge(stdin);
		scanf("%f", &dividendo);
		printf("\nEsciba el divisor: ");
		__fpurge(stdin);
		scanf("%f", &divisor);

		if(dividir(dividendo, divisor, &resultado) == 0)
		{
			printf("\nEl resultado es: %f", resultado);
		}
		else
		{
			printf("\nError. No se puede dividir por 0");
		}

		printf("\n¿Desea continuar dividiendo? (s/n) ");
		__fpurge(stdin);
		scanf("%c", &continuar);
	}while(continuar == 's');

	return EXIT_SUCCESS;
}

float dividir(float dividendo, float divisor, float* punteroResultado)
{
	if(divisor == 0) //Error division por 0
	{
		return -1;
	}
	else
	{
		*punteroResultado = (float)dividendo / divisor;
		return 0;
	}
}
