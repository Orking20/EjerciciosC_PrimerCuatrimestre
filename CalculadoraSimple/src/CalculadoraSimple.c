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

float sumar(float numeroA, float numeroB, float* resultado);
float restar(float numeroA, float numeroB, float* resultado);
float multiplicar(float numeroA, float numeroB, float* resultado);
float dividir(float numeroA, float numeroB, float* punteroResultado);

int main(void)
{
	float numeroA;
	float numeroB;
	char operador;
	float resultado;
	float respuestaFuncion;

	printf("\nIngrese un número: ");
	//__fpurge(stdin);
	scanf("%f", &numeroA);

	do
	{
		printf("\nIngrese el operador (+ - * /): ");
		__fpurge(stdin);
		scanf("%c", &operador);
	}while(operador != '+' && operador != '-' && operador != '*' && operador != '/');

	printf("\nIngrese otro número: ");
	//__fpurge(stdin);
	scanf("%f", &numeroB);

	switch(operador)
	{
		case '+':
		{
			respuestaFuncion = sumar(numeroA, numeroB, &resultado);
			break;
		}
		case '-':
		{
			respuestaFuncion = restar(numeroA, numeroB, &resultado);
			break;
		}
		case '*':
		{
			respuestaFuncion = multiplicar(numeroA, numeroB, &resultado);
			break;
		}
		case '/':
		{
			respuestaFuncion = dividir(numeroA, numeroB, &resultado);
			break;
		}
	}

	if(respuestaFuncion == 0)
	{
		printf("La respuesta es: %0.2f", resultado);
	}
	else
	{
		printf("Error. No se puede dividir por cero");
	}

	return EXIT_SUCCESS;
}

float sumar(float numeroA, float numeroB, float* punteroResultado)
{
	*punteroResultado = numeroA + numeroB;
	return 0;
}

float restar(float numeroA, float numeroB, float* punteroResultado)
{
	*punteroResultado = numeroA - numeroB;
	return 0;
}

float multiplicar(float numeroA, float numeroB, float* punteroResultado)
{
	*punteroResultado = numeroA * numeroB;
	return 0;
}

float dividir(float numeroA, float numeroB, float* punteroResultado)
{
	if(numeroB == 0)
	{
		return -1;
	}
	else
	{
		*punteroResultado = (float)numeroA / numeroB;
		return 0;
	}
}

