/*
 * Persona.c
 *
 *  Created on: 13 abr. 2021
 *      Author: mateo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Persona.h"

/** \brief Carga valores iniciales en el array
 *  \param Persona[] aPersona: Puntero a estructura Persona
 *  \param int limite: Limite del array
 *  \param int indice: Indica en que posicion cargar los datos
 *  \param char[] nombre: Es el nombre de la persona
 *  \param char[] apellido: Es el apellido de la persona
 *  \param float altura: Es la altura de la persona expresada en metros
 *  \param float peso: Es el peso de la persona expresado en kilos
 *  \return Retorna 0 (EXITO) en caso de haber cargado los datos correctamente o -1 (ERROR) si no
 */
int cargaDatosPersona(Persona* pPersonas, int limite, int indice,char nombre[],char apellido[], float peso, float altura)
{
	int retorno = -1;

	if(pPersonas != NULL && limite > 0 && indice >= 0 && indice < limite && nombre != NULL && apellido != NULL)
	{
		strncpy(pPersonas[indice].nombre, nombre, sizeof(pPersonas));
		strncpy(pPersonas[indice].apellido, apellido, sizeof(pPersonas));
		pPersonas[indice].peso = altura;
		pPersonas[indice].altura = peso;
		retorno = 0;
	}

	return retorno;
}
