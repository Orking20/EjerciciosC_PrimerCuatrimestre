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
static int getString(char* cadena, int limite);
static int validarEntero(char* cadena, int limite);
static int validarDecimal(char* cadena, int limite);
static int validarNombre(char* cadena, int limite);

/**
 * \brief Le pide al usuario un número entero entre un rango con reintentos
 * \param int* pNumero: Puntero donde se almacena el número ingresado por el usuario
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \param int min: El rango mínimo para ingresar un número
 * \param int max: El rango máximo para ingresar un número
 * \param int reintentos: Los reintentos que tiene el usuario para poner números correctos
 * \return Retorna 0 (EXITO) si se obtiene un número entre el rango o -1 (ERROR) si no*/
int utn_getNumero(int* pNumero, char* pMensaje, char* pMensajeError, int min, int max, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pNumero != NULL && pMensaje != NULL && pMensajeError != NULL && reintentos >= 0 && min <= max)
	{
		do
		{
			printf("%s", pMensaje);
			__fpurge(stdin);
			if(getInt(&bufferInt) == 0 && bufferInt >= min && bufferInt <= max)
			{
				retorno = 0;
				*pNumero = bufferInt;
				break;
			}

			reintentos--;
			printf("%s", pMensajeError);
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
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \param float min: El rango mínimo para ingresar un número
 * \param float max: El rango máximo para ingresar un número
 * \param int reintentos: Los reintentos que tiene el usuario para poner números correctos
 * \return Retorna 0 (EXITO) si se obtiene un número decimal entre el rango o -1 (ERROR) si no*/
int utn_getDecimal(float* pNumero, char* pMensaje, char* pMensajeError, float min, float max, int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if(pNumero != NULL && pMensaje != NULL && pMensajeError != NULL && reintentos > 0 && min <= max)
	{
		do
		{
			printf("%s", pMensaje);
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
			printf("%s", pMensajeError);
		}while(reintentos > 0);

		if(reintentos == 0)
		{
			printf("Te quedaste sin intentos");
		}
	}

	return retorno;
}

/**
 * \brief Le pide al usuario que ingrese un texto
 * \param char* pString: Puntero donde se almacenará el texto ingresado por el usuario
 * \param int limite: El limite o tamaño de la cadena
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el texto o -1 (ERROR) si no*/
int utn_getTexto(char* pString, int limite, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[4096];

	if(pString != NULL && limite > 0 && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		__fpurge(stdin);
		if(getString(bufferString, sizeof(bufferString)) == 0)
		{
			strncpy(pString, bufferString, limite);
			retorno = 0;
		}
		else
		{
			printf("%s", pMensajeError);
		}
	}

	return retorno;
}

/**
 * \brief Le pide al usuario un caracter entre un rango con reintentos
 * \param char* pChar: El caracter ingresado por el usuario
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \param char min: El rango mínimo para ingresar un número
 * \param char max: El rango máximo para ingresar un número
 * \param int reintentos: Los reintentos que tiene el usuario para poner números correctos
 * \return Retorna 0 (EXITO) si se obtiene una letra entre el rango o -1 (ERROR) si no*/
int utn_getCaracter(char* pChar, char* pMensaje, char* pMensajeError, char min, char max, int reintentos)
{
	int retorno = -1;
	char bufferChar;

	if(pChar != NULL && pMensaje != NULL && pMensajeError != NULL && reintentos > 0 && min <= max)
	{
		do
		{
			printf("%s", pMensaje);
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
			printf("%s", pMensajeError);
		}while(reintentos > 0);

		if(reintentos == 0)
		{
			printf("Te quedaste sin intentos");
		}
	}

	return retorno;
}

/**
 * \brief Le pide al usuario que ingrese un nombre
 * \param char* pResultado: Puntero donde se almacenará el nombre ingresado por el usuario
 * \param int limite: El limite o tamaño de la cadena
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el nombre o -1 (ERROR) si no*/
int utn_getNombre(char* pResultado, int limite, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[100];

	printf("%s", pMensaje);
	if(pResultado != NULL && limite > 0 && pMensaje != NULL && pMensajeError != NULL)
	{
		if(getString(bufferString, sizeof(bufferString)) == 0 && validarNombre(bufferString, sizeof(bufferString)) == 1)
		{
			strncpy(pResultado, bufferString, limite);
			retorno = 0;
		}
		else
		{
			printf("%s", pMensajeError);
		}
	}

	return retorno;
}

/**
 * \brief Transforma una cadena de caractéres a números si es posible
 * \param int* pResultado: Puntero donde se almacenará el número ingresado
 * \return Retorna 0 (EXITO) si se obtiene un número entero o -1 (ERROR) si no*/
static int getInt(int* pResultado)
{
	int retorno = -1;
	char bufferInt[64];

	if(pResultado != NULL)
	{
		__fpurge(stdin);
		if(getString(bufferInt, sizeof(bufferInt)) == 0 && validarEntero(bufferInt, sizeof(bufferInt)))
		{
			*pResultado = atoi(bufferInt);
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * \brief Transforma una cadena de caractéres a números decimales si es posible
 * \param float* pResultado: Puntero donde se almacenará el número ingresado
 * \return Retorna 0 (EXITO) si se obtiene un número decimal o -1 (ERROR) si no*/
static int getFloat(float* pResultado)
{
	int retorno = -1;
	char bufferFloat[64];

	if(pResultado != NULL)
	{
		if(getString(bufferFloat, sizeof(bufferFloat)) == 0 && validarDecimal(bufferFloat, sizeof(bufferFloat)))
		{
			*pResultado = atof(bufferFloat);
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * \brief Pide un texto al usuario y se encarga de que no quede un enter en el buffer
 * \param char* pResultado: Puntero donde se almacenará el texto ingresado
 * \return Retorna 0 (EXITO) si se obtiene el texto o -1 (ERROR) si no*/
static int getString(char* cadena, int limite)
{
	int retorno = -1;
	char bufferString[4096];

	if(cadena != NULL && limite > 0 && fgets(bufferString, sizeof(bufferString), stdin) != NULL)
	{
		__fpurge(stdin);
		if(bufferString[strlen(bufferString) - 1] == '\n')
		{
			bufferString[strlen(bufferString) - 1] = '\0';
		}
		strncpy(cadena, bufferString, limite);
		retorno = 0;
	}

	return retorno;
}

/**
 * \brief Valida que la cadena recibida contenga solamente números enteros
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es numérica, 0 (falso) si no o -1 si hubo algún error con los argumentos*/
static int validarEntero(char* cadena, int limite)
{
	int retorno = -1;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if(i == 0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

/**
 * \brief Valida que la cadena recibida contenga solamente números decimales positivos o negativos
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es decimal, 0 (falso) si no o -1 si hubo algún error con los argumentos*/
static int validarDecimal(char* cadena, int limite)
{
	int retorno = -1;
	int punto = 1;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if(i == 0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(punto && cadena[i] == '.')
			{
				punto = 0;
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

/**
 * \brief Valida que la cadena recibida contenga sea un nombre o apellido
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es un nombre o apellido, 0 (falso) si no o -1 si hubo algún error con los argumentos*/
static int validarNombre(char* cadena, int limite)
{
	int retorno = -1;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if((i == 0 || cadena[i - 1] == ' ') && cadena[i] >= 'A' && cadena[i] <= 'Z')
			{
				continue;
			}
			if((cadena[i] < 'a' || cadena[i] > 'z') && cadena[i] != ' ')
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
