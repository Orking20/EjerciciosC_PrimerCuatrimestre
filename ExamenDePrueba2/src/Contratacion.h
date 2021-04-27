/*
 * Mascotas.h
 *
 *  Created on: 20 abr. 2021
 *      Author: mateo
 */

#ifndef CONTRATACION_H_
#define CONTRATACION_H_
#define TAM_NOMBRE_ARCHIVO 100
#define TAM_CUIT 12

typedef struct
{
	int idContratacion;
	int idPantalla;
	int cantDias;
	char cuitCliente[TAM_CUIT];
	char nombreArchivo[TAM_NOMBRE_ARCHIVO];
	int isEmpty;
}Contratacion;

int inicializarContratacion(Contratacion* pContratacion, int limite);
int buscarIndiceVacioContratacion(Contratacion* pContratacion, int limite);
int buscarContratacion(Contratacion* pContratacion, int limite);

#endif /* CONTRATACION_H_ */
