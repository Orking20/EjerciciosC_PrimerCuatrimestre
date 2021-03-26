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
	scanf("%d", pNumero);

	return 0;
}

float getFloat(float* pNumero)
{
	scanf("%f", pNumero);

	return 0;
}

char getChar(char* pCaracter)
{
	__fpurge(stdin);
	scanf("%c", pCaracter);

	return 0;
}
