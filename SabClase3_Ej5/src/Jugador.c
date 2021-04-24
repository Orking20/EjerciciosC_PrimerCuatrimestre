/*
 * Jugador.c
 *
 *  Created on: 17 abr. 2021
 *      Author: mateo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugador.h"
#include "utn.h"
#define TAM_NOMBRE 64

/**
 * \brief Le deja al usuario cargar los datos de cierta cantidad de jugadores
 * \param Jugador* pJugadores: Cadena donde se almacenarán los datos cargados
 * \param int limite: Limite o tamaño de la cadena
 * \param int indice: Posición de una cadena donde se almacenarán los datos
 * \param int* pFlagPrimeraCarga: Un puntero que permitirá que no se muestren los datos en caso de no haber sido cargados
 * \return Retorna 0 (EXITO) o -1 (ERROR)*/
int cargarJugador(Jugador* pJugadores, int limite, int indice, int* pFlagPrimeraCarga)
{
	int retorno = -1;
	char nombre[TAM_NOMBRE];
	int golesMetidos;
	int partidosJugados;
	int comprobarError;
	Jugador bufferJugador;

	if(pJugadores != NULL && limite > 0 && indice >= 0 && pFlagPrimeraCarga != NULL)
	{
		printf("\nIngresar nuevo jugador");
		comprobarError = utn_getNombre(nombre, TAM_NOMBRE, "\nIngrese el nombre: ", "\nError. Ese no es un nombre válido");
		while(comprobarError == -1)
		{
			comprobarError = utn_getNombre(nombre, TAM_NOMBRE, "\nIngrese el nombre nuevamente: ", "\nError. Ese no es un nombre válido");
		}

		comprobarError = utn_getNumero(&golesMetidos, "\nIngrese los goles metidos: ", "\nError. Ingrese un número válido", 0, 1500, 3);
		while(comprobarError == -1)
		{
			comprobarError = utn_getNumero(&golesMetidos, "\nIngrese los goles metidos nuevamente: ", "\nError. Ingrese un número válido", 0, 1500, 3);
		}

		comprobarError = utn_getNumero(&partidosJugados, "\nIngrese los partidos jugados: ", "\nError. Ingrese un número válido", 0, 1500, 3);
		while(comprobarError == -1)
		{
			comprobarError = utn_getNumero(&partidosJugados, "\nIngrese los partidos jugados nuevamente: ", "\nError. Ingrese un número válido", 0, 1500, 3);
		}

		strncpy(bufferJugador.nombre, nombre, sizeof(bufferJugador.nombre));
		bufferJugador.golesMetidos = golesMetidos;
		bufferJugador.partidosJugados = partidosJugados;
		bufferJugador.promedioGoles = (float)golesMetidos / partidosJugados;

		*pFlagPrimeraCarga = 1;
		pJugadores[indice] = bufferJugador;
		retorno = 0;
	}

	return retorno;
}

/**
 * \brief Muestra una lista de todos los jugadores y toda su información
 * \param Jugador* pJugadores: Cadena que va a ser recorrida para mostrar todas sus posiciones
 * \param int limite: Limite o tamaño de la cadena
 * \return Retorna 0 (EXITO) o -1 (ERROR)*/
int mostrarJugadores(Jugador* pJugadores, int limite)
{
	int retorno = -1;

	if(pJugadores != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			printf("\nNombre: %s - Goles metidos: %d - Partidos jugados: %d", pJugadores[i].nombre, pJugadores[i].golesMetidos, pJugadores[i].partidosJugados);
		}
		retorno = 0;
	}

	return retorno;
}

/**
 * \brief Promedia los goles de cada jugador con respecto a los partidos jugados
 * \param Jugador* pJugadores: Cadena que va a ser recorrida para calcular y mostrar el promedio de todas las posiciones
 * \param int limite: Limite o tamaño de la cadena
 * \return Retorna 0 (EXITO) o -1 (ERROR)*/
int promediarGoles(Jugador* pJugadores, int limite)
{
	int retorno = -1;

	if(pJugadores != NULL && limite > 0)
	{
		for(int i = 0; i < limite; i++)
		{
			pJugadores[i].promedioGoles = (float)pJugadores[i].golesMetidos / pJugadores[i].partidosJugados;

			printf("\nNombre: %s - Promedio de goles: %.2f", pJugadores[i].nombre, pJugadores[i].promedioGoles);
		}
		retorno = 0;
	}

	return retorno;
}
