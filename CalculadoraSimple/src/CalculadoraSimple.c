/*
 ============================================================================
 Name        : CalculadoraSimple.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Pedir un número, después un operador y por último otro número.
 	 	 	   Según la operación asignada se llamará a una función.
 	 	 	   Mostrar al usuario el resultado.
 	 	 	   En la función dividir, validar divisiones por 0.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int sumar(int a, int b);
int restar(int a, int b);
int multiplicar(int a, int b);
float dividir(int a, int b, float* resultadoFinal);

int main(void)
{
	int numero1;
	int numero2;
	char operador;
	float resultadoFinal;
	int errorDivCero;

	printf("Ingrese un número: \n");
	scanf("%d", &numero1);
	printf("Ingrese un operador (+ - * /): \n");
	__fpurge(stdin);
	scanf("%c", &operador);
	printf("Ingrese otro número: \n");
	scanf("%d", &numero2);

	switch(operador)
	{
		case '+':
		{
			resultadoFinal = sumar(numero1, numero2);
			printf("El resultado es: %0.2f", resultadoFinal);
			break;
		}
		case '-':
		{
			resultadoFinal = restar(numero1, numero2);
			printf("El resultado es: %0.2f", resultadoFinal);
			break;
		}
		case '*':
		{
			resultadoFinal = multiplicar(numero1, numero2);
			printf("El resultado es: %0.2f", resultadoFinal);
			break;
		}
		case '/':
		{
			errorDivCero = dividir(numero1, numero2, &resultadoFinal);
			printf("%d", errorDivCero);

			if(errorDivCero == 1)
			{
				printf("Error. No se puede dividir por cero.\n");
			}
			else
			{
				printf("El resultado es: %0.2f", resultadoFinal);
			}

			break;
		}
	}

	return EXIT_SUCCESS;
}

int sumar(int a, int b)
{
	int resultado;

	resultado = a + b;

	return resultado;
}

int restar(int a, int b)
{
	int resultado;

	resultado = a - b;

	return resultado;
}

int multiplicar(int a, int b)
{
	int resultado;

	resultado = a * b;

	return resultado;
}

float dividir(int a, int b, float* direccionResultadoFinal)
{
	float resultado;
	int huboError;

	if(b != 0)
	{
		resultado = (float)a / b;
		*direccionResultadoFinal = resultado;
		huboError = 0;
	}
	else
	{
		huboError = 1;
	}

	return huboError;
}
