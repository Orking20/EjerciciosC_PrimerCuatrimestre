/*
 * UTN.c
 *
 *  Created on: 25 mar. 2021
 *      Author: mateo
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"

/*
 * utn_getNumero:	Le pide al usuario un número entero entre un rango con reintentos
 *
 * pNumero:			El número ingresado por el usuario
 * pTexto:			Texto para que el usuario sepa que ingresar
 * mensajeError:	Texto que nos indica que hubo algún tipo de error
 * reintentos:		Los reintentos que tiene el usuario para poner números correctos
 * min:				El rango mínimo para ingresar un número
 * max:				El rango máximo para ingresar un número*/
int utn_getNumero(int* pNumero, const char* pTexto, const char* mensajeError, int reintentos, int min, int max)
{
	int retorno = -1;
	int errorLetra;

	if(pNumero != NULL && pTexto != NULL && mensajeError != NULL && reintentos > 0 && min <= max)
	{
		do
		{
			printf(pTexto);
			__fpurge(stdin);
			errorLetra = scanf("%d", pNumero);
			if(errorLetra == 1)
			{
				if(*pNumero >= min && *pNumero <= max)
				{
					retorno = 0;
					break;
				}
			}

			reintentos--;
			printf(mensajeError);
		}while(reintentos > 0);

		if(reintentos == 0)
		{
			printf("Te quedaste sin intentos");
		}
	}

	return retorno;
}

/*
 * utn_getFloat:	Le pide al usuario un número racional entre un rango con reintentos
 *
 * pNumero:			El número ingresado por el usuario
 * pTexto:			Texto para que el usuario sepa que ingresar
 * sError:			Texto que nos tira un error si ingresamos letra en vez de números
 * fueraDeRango:	Texto que nos indica si el usuario ingresó un número fuera de rango
 * reintentos:		Los reintentos que tiene el usuario para poner números correctos
 * min:				El rango mínimo para ingresar un número
 * max:				El rango máximo para ingresar un número*/
float utn_getFloat(float* pNumero, const char* pTexto, const char* mensajeError, int reintentos, float min, float max)
{
	int retorno = -1;
	int errorLetra;

	if(pNumero != NULL && pTexto != NULL && mensajeError != NULL && reintentos > 0 && min <= max)
	{
		do
		{
			printf(pTexto);
			__fpurge(stdin);
			errorLetra = scanf("%f", pNumero);
			if(errorLetra == 1)
			{
				if(*pNumero >= min && *pNumero <= max)
				{
					retorno = 0;
					break;
				}
			}

			reintentos--;
			printf(mensajeError);
		}while(reintentos > 0);

		if(reintentos == 0)
		{
			printf("Te quedaste sin intentos");
		}
	}

	return retorno;
}

/*
 * utn_getChar:		Le pide al usuario un caracter entre un rango con reintentos
 *
 * pChar:			El caracter ingresado por el usuario
 * pTexto:			Texto para que el usuario sepa que ingresar
 * sError:			Texto que nos tira un error si ingresamos letra en vez de números
 * fueraDeRango:	Texto que nos indica si el usuario ingresó un número fuera de rango
 * reintentos:		Los reintentos que tiene el usuario para poner números correctos
 * min:				El rango mínimo para ingresar un número
 * max:				El rango máximo para ingresar un número*/
char utn_getChar(char* pChar, const char* pTexto, const char* mensajeError, int reintentos, char min, char max)
{
	int retorno = -1;
	char caracter;
	int errorLetra;

	if(pChar != NULL && pTexto != NULL && mensajeError != NULL && reintentos > 0 && min <= max)
	{
		do
		{
			printf(pTexto);
			__fpurge(stdin);
			errorLetra = scanf("%c", &caracter);
			if(errorLetra == 1)
			{
				if(caracter >= min && caracter <= max)
				{
					*pChar = caracter;
					retorno = 0;
					break;
				}
			}

			reintentos--;
			printf(mensajeError);
		}while(reintentos > 0);

		if(reintentos == 0)
		{
			printf("Te quedaste sin intentos");
		}
	}

	return retorno;
}

















