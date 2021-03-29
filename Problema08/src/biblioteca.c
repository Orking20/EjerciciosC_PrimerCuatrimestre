/*
 * biblioteca.c
 *
 *  Created on: 27 mar. 2021
 *      Author: mateo
 */


int averiguarEntero(int numero)
{
	int retorno;

	if(numero > 0)
	{
		retorno = 1;
	}
	else if(numero < 0)
	{
		retorno = -1;
	}
	else
	{
		retorno = 0;
	}

	return retorno;
}

int promedio(int sumaNumeros, int cantNumeros)
{
	int promedio;

	promedio = sumaNumeros / cantNumeros;

	return promedio;
}

int sumaAntecesores(int numero)
{
	int acumulador = 0;

	for(int i = 0; i > numero; i--)
	{
		acumulador += i;
	}

	return acumulador;
}
