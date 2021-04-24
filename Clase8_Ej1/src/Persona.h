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
	int isEmpty;
}Persona;

int inicializarPersonas(Persona* pArray, int limite);
int cargarPersonas(Persona* pPersona, int limite, int indice);
int eliminarPersonas(Persona* pPersona, int limite);
int mostrarPersonas(Persona* pArray, int limite);
int ordenarPersonas(Persona* pArray, int limite);
int buscarIndiceVacio(Persona* pProducto, int limite);

#endif /* PERSONA_H_ */
