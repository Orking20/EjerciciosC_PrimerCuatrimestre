/*
 ============================================================================
 Name        : CharScanf.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Hacer el programa ante la pregunta desea continuar sólo nos
 	 	 	   permita introducir como respuesta 'S' o'N'
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio_ext.h>

int main(void)
{
	char continuar;

	do
	{
		printf("¿Desea cotinuar (S/N)? ");
		__fpurge(stdin);
		scanf("%c", &continuar);
		continuar = toupper(continuar);
	}while(continuar != 'N');

	printf("Saliste exitosamente!");

	return EXIT_SUCCESS;
}
