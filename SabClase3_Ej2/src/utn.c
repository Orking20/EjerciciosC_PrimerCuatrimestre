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
static int validarPositivo(int numero);
static int negativoMinimo(int cadena[], int limite, int* pNegativoMenor);

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

	if(pNumero != NULL && pTexto != NULL && mensajeError != NULL && min <= max && reintentos >= 0)
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
 * \brief Recorre una cadena de enteros y por medio de un puntero devuelve el promedio de sus números positivos
 * \param int cadena[]: Cadena a ser analizada
 * \param int limite: Limite o tamaño de la cadena
 * \param float* pPromedio: Puntero donde se almacenará el promedio de los números positivos de la cadena
 * \return Retorna 0 (EXITO) o -1 (ERROR)*/
int promediarPositivos(int cadena[], int limite, float* pPromedio)
{
	int retorno = -1;
	int sumaPositivos = 0;
	int contPositivos = 0;
	float promedio;

	if(cadena != NULL && limite > 0 && pPromedio != NULL)
	{
		for(int i = 0; i < limite; i++)
		{
			if(validarPositivo(cadena[i]) == 1)
			{
				sumaPositivos += cadena[i];
				contPositivos++;
			}
		}

		promedio = (float)sumaPositivos / contPositivos;
		*pPromedio = promedio;
		retorno = 0;
	}

	return retorno;
}

int sumaAntesecores(int cadena[], int limite, int* pResultado)
{
	int retorno = 0;
	int numero;
	int acumulador = 0;
	int resultado;

	if(cadena != NULL && limite > 0 && pResultado != NULL)
	{
		negativoMinimo(cadena, limite, &numero);
		for(int i = 0; i != numero; numero++)
		{
			acumulador += numero;
		}

		resultado = acumulador;
		*pResultado = resultado;
		retorno = 0;
	}

	return retorno;
}

/**
 * \brief Recorre una cadena de enteros y por medio de un puntero devuelve el mínimo de los números negativos
 * \param int cadena[]: Cadena a ser analizada
 * \param int limite: Limite o tamaño de la cadena
 * \param int* pNegativoMenor: Puntero donde se almacenará el menor de los números negativos de la cadena
 * \return Retorna 0 (EXITO) o -1 (ERROR)*/
static int negativoMinimo(int cadena[], int limite, int* pNegativoMenor)
{
	int retorno = -1;
	int menor;

	if(cadena != NULL && limite > 0 && pNegativoMenor != NULL)
	{
		for(int i = 0; i < limite; i++)
		{
			if(i == 0 || cadena[i] < menor)
			{
				menor = cadena[i];
			}
		}

		*pNegativoMenor = menor;
		retorno = 0;
	}

	return retorno;
}

/**
* \brief Analiza un número para saber si es positivo, negativo o neutro
* \param int numero: Número a ser analizado
* \return Retorna -2 (ERROR), -1 si es negativo, 0 si es cero y 1 si es positivo*/
static int validarPositivo(int numero)
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
