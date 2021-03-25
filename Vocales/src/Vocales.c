/*
 ============================================================================
 Name        : Vocales.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Escribir un programa que realice lea por teclado 20 caracteres.
 	 	 	   Luego de la lectura indicar cuantas "a" se ingresaron,
 	 	 	   cuantas "e, i, o, u"
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int main(void)
{
	char caracter;
	int contador;

	contador = 0;

	for(int i = 0; i < 20; i++)
	{
		printf("Ingrese un caracter: ");
		__fpurge(stdin);
		scanf("%c", &caracter);

		if(caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u')
		{
			contador++;
		}
	}

	printf("Se ingresaron %d vocales en total", contador);

	return EXIT_SUCCESS;
}
