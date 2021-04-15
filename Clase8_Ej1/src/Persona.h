/*
 * Persona.h
 *
 *  Created on: 14 abr. 2021
 *      Author: mateo
 */

#ifndef PERSONA_H_
#define PERSONA_H_

typedef struct
{
	char nombre[100];
	char apellido[100];
	int legajo;
	int indice;
	int isEmpty;
}Persona;

int inicializarPersonas(Persona* pArray, int limite);
int cargarPersonas(Persona* pPersona, int limite, int indice, char* nombre, char* apellido, int legajo);
int mostrarPersonas(Persona* pArray, int limite);
int ordenarPersonas(Persona* pArray, int limite);

#endif /* PERSONA_H_ */
