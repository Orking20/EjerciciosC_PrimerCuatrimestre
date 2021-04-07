#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

void ordenArray(int* array, int limite, int* punteroMinimo)
{
	int indiceMinimo;
	int auxiliar;

	for(int i = 0; i < limite - 1; i++)
	{
		numeroMinArray(array, limite, &indiceMinimo);

		if(i != array[indiceMinimo])
		{
			auxiliar = array[i];
			array[i] = array[indiceMinimo];
			array[indiceMinimo] = auxiliar;
		}
	}
}

/**
 * \brief				Recorre un array y por medio de un puntero devuelve el número menor
 *
 * \param array[]		La lista que va a ser leída
 * \param tamanoArray	El número de elementos que tiene el array
 * \param pMinimo		El puntero donde se va a almacenar el número menor y va a ser llevado al main
 *
 * \return				Retorna -1 si hay algún error o 0 si salió todo bien*/
int numeroMinArray(int array[], int tamanoArray, int* pIndiceMinimo)
{
	int retorno = -1;
	int indice = 0;


	if(array != NULL && tamanoArray > 0 && pIndiceMinimo != NULL)
	{
		for(int i = 0; i < tamanoArray; i++)
		{
			if(array[i] < array[indice])
			{
				indice = i;
			}
		}
		*pIndiceMinimo = indice;
		retorno = 0;
	}

	return retorno;
}
