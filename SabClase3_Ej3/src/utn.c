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
 * \param int* pNumero: Puntero donde se almacena el número ingresado por el usuario
 * \param const char* pTexto: Texto para que el usuario sepa que ingresar
 * \param const char* mensajeError: Texto que nos indica que hubo un error
 * \param int min: El rango mínimo para ingresar un número
 * \param int max: El rango máximo para ingresar un número
 * \param int reintentos: Los reintentos que tiene el usuario para poner números correctos
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
 * \brief Le pide al usuario un número decimal entre un rango con reintentos
 * \param float* pNumero: Puntero donde se almacena el número ingresado por el usuario
 * \param const char* pTexto: Texto para que el usuario sepa que ingresar
 * \param const char* sError: Texto que nos indica que hubo un error
 * \param float min: El rango mínimo para ingresar un número
 * \param float max: El rango máximo para ingresar un número
 * \param int reintentos: Los reintentos que tiene el usuario para poner números correctos
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
 * \param char* pChar: El caracter ingresado por el usuario
 * \param const char* pTexto: Texto para que el usuario sepa que ingresar
 * \param const char* sError: Texto que nos tira un error si ingresamos letra en vez de números
 * \param char min: El rango mínimo para ingresar un número
 * \param char max: El rango máximo para ingresar un número
 * \param int reintentos: Los reintentos que tiene el usuario para poner números correctos
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
 * \brief Transforma una cadena de caractéres a números si es posible
 * \param int* pResultado: Puntero donde se almacenará el número ingresado
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
 * \brief Transforma una cadena de caractéres a números decimales si es posible
 * \param float* pResultado: Puntero donde se almacenará el número ingresado
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
 * \brief Verifica que la cadena recibida contenga solamente números positivos o negativos
 * \param char* cadena: Cadena de caracteres a ser analizada
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
 * \brief Verifica que la cadena recibida contenga solamente números decimales positivos o negativos
 * \param char* cadena: Cadena de caracteres a ser analizada
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
* \param char* cadena: Puntero al espacio de memoria donde se copiará la cadena obtenida
* \param longitud: Define el tamaño de la cadena
* \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no*/
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

/**
* \brief Ordena una cadena de enteros de forma creciente
* \param int* cadena: Cadena que va a ser ordenada
* \param limite: Limite o tamaño de la cadena
* \return Retorna 0 (EXITO) o -1 (ERROR)*/
int ordenamientoCreciente(int* cadena, int limite)
{
	int retorno = -1;
	int aux;
	int flagSwap = 0;

	if(cadena != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 0; i < limite - 1; i++)
			{
				if(cadena[i] > cadena[i + 1])
				{
					aux = cadena[i];
					cadena[i] = cadena[i + 1];
					cadena[i + 1] = aux;
					flagSwap = 1;
				}
			}
		}while(flagSwap);

		retorno = 0;
	}

	return retorno;
}

/**
* \brief Ordena una cadena de enteros de forma decreciente
* \param int* cadena: Cadena que va a ser ordenada
* \param limite: Limite o tamaño de la cadena
* \return Retorna 0 (EXITO) o -1 (ERROR)*/
int ordenamientoDecreciente(int* cadena, int limite)
{
	int retorno = -1;
	int aux;
	int flagSwap = 0;

	if(cadena != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(int i = 0; i < limite - 1; i++)
			{
				if(cadena[i] < cadena[i + 1])
				{
					aux = cadena[i];
					cadena[i] = cadena[i + 1];
					cadena[i + 1] = aux;
					flagSwap = 1;
				}
			}
		}while(flagSwap);

		retorno = 0;
	}

	return retorno;
}
