#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

/*
 * \brief				Ordena de menor a mayor un array*/
int ordenArray(int* array, int limite, int* punteroMinimo)
{
	int retorno = -1;
	int valorMinimo;
	int indiceMinimo;
	int auxiliar;

	if(array != NULL && limite > 0 && punteroMinimo != NULL)
	{
		for(int i = 0; i < limite - 1; i++)
		{
			numeroMinArray(array, limite, i, &valorMinimo, &indiceMinimo);

			if(i != indiceMinimo)
			{
				auxiliar = array[i];
				array[i] = valorMinimo;
				array[indiceMinimo] = auxiliar;
			}
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * \brief				Recorre un array y por medio de un puntero devuelve el número menor
 *
 * \param array[]		La lista que va a ser leída
 * \param tamanoArray	El número de elementos que tiene el array
 * \param pMinimo		El puntero donde se va a almacenar el número menor y va a ser llevado al main
 *
 * \return				Retorna -1 si hay algún error o 0 si salió todo bien*/
int numeroMinArray(int array[], int tamanoArray, int inicio, int* pValorMinimo, int* pIndiceMinimo)
{
	int retorno = -1;
	int indice;
	int minimo = array[inicio];

	if(array != NULL && tamanoArray > 0 && pValorMinimo != NULL && pIndiceMinimo != NULL)
	{
		for(int i = inicio; i < tamanoArray; i++)
		{
			if(array[i] < minimo)
			{
				minimo = array[i];
				indice = i;
			}
		}
		*pValorMinimo = minimo;
		*pIndiceMinimo = indice;
		retorno = 0;
	}

	return retorno;
}
