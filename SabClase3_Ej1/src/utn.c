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
static int BuscarParidad(int numero);
static int EsPositivo(int numero);

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
* \brief Devuelve a travéz de un puntero la suma de números pares de una cadena
* \param int cadena[]: Cadena a ser analizada
* \param int limite: Limite o tamaño de la cadena
* \param int* pSumaPares: Puntero donde se almacenará la suma de números pares
* \return Retorna 0 (EXITO) o -1 (ERROR)*/
int SumarPares(int cadena[], int limite, int* pSumaPares)
{
	int retorno = -1;
	int sumaPares = 0;

	if(cadena != NULL && limite > 0 && pSumaPares != NULL)
	{
		for(int i = 0; i < limite; i++)
		{
			if(BuscarParidad(cadena[i]) == 1)
			{
				sumaPares += cadena[i];
			}
		}

		*pSumaPares = sumaPares;
		retorno = 0;
	}

	return retorno;
}

/**
* \brief Devuelve a travéz de un puntero el número impar más grande que hay en una cadena
* \param int cadena[]: Cadena a ser analizada
* \param int limite: Limite o tamaño de la cadena
* \param int* pMayorImpar: Puntero donde se almacenará el número impar más grande
* \return Retorna 0 (EXITO) o -1 (ERROR)*/
int RetornarMayorImpar(int cadena[], int limite, int* pMayorImpar)
{
	int retorno = -1;
	int mayorImpar;

	if(cadena != NULL && limite > 0 && pMayorImpar != NULL)
	{
		for(int i = 0; i < limite; i++)
		{
			if(BuscarParidad(cadena[i]) == -1)
			{
				if(i == 0 || cadena[i] > mayorImpar)
				{
					mayorImpar = cadena[i];
				}
			}
		}

		*pMayorImpar = mayorImpar;
		retorno = 0;
	}

	return retorno;
}

/**
* \brief Muestra una lista de todos los números pares en una cadena
* \param int cadena[]: Cadena a ser analizada
* \param int limite: Limite o tamaño de la cadena
* \return Retorna 0 (EXITO) o -1 (ERROR)*/
int MostrarTodosLosNumerosPares(int cadena[], int limite)
{
	int retorno = -1;

	if(cadena != NULL && limite > 0)
	{
		printf("Listado de números pares\n");
		for(int i = 0; i < limite; i++)
		{
			if(BuscarParidad(cadena[i]) == 1)
			{
				printf("%d\n", cadena[i]);
			}
		}
		retorno = 0;
	}

	return retorno;
}

/**
* \brief Muestra una lista de los números de las posiciones impares de una cadena
* \param int cadena[]: Cadena a ser analizada
* \param int limite: Limite o tamaño de la cadena
* \return Retorna 0 (EXITO) o -1 (ERROR)*/
int MostrarNumerosPosicionesImpares(int cadena[], int limite)
{
	int retorno = -1;

	if(cadena != NULL && limite > 0)
	{
		printf("Listado de los números de las posiciones impares\n");
		for(int i = 1; i < limite; i += 2)
		{
			printf("%d\n", cadena[i]);
		}
		retorno = 0;
	}

	return retorno;
}

/**
* \brief Devuelve a travéz de un puntero la cantidad de números positivos que hay en una cadena
* \param int cadena[]: Cadena a ser analizada
* \param int limite: Limite o tamaño de la cadena
* \param int* pCantPositivos: Puntero donde se almacenará la cantidad de positivos en la cadena
* \return Retorna 0 (EXITO) o -1 (ERROR)*/
int ContarPositivos(int cadena[], int limite, int* pCantPositivos)
{
	int retorno = -1;
	int cantPositivos = 0;

	if(cadena != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(EsPositivo(cadena[i]) == 1)
			{
				cantPositivos++;
			}
		}

		*pCantPositivos = cantPositivos;
		retorno = 0;
	}

	return retorno;
}

/**
* \brief Devuelve a travéz de un puntero la cantidad de números negativos que hay en una cadena
* \param int cadena[]: Cadena a ser analizada
* \param int limite: Limite o tamaño de la cadena
* \param int* pCantNegativos: Puntero donde se almacenará la cantidad de negativos en la cadena
* \return Retorna 0 (EXITO) o -1 (ERROR)*/
int ContarNegativos(int cadena[], int limite, int* pCantNegativos)
{
	int retorno = -1;
	int cantNegativos = 0;

	if(cadena != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			if(EsPositivo(cadena[i]) == -1)
			{
				cantNegativos++;
			}
		}

		*pCantNegativos = cantNegativos;
		retorno = 0;
	}

	return retorno;
}

/**
* \brief Analiza un número para saber si es par, impar o cero
* \param int numero: Número a ser analizado
* \return Retorna -2 (ERROR), -1 si es impar, 0 si es cero y 1 si es par*/
static int BuscarParidad(int numero)
{
	int retorno = -2;

	if(numero == 0)
	{
		retorno = 0;
	}
	else if(numero % 2 == 0)
	{
		retorno = 1;
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

/**
* \brief Analiza un número para saber si es positivo, negativo o neutro
* \param int numero: Número a ser analizado
* \return Retorna -2 (ERROR), -1 si es negativo, 0 si es cero y 1 si es positivo*/
static int EsPositivo(int numero)
{
	int retorno = -2;

	if(numero > 0)
	{
		retorno = 1;
	}
	else if(numero < 0)
	{
		retorno = -1;
	}
	else
	{
		retorno = 0;
	}

	return retorno;
}
