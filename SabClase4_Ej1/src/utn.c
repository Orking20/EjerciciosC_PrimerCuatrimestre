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
static int getLongInt(long int* pResultado);
static int getFloat(float *pResultado);
static int getString(char* cadena, int limite);

static int validarEntero(char* cadena, int limite);
static int validarDecimal(char* cadena, int limite);
static int validarNombre(char* cadena, int limite);
static int validarDni(char* cadena, int limite);
static int validarCuit(char* cadena, int limite);
static int validarEdad(int* pNumero);
static int validarPrecio(long int* pResultado);
static int validarTelefono(char* cadena, int limite);

//--------------------------------OBTENCIÓN DE DATOS--------------------------------

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
			printf("Te quedaste sin intentos\n");
		}
	}

	return retorno;
}

/**
 * \brief Le pide al usuario un número decimal entre un rango con reintentos
 * \param float* pDecimal: Puntero donde se almacena el número ingresado por el usuario
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \param float min: El rango mínimo para ingresar un número
 * \param float max: El rango máximo para ingresar un número
 * \param int reintentos: Los reintentos que tiene el usuario para poner números correctos
 * \return Retorna 0 (EXITO) si se obtiene un número decimal entre el rango o -1 (ERROR) si no*/
int utn_getDecimal(float* pDecimal, char* pMensaje, char* pMensajeError, float min, float max, int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if(pDecimal != NULL && pMensaje != NULL && pMensajeError != NULL && reintentos > 0 && min <= max)
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
					*pDecimal = bufferFloat;
					break;
				}
			}

			reintentos--;
			printf("%s", pMensajeError);
		}while(reintentos > 0);

		if(reintentos == 0)
		{
			printf("Te quedaste sin intentos\n");
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
			printf("Te quedaste sin intentos\n");
		}
	}

	return retorno;
}

/**
 * \brief Le pide al usuario que ingrese un nombre
 * \param char* pNombre: Puntero donde se almacenará el nombre ingresado por el usuario
 * \param int limite: El limite o tamaño de la cadena
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el nombre o -1 (ERROR) si no*/
int utn_getNombre(char* pNombre, int limite, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[100];

	printf("%s", pMensaje);
	if(pNombre != NULL && limite > 0 && pMensaje != NULL && pMensajeError != NULL)
	{
		if(getString(bufferString, sizeof(bufferString)) == 0 && validarNombre(bufferString, sizeof(bufferString)) == 1)
		{
			strncpy(pNombre, bufferString, limite);
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
 * \brief Le pide al usuario que ingrese un DNI
 * \param char* pDni: Puntero donde se almacenará el DNI ingresado por el usuario
 * \param int limite: El limite o tamaño de la cadena
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el DNI o -1 (ERROR) si no*/
int utn_getDni(char* pDni, int limite, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[limite];

	if(pDni != NULL && limite > 0 && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		if(getString(bufferString, sizeof(bufferString)) == 0 && validarDni(bufferString, sizeof(bufferString)) == 1)
		{
			strncpy(pDni, bufferString, limite);
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
 * \brief Le pide al usuario que ingrese un CUIT
 * \param char* pCuit: Puntero donde se almacenará el CUIT ingresado por el usuario
 * \param int limite: El limite o tamaño de la cadena
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el CUIT o -1 (ERROR) si no*/
int utn_getCuit(char* pCuit, int limite, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[limite];

	if(pCuit != NULL && limite > 0 && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		if(getString(bufferString, sizeof(bufferString)) == 0 && validarCuit(bufferString, sizeof(bufferString)) == 1)
		{
			strncpy(pCuit, bufferString, limite);
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
 * \brief Le pide al usuario una edad
 * \param int* pEdad: Puntero donde se almacena la edad
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene la edad o -1 (ERROR) si no*/
int utn_getEdad(int* pEdad, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	int bufferInt;

	if(pEdad != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		__fpurge(stdin);
		if(getInt(&bufferInt) == 0 && validarEdad(&bufferInt))
		{
			*pEdad = bufferInt;
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
 * \brief Le pide al usuario un precio
 * \param int* pPrecio: Puntero donde se almacena el precio
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el precio o -1 (ERROR) si no*/
int utn_getPrecio(long int* pPrecio, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	long int bufferLongInt;

	if(pPrecio != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		if(getLongInt(&bufferLongInt) == 0 && validarPrecio(&bufferLongInt) == 1)
		{
			*pPrecio = bufferLongInt;
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
 * \brief Le pide al usuario que ingrese un teléfono
 * \param char* pTelefono: Puntero donde se almacenará el telefono ingresado por el usuario
 * \param int limite: El limite o tamaño de la cadena
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el teléfono o -1 (ERROR) si no*/
int utn_getTelefono(char* pTelefono, int limite, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[limite];

	if(pTelefono != NULL && limite > 0 && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		if(getString(bufferString, sizeof(bufferString)) == 0 && validarTelefono(bufferString, sizeof(bufferString)) == 1)
		{
			strncpy(pTelefono, bufferString, limite);
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
 * \brief Transforma una cadena de caractéres a números del tipo int
 * \param int* pResultado: Puntero donde se almacenará el número ingresado
 * \return Retorna 0 (EXITO) si puede transformar la cadena o -1 (ERROR) si no*/
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
 * \brief Transforma una cadena de caractéres a números del tipo long int
 * \param int* pResultado: Puntero donde se almacenará el número ingresado
 * \return Retorna 0 (EXITO) si puede transformar la cadena o -1 (ERROR) si no*/
static int getLongInt(long int* pResultado)
{
	int retorno = -1;
	char bufferLongInt[64];

	if(pResultado != NULL)
	{
		__fpurge(stdin);
		if(getString(bufferLongInt, sizeof(bufferLongInt)) == 0 && validarEntero(bufferLongInt, sizeof(bufferLongInt)))
		{
			*pResultado = atol(bufferLongInt);
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * \brief Transforma una cadena de caractéres a números del tipo float
 * \param float* pResultado: Puntero donde se almacenará el número ingresado
 * \return Retorna 0 (EXITO) si puede transformar la cadena o -1 (ERROR) si no*/
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

//--------------------------------VALIDACIONES--------------------------------

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
 * \brief Valida que la cadena recibida contenga sea un nombre o apellido válido
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

/**
 * \brief Valida que la cadena recibida sea un DNI válido
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es un DNI, 0 (falso) si no o -1 si hubo algún error con los argumentos*/
static int validarDni(char* cadena, int limite)
{
	int retorno = -1;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i = 0; i < limite  && cadena[i] != '\0'; i++)
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
		if(strlen(cadena) != 8)
		{
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * \brief Valida que la cadena recibida sea un CUIT válido
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es un CUIT, 0 (falso) si no o -1 si hubo algún error con los argumentos*/
static int validarCuit(char* cadena, int limite)
{
	int retorno = -1;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i = 0; i < limite  && cadena[i] != '\0'; i++)
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
		if(strlen(cadena) != 11)
		{
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * \brief Valida que el número ingresado sea una edad válida
 * \param int* pNumero: Puntero donde se almacenará la edad correcta
 * \return Retorna 1 (verdadero) si es una edad válida, 0 (falso) si no o -1 si hubo algún error con los argumentos*/
static int validarEdad(int* pNumero)
{
	int retorno = -1;

	if(pNumero != NULL)
	{
		retorno = 1;
		if(*pNumero < 1 || *pNumero > 122)
		{
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * \brief Valida que el número ingresado sea un precio válido
 * \param int* pNumero: Puntero donde se almacenará el precio
 * \return Retorna 1 (verdadero) si es un precio válido, 0 (falso) si no o -1 si hubo algún error con los argumentos*/
static int validarPrecio(long int* pResultado)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		retorno = 1;
		if(*pResultado < 0)
		{
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * \brief Valida que la cadena recibida sea un teléfono válido
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es un teléfono, 0 (falso) si no o -1 si hubo algún error con los argumentos*/
static int validarTelefono(char* cadena, int limite)
{
	int retorno = -1;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i = 0; i < limite  && cadena[i] != '\0'; i++)
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
		if(strlen(cadena) != 8)
		{
			retorno = 0;
		}
	}

	return retorno;
}

//--------------------------------OPERACIONES--------------------------------

/**
 * \brief Suma dos números y por medio de un puntero devuelve el resultado
 * \param float numeroA: Primer número de la operación
 * \param float numeroB: Segundo número de la operación
 * \param float* pResultado: El resultado de la suma, que va a llegar al main mediante un puntero
 * \return Retorna 0 (EXITO) si se pudo completar la suma o -1 (ERROR) si no*/
int utn_sumar(float numeroA, float numeroB, float* pResultado)
{
	int retorno = -1;
	float resultado;

	if(pResultado != NULL)
	{
		resultado = numeroA + numeroB;
		retorno = 0;
	}

	*pResultado = resultado;
	return retorno;
}

/**
 * \brief Resta dos números y por medio de un puntero devuelve el resultado
 * \param float numeroA: Primer número de la operación
 * \param float numeroB: Segundo número de la operación
 * \param float* pResultado: El resultado de la resta, que va a llegar al main mediante un puntero
 * \return Retorna 0 (EXITO) si se pudo completar la resta o -1 (ERROR) si no*/
int utn_restar(float numeroA, float numeroB, float* pResultado)
{
	int retorno = -1;
	float resultado;

	if(pResultado != NULL)
	{
		resultado = numeroA - numeroB;
		retorno = 0;
	}

	*pResultado = resultado;
	return retorno;
}

/**
 * \brief Divide dos números y por medio de un puntero devuelve el resultado
 * \param float numeroA: Primer número de la operación
 * \param float numeroB: Segundo número de la operación
 * \param float* pResultado: El resultado de la división, que va a llegar al main mediante un puntero
 * \param const char* pDivisionPorCero: Mensaje de error si el divisor es cero
 * \return Retorna 0 (EXITO) si se pudo completar la division o -1 (ERROR) si no o si el divisor es 0*/
int utn_dividir(float dividendo, float divisor, float* pResultado, const char* pDivisionPorCero)
{
	int retorno = -1;
	float resultado;

	if(pResultado != NULL)
	{
		if(divisor != 0)
		{
			resultado = dividendo / divisor;
			retorno = 0;
		}
		else
		{
			printf(pDivisionPorCero);
		}
	}

	*pResultado = resultado;
	return retorno;
}

/**
 * \brief Multiplica dos números y por medio de un puntero devuelve el resultado
 * \param float numeroA: Primer número de la operación
 * \param float numeroB: Segundo número de la operación
 * \param float* pResultado: El resultado de la multiplicación, que va a llegar al main mediante un puntero
 * \return Retorna 0 (EXITO) si se pudo completar la multiplicación o -1 (ERROR) si no*/
int utn_multiplicar(float dividendo, float divisor, float* pResultado)
{
	int retorno = -1;
	float resultado;

	if(pResultado != NULL)
	{
		resultado = dividendo * divisor;
		retorno = 0;
	}

	*pResultado = resultado;
	return retorno;
}

/**
 * \brief Factorisa un número ingresado y lo devuelve mediante un puntero
 * \param float numero: Número a ser factoriado
 * \param float* pResultado: El resultado de la factorización, que va a llegar al main mediante un puntero
 * \return Retorna 0 (EXITO) si se pudo completar la factorisación o -1 (ERROR) si no*/
int utn_factorial(float numero, float* pResultado)
{
	int retorno = -1;
	int acumulador = 1;

	if(pResultado != NULL)
	{
		for(int i = 1; i <= numero; i++)
		{
			acumulador *= i;
		}
		*pResultado = acumulador;
		retorno = 0;
	}

	return retorno;
}
