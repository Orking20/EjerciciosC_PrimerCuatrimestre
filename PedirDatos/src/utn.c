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
#include <ctype.h>
#define TAM_ARRAY 4096
#define TAM_NOMBRE 100
#define TAM_DESCRIPCION 4096
#define TAM_DNI 9
#define TAM_CUIT 12
#define TAM_TELEFONO 10
#define TAM_CELULAR 13
#define TAM_EMAIL 64
#define TAM_SITIO_WEB 100
#define TAM_TARJETA_CREDITO 20
#define TAM_DIRECCION 64
#define TAM_DIRECCION_ALTURA 10
#define TAM_NOMBRE_ARCHIVO 64
#define TAM_ESTADO_CIVIL 20
#define TAM_SEXO 20
#define TAM_RESPUESTA 3

static int getInt(int *pResultado);
static int getFloat(float *pResultado);
static int getString(char* cadena, int limite);

static int getMayusculas(char* cadena, int limite);
static int getMinusculas(char* cadena, int limite);

static int validarEntero(char* cadena, int limite);
static int validarDecimal(char* cadena, int limite);
static int validarPalabra(char* cadena, int limite);
static int validarNombre(char* cadena, int limite);
static int validarDni(char* cadena, int limite);
static int validarCuit(char* cadena, int limite);
static int validarEdad(int* pNumero);
static int validarPrecio(float* pResultado);
static int validarTelefono(char* cadena, int limite);
static int validarCelular(char* cadena, int limite);
static int validarEmail(char* cadena, int limite);
static int validarSitioWeb(char* cadena, int limite);
static int validarTarjetaCredito(char* cadena, int limite);
static int validarDireccion(char* cadena, int limite);
static int validarDireccionAltura(char* cadena, int limite);
static int validarNombreArchivo(char* cadena, int limite);
static int validarEstadoCivil(char* cadena, int limite);
static int validarSexo(char* cadena, int limite);
static int validarRespuestaSiNo(char* cadena, int limite);

//--------------------------------OBTENCIÓN DE DATOS--------------------------------

/**
 * \brief Le pide al usuario un número entero entre un rango con reintentos
 * \param int* pNumero: Puntero donde se almacenará el número ingresado
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
 * \param float* pDecimal: Puntero donde se almacenará el número ingresado
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
 * \param char* pString: Puntero donde se almacenará el texto ingresado
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
 * \brief Le pide al usuario que ingrese una palabra
 * \param char* pString: Puntero donde se almacenará la palabra ingresada
 * \param int limite: El limite o tamaño de la cadena
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene la palabra o -1 (ERROR) si no*/
int utn_getPalabra(char* pString, int limite, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[1024];

	if(pString != NULL && limite > 0 && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		__fpurge(stdin);
		if(getString(bufferString, sizeof(bufferString)) == 0 && validarPalabra(bufferString, sizeof(bufferString)))
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
 * \param char* pChar: Puntero donde se almacenará el caracter ingresado
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
 * \brief Le pide al usuario que ingrese un texto y lo convierte en mayúsculas
 * \param char* pString: Puntero donde se almacenará el texto ingresado en mayúsculas
 * \param int limite: El limite o tamaño de la cadena
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el texto en mayúsculas o -1 (ERROR) si no*/
int utn_getCadenaMayusculas(char* pString, int limite, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[2024];

	if(pString != NULL && limite > 0 && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		__fpurge(stdin);
		if(getString(bufferString, sizeof(bufferString)) == 0 && getMayusculas(bufferString, sizeof(bufferString)) == 0)
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
 * \brief Le pide al usuario que ingrese un texto y lo convierte en minúsculas
 * \param char* pString: Puntero donde se almacenará el texto ingresado en minúsculas
 * \param int limite: El limite o tamaño de la cadena
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el texto en minúsculas o -1 (ERROR) si no*/
int utn_getCadenaMinusculas(char* pString, int limite, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[2024];

	if(pString != NULL && limite > 0 && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		__fpurge(stdin);
		if(getString(bufferString, sizeof(bufferString)) == 0 && getMinusculas(bufferString, sizeof(bufferString)) == 0)
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
 * \brief Le pide al usuario que ingrese un nombre
 * \param char* pNombre: Puntero donde se almacenará el nombre ingresado
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el nombre o -1 (ERROR) si no*/
int utn_getNombre(char* pNombre, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[TAM_NOMBRE];

	printf("%s", pMensaje);
	__fpurge(stdin);
	if(pNombre != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		if(getString(bufferString, sizeof(bufferString)) == 0 && validarNombre(bufferString, sizeof(bufferString)) == 1)
		{
			strncpy(pNombre, bufferString, TAM_NOMBRE);
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
 * \brief Le pide al usuario que ingrese una descripción
 * \param char* pDescripcion: Puntero donde se almacenará la descripción ingresada
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene la descripción o -1 (ERROR) si no*/
int utn_getDescripcion(char* pDescripcion, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[TAM_DESCRIPCION];

	printf("%s", pMensaje);
	__fpurge(stdin);
	if(pDescripcion != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		if(getString(bufferString, sizeof(bufferString)) == 0)
		{
			strncpy(pDescripcion, bufferString, TAM_DESCRIPCION);
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
 * \param char* pDni: Puntero donde se almacenará el DNI ingresado
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el DNI o -1 (ERROR) si no*/
int utn_getDni(char* pDni, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[TAM_DNI];

	if(pDni != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		__fpurge(stdin);
		if(getString(bufferString, sizeof(bufferString)) == 0 && validarDni(bufferString, sizeof(bufferString)) == 1)
		{
			strncpy(pDni, bufferString, TAM_DNI);
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
 * \param char* pCuit: Puntero donde se almacenará el CUIT ingresado
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el CUIT o -1 (ERROR) si no*/
int utn_getCuit(char* pCuit, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[TAM_CUIT];

	if(pCuit != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		__fpurge(stdin);
		if(getString(bufferString, sizeof(bufferString)) == 0 && validarCuit(bufferString, sizeof(bufferString)) == 1)
		{
			strncpy(pCuit, bufferString, TAM_CUIT);
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
 * \param int* pEdad: Puntero donde se almacenará la edad ingresada
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
 * \param float* pPrecio: Puntero donde se almacenará el precio ingresado
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el precio o -1 (ERROR) si no*/
int utn_getPrecio(float* pPrecio, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	float bufferLongInt;

	if(pPrecio != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		__fpurge(stdin);
		if(getFloat(&bufferLongInt) == 0 && validarPrecio(&bufferLongInt) == 1)
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
 * \param char* pTelefono: Puntero donde se almacenará el telefono ingresado
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el teléfono o -1 (ERROR) si no*/
int utn_getTelefono(char* pTelefono, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[TAM_TELEFONO];

	if(pTelefono != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		__fpurge(stdin);
		if(getString(bufferString, sizeof(bufferString)) == 0 && validarTelefono(bufferString, sizeof(bufferString)) == 1)
		{
			strncpy(pTelefono, bufferString, TAM_TELEFONO);
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
 * \brief Le pide al usuario que ingrese un celular
 * \param char* pCelular: Puntero donde se almacenará el celular ingresado
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el celular o -1 (ERROR) si no*/
int utn_getCelular(char* pCelular, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[TAM_CELULAR];

	if(pCelular != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		__fpurge(stdin);
		if(getString(bufferString, sizeof(bufferString)) == 0 && validarCelular(bufferString, sizeof(bufferString)) == 1)
		{
			strncpy(pCelular, bufferString, TAM_CELULAR);
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
 * \brief Le pide al usuario que ingrese un email
 * \param char* pEmail: Puntero donde se almacenará el email ingresado
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el email o -1 (ERROR) si no*/
int utn_getEmail(char* pEmail, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[TAM_EMAIL];

	if(pEmail != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		__fpurge(stdin);
		if(getString(bufferString, sizeof(bufferString)) == 0 && validarEmail(bufferString, sizeof(bufferString)) == 1)
		{
			strncpy(pEmail, bufferString, TAM_EMAIL);
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
 * \brief Le pide al usuario que ingrese un sitio web
 * \param char* pSitioWeb: Puntero donde se almacenará el sitio web ingresado
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el sitio web o -1 (ERROR) si no*/
int utn_getSitioWeb(char* pSitioWeb, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[TAM_SITIO_WEB];

	if(pSitioWeb != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		__fpurge(stdin);
		if(getString(bufferString, sizeof(bufferString)) == 0 && validarSitioWeb(bufferString, sizeof(bufferString)) == 1)
		{
			strncpy(pSitioWeb, bufferString, TAM_SITIO_WEB);
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
 * \brief Le pide al usuario que ingrese una tarjeta de crédito
 * \param char* pTarjeta: Puntero donde se almacenará la tarjeta de crédito ingresada
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene la tarjeta de crédito o -1 (ERROR) si no*/
int utn_getTarjetaCredito(char* pTarjeta, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[TAM_TARJETA_CREDITO];

	if(pTarjeta != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		__fpurge(stdin);
		if(getString(bufferString, sizeof(bufferString)) == 0 && validarTarjetaCredito(bufferString, sizeof(bufferString)) == 1)
		{
			strncpy(pTarjeta, bufferString, TAM_TARJETA_CREDITO);
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
 * \brief Le pide al usuario que ingrese una dirección
 * \param char* pDireccion: Puntero donde se almacenará la direccion ingresada
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeAltura: Texto que informa que se debe ingresar una altura
 * \param char* pMensajeError: Texto que nos informa de un error
 * \param char* pMensajeErrorAltura: Texto que nos informa que faltó escribir la altura de la dirección
 * \return Retorna 0 (EXITO) si se obtiene la dirección o -1 (ERROR) si no*/
int utn_getDireccion(char* pDireccion, char* pMensaje, char* pMensajeAltura, char* pMensajeError, char* pMensajeErrorAltura)
{
	int retorno = -1;
	char bufferString[TAM_DIRECCION];
	char bufferString2[TAM_DIRECCION_ALTURA];

	if(pDireccion != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		__fpurge(stdin);
		if(getString(bufferString, sizeof(bufferString)) == 0 && validarDireccion(bufferString, sizeof(bufferString)) == 1)
		{
			printf("%s", pMensajeAltura);
			__fpurge(stdin);
			if(getString(bufferString2, sizeof(bufferString2)) == 0 && validarDireccionAltura(bufferString2, sizeof(bufferString2)) == 1)
			{
				strcat(bufferString, " ");
				strcat(bufferString, bufferString2);
				strncpy(pDireccion, bufferString, TAM_DIRECCION);
				retorno = 0;
			}
			else
			{
				printf("%s", pMensajeErrorAltura);
			}
		}
		else
		{
			printf("%s", pMensajeError);
		}
	}

	return retorno;
}

/**
 * \brief Le pide al usuario que ingrese el nombre de un archivo
 * \param char* pArchivo: Puntero donde se almacenará el nombre de archivo ingresado
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el nombre del archivo o -1 (ERROR) si no*/
int utn_getNombreArchivo(char* pArchivo, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[TAM_NOMBRE_ARCHIVO];

	if(pArchivo != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		__fpurge(stdin);
		if(getString(bufferString, sizeof(bufferString)) == 0 && validarNombreArchivo(bufferString, sizeof(bufferString)) == 1)
		{
			strncpy(pArchivo, bufferString, TAM_NOMBRE_ARCHIVO);
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
 * \brief Le pide al usuario que ingrese un estado civíl
 * \param char* pEstadoCivil: Puntero donde se almacenará el estado civíl ingresado
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el estado civíl o -1 (ERROR) si no*/
int utn_getEstadoCivil(char* pEstadoCivil, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[TAM_ESTADO_CIVIL];

	if(pEstadoCivil != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		__fpurge(stdin);
		if(getString(bufferString, sizeof(bufferString)) == 0 && validarEstadoCivil(bufferString, sizeof(bufferString)) == 1)
		{
			strncpy(pEstadoCivil, bufferString, TAM_ESTADO_CIVIL);
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
 * \brief Le pide al usuario que ingrese un sexo (femenino o masculino)
 * \param char* pSexo: Puntero donde se almacenará el sexo ingresado
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene el sexo o -1 (ERROR) si no*/
int utn_getSexo(char* pSexo, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[TAM_SEXO];

	if(pSexo != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		__fpurge(stdin);
		if(getString(bufferString, sizeof(bufferString)) == 0 && validarSexo(bufferString, sizeof(bufferString)) == 1)
		{
			strncpy(pSexo, bufferString, TAM_SEXO);
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
 * \brief Le pide al usuario que ingrese una respuesta (si o no)
 * \param char* pRespuesta: Puntero donde se almacenará la respuesta ingresada
 * \param char* pMensaje: Texto para que el usuario sepa que ingresar
 * \param char* pMensajeError: Texto que nos informa de un error
 * \return Retorna 0 (EXITO) si se obtiene la respuesta o -1 (ERROR) si no*/
int utn_getRespuestaSiNo(char* pRespuesta, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[TAM_RESPUESTA];

	if(pRespuesta != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		__fpurge(stdin);
		if(getString(bufferString, sizeof(bufferString)) == 0 && validarRespuestaSiNo(bufferString, sizeof(bufferString)) == 1)
		{
			strncpy(pRespuesta, bufferString, TAM_RESPUESTA);
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
 * \brief Transforma una cadena de caractéres a números del tipo float
 * \param float* pResultado: Puntero donde se almacenará el número ingresado
 * \return Retorna 0 (EXITO) si puede transformar la cadena o -1 (ERROR) si no*/
static int getFloat(float* pResultado)
{
	int retorno = -1;
	char bufferFloat[64];

	if(pResultado != NULL)
	{
		__fpurge(stdin);
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
 * \param char* cadena: Puntero donde se almacenará el texto ingresado
 * \param limite: Limite o tamaño de la cadena
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
 * \brief Pide un texto al usuario y lo convierte en mayúsculas
 * \param char* cadena: Puntero donde se almacenará el texto en mayúsculas
 * \param limite: Limite o tamaño de la cadena
 * \return Retorna 0 (EXITO) si se convierte en mayúsculas o -1 (ERROR) si no*/
static int getMayusculas(char* cadena, int limite)
{
	int retorno = -1;

	if(cadena != NULL)
	{
		for(int i = 0; i < limite; i++)
		{
			cadena[i] = toupper(cadena[i]);
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * \brief Pide un texto al usuario y lo convierte en minúsculas
 * \param char* cadena: Puntero donde se almacenará el texto en minúsculas
 * \param limite: Limite o tamaño de la cadena
 * \return Retorna 0 (EXITO) si se convierte en minúsculas o -1 (ERROR) si no*/
static int getMinusculas(char* cadena, int limite)
{
	int retorno = -1;

	if(cadena != NULL)
	{
		for(int i = 0; i < limite; i++)
		{
			cadena[i] = tolower(cadena[i]);
		}
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
	int punto = 0;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if(i == 0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(punto == 0 && cadena[i] == '.')
			{
				punto = 1;
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
 * \brief Valida que la cadena recibida contenga solo una palabra
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es una palabra, 0 (falso) si no o -1 si hubo algún error con los argumentos*/
static int validarPalabra(char* cadena, int limite)
{
	int retorno = -1;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z'))
			{
				continue;
			}
			else
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

/**
 * \brief Valida que la cadena recibida contenga un nombre o apellido válido
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
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
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
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
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
 * \param float* pResultado: Puntero donde se almacenará el precio
 * \return Retorna 1 (verdadero) si es un precio válido, 0 (falso) si no o -1 si hubo algún error con los argumentos*/
static int validarPrecio(float* pResultado)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		retorno = 1;
		if(*pResultado <= 0)
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
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if(cadena[4] == '-')
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
		if(cadena[4] == '-' && strlen(cadena) == 9)
		{
			retorno = 1;
		}
		else if(strlen(cadena) != 8)
		{
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * \brief Valida que la cadena recibida sea un celular válido
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es un celular, 0 (falso) si no o -1 si hubo algún error con los argumentos*/
static int validarCelular(char* cadena, int limite)
{
	int retorno = -1;
	int signo = 0;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if(cadena[2] == '-')
			{
				signo = 1;
				continue;
			}
			if(signo && cadena[7] == '-')
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
		if(cadena[2] == '-' && cadena[7] == '-' && strlen(cadena) == 12)
		{
			retorno = 1;
		}
		else if(strlen(cadena) != 10)
		{
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * \brief Valida que la cadena recibida contenga un email válido
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es un email, 0 (falso) si no o -1 si hubo algún error con los argumentos*/
static int validarEmail(char* cadena, int limite)
{
	int retorno = -1;
	int i;
	int arroba = 0;
	int punto = 0;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= '0' && cadena[i] <= '9'))
			{
				retorno = 1;
			}
			else if(i > 0 && arroba == 0 && cadena[i] == '@')
			{
				arroba = 1;
				punto = 0;
			}
			else if(i > 0 && i < strlen(cadena) - 1 && cadena[i] == '.' && cadena[i - 1] != '.' && cadena[i - 1] != '@' && cadena[i - 1] != '-' && cadena[i - 1] != '_')
			{
				punto = 1;
				retorno = 1;
			}
			else if((cadena[i] == '-' && cadena[i - 1] != '-' && cadena[i - 1] != '_' && cadena[i - 1] != '.') || (cadena[i] == '_' && cadena[i - 1] != '_' && cadena[i - 1] != '-' && cadena[i - 1] != '.'))
			{
				retorno = 1;
			}
			else
			{
				retorno = 0;
				break;
			}
		}
		if(arroba == 0 || punto == 0 || cadena[i - 1] == '.')
		{
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * \brief Valida que la cadena recibida contenga un sitio web válido
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es un sitio web, 0 (falso) si no o -1 si hubo algún error con los argumentos*/
static int validarSitioWeb(char* cadena, int limite)
{
	int retorno = -1;
	int i;
	int punto = 0;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= '0' && cadena[i] <= '9') || cadena[i] == '-')
			{
				retorno = 1;
			}
			else if(i == 3 && punto == 0 && cadena[i] == '.')
			{
				punto = 1;
				retorno = 1;
			}
			else if(i == strlen(cadena) - 4 && punto == 1 && cadena[i] == '.')
			{
				punto = 2;
				retorno = 1;
			}
			else
			{
				retorno = 0;
				break;
			}
		}
		if(punto == 0 || cadena[0] != 'w' || cadena[1] != 'w' || cadena[2] != 'w')
		{
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * \brief Valida que la cadena recibida sea una tarjeta de crédito válida
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es una tarjeta de crédito, 0 (falso) si no o -1 si hubo algún error con los argumentos*/
static int validarTarjetaCredito(char* cadena, int limite)
{
	int retorno = -1;
	int signo = 0;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if(cadena[4] == '-')
			{
				signo = 1;
				continue;
			}
			if(signo && cadena[9] == '-')
			{
				signo = 2;
				continue;
			}
			if(signo == 2 && cadena[14] == '-')
			{
				signo = 3;
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
		if(cadena[4] == '-' && cadena[9] == '-' && cadena[14] && strlen(cadena) == 19)
		{
			retorno = 1;
		}
		else if(strlen(cadena) != 16)
		{
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * \brief Valida que la cadena recibida contenga una dirección válida
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es una dirección, 0 (falso) si no o -1 si hubo algún error con los argumentos*/
static int validarDireccion(char* cadena, int limite)
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
			else if((cadena[i] >= 'a' && cadena[i] <= 'z') || cadena[i] == ' ')
			{
				continue;
			}
			else
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

/**
 * \brief Valida que la cadena recibida contenga una altura válida de una dirección
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es una altura de dirección, 0 (falso) si no o -1 si hubo algún error con los argumentos*/
static int validarDireccionAltura(char* cadena, int limite)
{
	int retorno = -1;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
		if(strlen(cadena) < 1 || strlen(cadena) > 4)
		{
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * \brief Valida que la cadena recibida contenga un nombre de archivo válido
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es un nombre de archivo, 0 (falso) si no o -1 si hubo algún error con los argumentos*/
static int validarNombreArchivo(char* cadena, int limite)
{
	int retorno = -1;
	int punto = 0;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= '0' && cadena[i] <= '9') || cadena[i] == '-' || cadena[i] == '_')
			{
				retorno = 1;
			}
			else if(punto == 0 && cadena[strlen(cadena) - 4] == '.')
			{
				punto = 1;
				retorno = 1;
			}
			else
			{
				retorno = 0;
				break;
			}
		}
		if(punto == 0)
		{
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * \brief Valida que la cadena recibida contenga un estado civíl válido
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es un estado civíl, 0 (falso) si no o -1 si hubo algún error con los argumentos*/
static int validarEstadoCivil(char* cadena, int limite)
{
	int retorno = -1;

	if(cadena != NULL && limite > 0)
	{
		if(strcmp(cadena, "soltero") == 0 || strcmp(cadena, "casado") == 0 || strcmp(cadena, "divorciado") == 0 || strcmp(cadena, "viudo") == 0)
		{
			retorno = 1;
		}
		else
		{
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * \brief Valida que la cadena recibida contenga un sexo
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es un sexo, 0 (falso) si no o -1 si hubo algún error con los argumentos*/
static int validarSexo(char* cadena, int limite)
{
	int retorno = -1;

	if(cadena != NULL && limite > 0)
	{
		if(strcmp(cadena, "masculino") == 0 || strcmp(cadena, "femenino") == 0)
		{
			retorno = 1;
		}
		else
		{
			retorno = 0;
		}
	}

	return retorno;
}

/**
 * \brief Valida que la cadena recibida contenga una respuesta de si o no
 * \param char* cadena: Cadena de caracteres a ser analizada
 * \param int limite: El limite o tamaño de la cadena
 * \return Retorna 1 (verdadero) si la cadena es una respuesta, 0 (falso) si no o -1 si hubo algún error con los argumentos*/
static int validarRespuestaSiNo(char* cadena, int limite)
{
	int retorno = -1;

	if(cadena != NULL && limite > 0)
	{
		if(strcmp(cadena, "si") == 0 || strcmp(cadena, "no") == 0)
		{
			retorno = 1;
		}
		else
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
