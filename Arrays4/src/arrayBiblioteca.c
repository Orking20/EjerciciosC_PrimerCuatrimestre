#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

/**
 * \brief				Muestra todos los elementos de un array y sus valores
 *
 * \param array[]		La lista que va a ser leída
 * \param tamanoArray	El número de elementos que tiene el array
 *
 * \return				Retorna -1 si hay algún error o 0 si salió todo bien*/
int mostrarArray(int array[], int tamanoArray)
{
	int retorno = -1;

	if(array != NULL && tamanoArray > 0)
	{
		for(int i = 0; i < tamanoArray; i++)
		{
			printf("Elemento %d: %d\n", i + 1, array[i]);
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * \brief				Recorre un array y por medio de un puntero devuelve el número mayor
 *
 * \param array[]		La lista que va a ser leída
 * \param tamanoArray	El número de elementos que tiene el array
 * \param pMaximo		El puntero donde se va a almacenar el número mayor y va a ser llevado al main
 *
 * \return				Retorna -1 si hay algún error o 0 si salió todo bien*/
int numeroMaxArray(int array[], int tamanoArray, int* pMaximo)
{
	int retorno = -1;
	*pMaximo = array[0];

	if(array != NULL && tamanoArray > 0 && pMaximo != NULL)
	{
		for(int i = 0; i < tamanoArray; i++)
		{
			if(array[i] > *pMaximo)
			{
				*pMaximo = array[i];
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
int numeroMinArray(int array[], int tamanoArray, int* pMinimo)
{
	int retorno = -1;
	*pMinimo = array[0];

	if(array != NULL && tamanoArray > 0 && pMinimo != NULL)
	{
		for(int i = 0; i < tamanoArray; i++)
		{
			if(array[i] < *pMinimo)
			{
				*pMinimo = array[i];
			}
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * \brief				Recorre un array y por medio de un puntero devuelve el promedio de todos los números
 *
 * \param array[]		La lista que va a ser leída
 * \param tamanoArray	El número de elementos que tiene el array
 * \param pPromedio		El puntero donde se va a almacenar el promedio y va a ser llevado al main
 *
 * \return				Retorna -1 si hay algún error o 0 si salió todo bien*/
int promedioArray(int array[], int tamanoArray, float* pPromedio)
{
	int retorno = -1;
	float acumulador = 0;

	if(array != NULL && tamanoArray > 0 && pPromedio != NULL)
	{
		for(int i = 0; i < tamanoArray; i++)
		{
			acumulador += array[i];
		}
		retorno = 0;
	}

	*pPromedio = acumulador / tamanoArray;

	return retorno;
}

/**
 * \brief				Cambia el valor del elemento deseado de una lista
 *
 * \param array[]		La lista a la cual queremos cambiarle algún valor
 * \param tamanoArray	El número de elementos que tiene el array
 * \param valorNuevo	El puntero donde se va a almacenar el nuevo valor y va a ser llevado al main
 *
 * \return				Retorna -1 si hay algún error o 0 si salió todo bien*/
int modificarValoresArray(int array[], int tamanoArray, int* pValorNuevo)
{
	int retorno = -1;
	int posicionCambiar;

	if(array != NULL && tamanoArray > 0 && pValorNuevo != NULL)
	{
		printf("Seleccione el elemento a cambiar: ");
		scanf("%d", &posicionCambiar);
		if(posicionCambiar >= 1 && posicionCambiar <= tamanoArray)
		{
			printf("Ingrese el nuevo valor: ");
			scanf("%d", pValorNuevo);

			array[posicionCambiar - 1] = *pValorNuevo;

			printf("\nNuevos valores:\n");

			for(int i = 0; i < tamanoArray; i++)
			{
				printf("Elemento %d: %d\n", i + 1, array[i]);
			}
			retorno = 0;
		}
		else
		{
			printf("\nEl elemento ingresado está fuera de rango\n");
		}

	}


	return retorno;
}
