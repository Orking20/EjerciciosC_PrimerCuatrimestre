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
#define TAM_NOMBRE 100

int main(void)
{
	int numero;
	float decimal;
	char letra;
	char texto[TAM_ARRAY];
	char nombre[TAM_NOMBRE];

	if(utn_getNumero(&numero, "Ingrese un número positivo hasta el 1000: \n", "Error en los argumentos\n", -1000, 1000, 3) == 0)
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
		printf("%s", texto);
	}

	if(utn_getNombre(nombre, TAM_NOMBRE, "Ingrese su nombre: \n", "Error. Eso no es un nombre, solo se permiten letras\n") == 0)
	{
		printf("%s", nombre);
	}

	return EXIT_SUCCESS;
}
