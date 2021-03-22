/*
 ============================================================================
 Name        : Problema01.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Ingresar 10 números enteros distintos de 0. Mostrar:
 	 	 	 a) Cantidad de pares e impares
 	 	 	 b) El menor número ingresado
 	 	 	 c) Suma de los positivos
 	 	 	 d) Producto de los negativos
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout, NULL);

	int numeroIngresado;
	int contadorPares;
	int contadorImpares;
	int minimo;
	int sumaPositivos;
	int productoNegativos;
	int ingresoNegativo;

	contadorPares = 0;
	contadorImpares = 0;
	sumaPositivos = 0;
	productoNegativos = 1;
	ingresoNegativo = 0;

	for(int i = 0; i < 10; i++)
	{
		printf("Ingrese un número: ");
		scanf("%d", &numeroIngresado);
		while(numeroIngresado == 0)
		{
			printf("Error. Solo se pueden ingresar números distintos de 0. Ingrese un número nuevamente: ");
			scanf("%d", &numeroIngresado);
		}
		//a)
		if(numeroIngresado % 2 == 0)
		{
			contadorPares++;
		}
		else
		{
			contadorImpares++;
		}
		//b)
		if(i == 0 || numeroIngresado < minimo)
		{
			minimo = numeroIngresado;
		}
		//c)
		if(numeroIngresado > 0)
		{
			sumaPositivos += numeroIngresado;
		}
		else
		{
			ingresoNegativo = 1;
			productoNegativos *= numeroIngresado;
		}
	}

	printf("Cantidad de números pares: %d\nCantidad de impares: %d\n", contadorPares, contadorImpares);
	printf("El menor número ingresado es: %d\n", minimo);
	printf("La suma de los positivos es: %d\n", sumaPositivos);
	if(ingresoNegativo == 1)
	{
		printf("El producto de los negativos es: %d\n", productoNegativos);
	}
	else
	{
		printf("El producto de los negativos es: 0");
	}

	return EXIT_SUCCESS;
}
