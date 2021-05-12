/*
 ============================================================================
 Name        : PedirDatos.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Probando la biblioteca utn.h
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define TAM_ARRAY 4096
#define TAM_PALABRA 1024
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
#define TAM_CADENA_MAYUSUCULAS 2024
#define TAM_NOMBRE_ARCHIVO 64
#define TAM_ESTADO_CIVIL 20
#define TAM_SEXO 20
#define TAM_RESPUESTA 3

int main(void)
{
	/*int numero;
	float decimal;
	char letra;
	char texto[TAM_ARRAY];
	char nombre[TAM_NOMBRE];
	char descripcion[TAM_DESCRIPCION];
	char dni[TAM_DNI];
	char cuit[TAM_CUIT];
	int edad;
	float precio;
	char telefono[TAM_TELEFONO];
	char celular[TAM_CELULAR];
	char email[TAM_EMAIL];
	char sitioWeb[TAM_SITIO_WEB];
	char tarjetaCredito[TAM_TARJETA_CREDITO];
	char direccion[TAM_DIRECCION];
	char textoMayusculas[TAM_CADENA_MAYUSUCULAS];
	char textoMinusculas[TAM_CADENA_MAYUSUCULAS];
	char palabra[TAM_PALABRA];
	char nombreArchivo[TAM_NOMBRE_ARCHIVO];
	char estadoCivil[TAM_ESTADO_CIVIL];
	char sexo[TAM_SEXO];*/
	char respuesta[TAM_RESPUESTA];


/*	if(utn_getNumero(&numero, "Ingrese un número positivo hasta el 1000: \n", "Error en los argumentos\n", -1000, 1000, 3) == 0)
	{
		printf("Numero ingresado: %d\n", numero);
	}

	if(utn_getDecimal(&decimal, "Ingrese un decimal: \n", "Error en los argumentos\n", -1000, 1000, 3) == 0)
	{
		printf("Numero ingresado: %0.2f\n", decimal);
	}

	if(utn_getCaracter(&letra, "Ingrese una letra: \n", "Error de arguentos\n", 'a', 'z', 2) == 0)
	{
		printf("Letra: %c\n", letra);
	}

	if(utn_getTexto(texto, TAM_ARRAY, "Ingrese un texto: \n", "Error en los argumentos\n") == 0)
	{
		printf("%s\n", texto);
	}

	if(utn_getNombre(nombre, "Ingrese su nombre: \n", "Error. Eso no es un nombre, solo se permiten letras\n") == 0)
	{
		printf("%s\n", nombre);
	}

	if(utn_getDescripcion(descripcion, "Ingrese la descripción\n", "Error. Esa descripción no es válida\n") == 0)
	{
		printf("%s\n", descripcion);
	}

	if(utn_getDni(dni, "Ingrese el DNI: \n", "Error. Este no es un DNI válido\n") == 0)
	{
		printf("%s\n", dni);
	}

	if(utn_getCuit(cuit, "Ingrese el CUIT: \n", "Error. Este no es un CUIT válido\n") == 0)
	{
		printf("%s\n", cuit);
	}

	if(utn_getEdad(&edad, "Ingrese la edad: \n", "Error. Esa no es una edad válida\n") == 0)
	{
		printf("%d\n", edad);
	}

	if(utn_getPrecio(&precio, "Ingrese el precio: \n", "Error. Ese no es un precio válido\n") == 0)
	{
		printf("%f\n", precio);
	}

	if(utn_getTelefono(telefono, "Ingrese el teléfono: \n", "Error. Este no es un teléfono válido\n") == 0)
	{
		printf("%s\n", telefono);
	}

	if(utn_getCelular(celular, "Ingrese el celular: \n", "Error. Ese celular no es válido\n") == 0)
	{
		printf("%s\n", celular);
	}

	if(utn_getEmail(email, "Ingrese el mail: \n", "Error. Este email no es válido\n") == 0)
	{
		printf("%s\n", email);
	}

	if(utn_getSitioWeb(sitioWeb, "Ingrese un sitio web: \n", "Error. Ese sitio web no es válido\n") == 0)
	{
		printf("%s\n", sitioWeb);
	}

	if(utn_getTarjetaCredito(tarjetaCredito, "Ingrese la tarjeta de crédito: \n", "Error. Esa no es una tarjeta de crédito válida\n") == 0)
	{
		printf("%s\n", tarjetaCredito);
	}

	if(utn_getDireccion(direccion, "Ingrese una dirección: \n", "Ingrese una altura: \n", "Error. Esa no es una dirección válida\n", "Debes ingresar la altura\n") == 0)
	{
		printf("%s\n", direccion);
	}

	if(utn_getCadenaMayusculas(textoMayusculas, TAM_CADENA_MAYUSUCULAS, "Ingrese un texto: \n", "Error.\n") == 0)
	{
		printf("%s\n", textoMayusculas);
	}

	if(utn_getCadenaMinusculas(textoMinusculas, TAM_CADENA_MAYUSUCULAS, "Ingrese un texto: \n", "Error.\n") == 0)
	{
		printf("%s\n", textoMinusculas);
	}

	if(utn_getPalabra(palabra, TAM_PALABRA, "Ingrese una palabra:\n", "Error. Esa no es una palabra\n") == 0)
	{
		printf("%s\n", palabra);
	}

	if(utn_getNombreArchivo(nombreArchivo, "Ingrese el nombre del archivo:\n", "Error. Ese nombre de archivo no es válido\n") == 0)
	{
		printf("%s\n", nombreArchivo);
	}

	if(utn_getEstadoCivil(estadoCivil, "Ingrese el estado civíl (soltero/casado/divorciado/viudo):\n", "Error. Ese estado civíl no es válido\n") == 0)
	{
		printf("%s\n", estadoCivil);
	}

	if(utn_getSexo(sexo, "Ingrese el sexo (masculino/femenino):\n", "Error. Ese sexo no es válido\n") == 0)
	{
		printf("%s\n", sexo);
	}*/

	if(utn_getRespuestaSiNo(respuesta, "Ingrese una respuesta (si/no):\n", "Error. Solo puede ingresar si o no\n"))
	{
		printf("%s\n", respuesta);
	}

	return EXIT_SUCCESS;
}
