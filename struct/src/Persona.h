/*
 * Persona.h
 *
 *  Created on: 13 abr. 2021
 *      Author: mateo
 */

#ifndef PERSONA_H_
#define PERSONA_H_

typedef struct
{
	char nombre[50];
	char apellido[50];
	float peso;
	float altura;
}Persona;

int cargaDatosPersona(Persona* pPersonas, int limite, int indice, char nombre[], char apellido[], float peso, float altura);

#endif /* PERSONA_H_ */
