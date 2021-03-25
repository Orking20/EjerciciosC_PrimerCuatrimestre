/*
 * utn.c
 *
 *  Created on: 25 mar. 2021
 *      Author: mateo
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int getInt(int* pNumero)
{
	int numero;

	scanf("%d", &numero);
	*pNumero = numero;

	return 0;
}

float getFloat(float* pNumero)
{
	float numero;

	scanf("%f", &numero);
	*pNumero = numero;

	return 0;
}

char getChar(char* pCaracter)
{
	char caracter;

	__fpurge(stdin);
	scanf("%c", &caracter);
	*pCaracter = caracter;

	return 0;
}
