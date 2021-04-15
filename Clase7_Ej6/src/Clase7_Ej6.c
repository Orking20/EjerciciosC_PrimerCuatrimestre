/*
 ============================================================================
 Name        : Clase7_Ej6.c
 Author      : Mateo Luchetti Capalbo
 Version     :
 Copyright   : Your copyright notice
 Description : Dado el texto almacenado en el array de char "texto", realizar una función
 	 	 	   que reciba un array de char y su longitud y devuelva por referencia la
 	 	 	   cantidad de palabras encontradas y probarla con dicho texto
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarPalabras(char cadena[], int limite, int* pPalabras);

int main(void)
{
	int palabras;
	char texto[] = "C es un lenguaje de programación de propósito general originalmente desarrollado por Dennis Ritchie entre 1969 y 1972 en los Laboratorios Bell, como evolución del anterior lenguaje B, a su vez basado en BCPL.";

	if(contarPalabras(texto, sizeof(texto), &palabras) == 0)
	{
		printf("El texto contiene %d palabras", palabras);
	}

	return EXIT_SUCCESS;
}

/**
 * \brief Cuenta la cantidad de palabras en un array
 * \param char cadena: El array a ser analizado
 * \param int limite: El límite o tamaño de la cadena
 * \param int pPalabras: Puntero donde se almacenará la cantidad de palabras en el texto
 * \return Retorna 0 (EXITO) y -1 (ERROR)*/
int contarPalabras(char cadena[], int limite, int* pPalabras)
{
	int retorno = -1;
	int palabras = 0;

	if(cadena != NULL && limite > 0 && pPalabras != NULL)
	{
		for(int i = 0; i < limite && cadena[i] != '\0'; i ++)
		{
			if(cadena[i] == ' ' || cadena[i] == '.')
			{
				palabras++;
			}
		}

		*pPalabras = palabras;
		retorno = 0;
	}

	return retorno;
}
