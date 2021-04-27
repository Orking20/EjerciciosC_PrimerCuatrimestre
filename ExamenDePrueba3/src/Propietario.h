/*
 * Razas.h
 *
 *  Created on: 20 abr. 2021
 *      Author: mateo
 */

#ifndef PROPIETARIO_H_
#define PROPIETARIO_H_
#define TAM_NOMBRE 100
#define TAM_DIRECCION 100
#define TAM_TIPO 20
#define TAM_NUM_TARJETA 20

typedef struct
{
	int idPropietario;
	char nombreApellido[TAM_NOMBRE];
	char direccion[TAM_DIRECCION];
	char numTarjeta[TAM_NUM_TARJETA];
	int isEmpty;
}Propietario;

int inicializarPropietario(Propietario* pPropietario, int limite);
int altaPropietario(Propietario* pPropietario, int indice);
int modificarPropietario(Propietario* pPropietario, int limite);
int mostrarPropietario(Propietario* pPropietario, int limite);
int mostrarPropietarioId(Propietario* pPropietario, int limite);

int buscarIndiceVacioPropietario(Propietario* pPropietario, int limite);
int buscarIdPropietario(Propietario* pPropietario, int limite, int id);
int buscarPropietario(Propietario* pPropietario, int limite);

#endif /* PROPIETARIO_H_ */
