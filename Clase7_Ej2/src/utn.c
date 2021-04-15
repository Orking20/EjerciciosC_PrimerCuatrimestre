/*
 * utn.c
 *
 *  Created on: 25 mar. 2021
 *      Author: mateo
 */

// Incluir el getFloat(), esNumeroDecimal() y getString

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

static int getInt(int *pResultado);
static int getFloat(float *pResultado);
static int esNumerica(char* cadena);
static int esDecimal(char* cadena);
static int myGets(char* cadena, int longitud);

/**
 * \brief Le pide al usuario un número entero entre un rango con reintentos
 *
 * \param pNumero: El número ingresado por el usuario
 * \param pTexto: Texto para que el usuario sepa que ingresar
 * \param mensajeError: Texto que nos indica que hubo algún tipo de error
 * \param reintentos: Los reintentos que tiene el usuario para poner números correctos
 * \param min: El rango mínimo para ingresar un número
 * \param max: El rango máximo para ingresar un número
 *
 * \return Retorna 0 (EXITO) si se obtiene un número entre el rango o -1 (ERROR) si no*/
int utn_getNumero(int* pNumero, const char* pTexto, const char* mensajeError, int min, int max, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pNumero != NULL && pTexto != NULL && mensajeError != NULL && reintentos >= 0 && min <= max)
	{
		do
		{
			printf(pTexto);
			__fpurge(stdin);
			if(getInt(&bufferInt) == 0)
			{
				if(bufferInt >= min && bufferInt <= max)
				{
					retorno = 0;
					*pNumero = bufferInt;
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

/**
 * \brief Le pide al usuario un número con decimal entre un rango con reintentos
 *
 * \param pNumero: El número ingresado por el usuario
 * \param pTexto: Texto para que el usuario sepa que ingresar
 * \param sError: Texto que nos tira un error si ingresamos letra en vez de números
 * \param fueraDeRango: Texto que nos indica si el usuario ingresó un número fuera de rango
 * \param reintentos: Los reintentos que tiene el usuario para poner números correctos
 * \param min: El rango mínimo para ingresar un número
 * \param max: El rango máximo para ingresar un número
 *
 * \return Retorna 0 (EXITO) si se obtiene un número decimal entre el rango o -1 (ERROR) si no*/
float utn_getFloat(float* pNumero, const char* pTexto, const char* mensajeError, float min, float max, int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if(pNumero != NULL && pTexto != NULL && mensajeError != NULL && reintentos > 0 && min <= max)
	{
		do
		{
			printf(pTexto);
			__fpurge(stdin);
			if(getFloat(&bufferFloat) == 0)
			{
				if(bufferFloat >= min && bufferFloat <= max)
				{
					retorno = 0;
					*pNumero = bufferFloat;
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

/**
 * \brief Le pide al usuario un caracter entre un rango con reintentos
 *
 * \param pChar: El caracter ingresado por el usuario
 * \param pTexto: Texto para que el usuario sepa que ingresar
 * \param sError: Texto que nos tira un error si ingresamos letra en vez de números
 * \param fueraDeRango: Texto que nos indica si el usuario ingresó un número fuera de rango
 * \param reintentos: Los reintentos que tiene el usuario para poner números correctos
 * \param min: El rango mínimo para ingresar un número
 * \param max: El rango máximo para ingresar un número
 *
 * \return Retorna 0 (EXITO) si se obtiene una letra entre el rango o -1 (ERROR) si no*/
char utn_getChar(char* pChar, const char* pTexto, const char* mensajeError, char min, char max, int reintentos)
{
	int retorno = -1;
	char bufferChar;

	if(pChar != NULL && pTexto != NULL && mensajeError != NULL && reintentos > 0 && min <= max)
	{
		do
		{
			printf(pTexto);
			__fpurge(stdin);
			if(scanf("%c", &bufferChar) == 1)
			{
				if(bufferChar >= min && bufferChar <= max)
				{
					*pChar = bufferChar;
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

/**
 * \brief Manda a verificar la cadena y si sale todo bien la transforma en un número
 *
 * \param pResultado: Puntero donde se almacenará el número ingresado
 *
 * \return Retorna 0 (EXITO) si se obtiene un número entero o -1 (ERROR) si no*/
static int getInt(int *pResultado)
{
	int retorno = -1;
	char buffer[64];

	if(pResultado != NULL)
	{
		if(myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer))
		{
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * \brief Manda a verificar la cadena y si sale todo bien la transforma en un número decimal
 *
 * \param pResultado: Puntero donde se almacenará el número ingresado
 *
 * \return Retorna 0 (EXITO) si se obtiene un número decimal o -1 (ERROR) si no*/
static int getFloat(float *pResultado)
{
	int retorno = -1;
	char buffer[64];

	if(pResultado != NULL)
	{
		if(myGets(buffer, sizeof(buffer)) == 0 && esDecimal(buffer))
		{
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * \brief Verifica que la cadena recibida solo contenga números positivos o negativos
 *
 * \param cadena: Cadena de caracteres a ser analizada
 *
 * \return Retorna 1 (verdadero) si la cadena es numérica, 0 (falso) si no o -1 si hubo algún error con los argumentos*/
static int esNumerica(char* cadena)
{
	int retorno = -1;
	int signo = 1;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		retorno = 0;
		for(int i = 0; cadena[i] != '\0'; i++)
		{
			if(cadena[i] >= '0' && cadena[i] <= '9')
			{
				if(i == 0 && cadena[i] == '-' && signo)
				{
					signo = 0;
				}
				retorno = 1;
			}
		}
	}

	return retorno;
}

/**
 * \brief Verifica que la cadena recibida solo contenga números decimales positivos o negativos
 *
 * \param cadena: Cadena de caracteres a ser analizada
 *
 * \return Retorna 1 (verdadero) si la cadena es decimal, 0 (falso) si no o -1 si hubo algún error con los argumentos*/
static int esDecimal(char* cadena)
{
	int retorno = -1;
	int punto = 1;
	int signo = 1;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		retorno = 0;
		for(int i = 0; cadena[i] != '\0'; i++)
		{
			if(cadena[i] >= '0' && cadena[i] <= '9')
			{
				if(i == 0 && cadena[i] == '-' && signo)
				{
					signo = 0;
				}
				if(cadena[i] == '.' && punto)
				{
					punto = 0;
				}
				retorno = 1;
			}
		}
	}

	return retorno;
}

/**
* \brief Verifica que en la cadena no quede un enter
*
* \param pResultado Puntero al espacio de memoria donde se copiará la cadena obtenida
* \param longitud Define el tamaño de cadena
*
* \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*/
static int myGets(char* cadena, int longitud)
{
	int retorno = -1;

	if(cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena)
	{
		__fpurge(stdin);
		if(cadena[strlen(cadena) - 1] == '\n')
		{
			cadena[strlen(cadena) - 1] = '\0';
		}
		retorno = 0;
	}

	return retorno;
}


