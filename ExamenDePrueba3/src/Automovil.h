/*
 * Mascotas.h
 *
 *  Created on: 20 abr. 2021
 *      Author: mateo
 */

#ifndef AUTOMOVIL_H_
#define AUTOMOVIL_H_
#define TAM_PATENTE 20
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

typedef struct
{
	int idAutomovil;
	int idPropietario;
	int marca;
	char patente[TAM_PATENTE];
	int isEmpty;
}Automovil;

int inicializarAutomovil(Automovil* pAutomovil, int limite);
int buscarIndiceVacioAutomovil(Automovil* pAutomovil, int limite);
int buscarAutomovil(Automovil* pAutomovil, int limite);

#endif /* AUTOMOVIL_H_ */
