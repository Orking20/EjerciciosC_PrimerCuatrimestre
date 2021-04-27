/*
 * Pais.h
 *
 *  Created on: 24 abr. 2021
 *      Author: mateo
 */

#ifndef PAIS_H_
#define PAIS_H_
#define TAM_NOMBRE_PAIS 100
#define TAM_CONTINENTE 100

typedef struct
{
	char nombreDePais[TAM_NOMBRE_PAIS];
	char continente[TAM_CONTINENTE];
	int codigoTelefonico;
}Pais;

#endif /* PAIS_H_ */
