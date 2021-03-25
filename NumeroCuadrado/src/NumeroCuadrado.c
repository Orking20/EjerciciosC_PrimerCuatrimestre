/*
 ============================================================================
 Name        : NumeroCuadrado.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Escribir el programa necesario para calcular y mostrar el
 	 	 	   cuadrado de un número. El número debe ser mayor que cero,
 	 	 	   en caso de error que aparezca el mensaje "ERROR,
 	 	 	   el número debe ser mayor que cero"
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int numero;

	printf("Ingrese un número: ");
	scanf("%d", &numero);

	if(numero < 0)
	{
		printf("Error! el número debe ser mayor que cero");
	}
	else
	{
		printf("El cuadrado de %d es %d", numero, numero * numero);
	}

	return EXIT_SUCCESS;
}
