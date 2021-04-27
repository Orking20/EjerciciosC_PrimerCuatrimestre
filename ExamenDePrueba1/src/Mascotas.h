/*
 * Mascotas.h
 *
 *  Created on: 20 abr. 2021
 *      Author: mateo
 */

#ifndef MASCOTAS_H_
#define MASCOTAS_H_
#define TAM_NOMBRE 100
#define TAM_TIPO 64

typedef struct
{
	int idMascota;
	int idRaza;
	char nombre[TAM_NOMBRE];
	int edad;
	char sexo;
	char tipo[TAM_TIPO];
	int isEmpty;
}Mascota;

int inicializarMascotas(Mascota* pMascotas, int limite);
void harcodeoMascotas(Mascota* pMascotas, int limite);
int buscarIndiceVacioMascota(Mascota* pMascotas, int limite);
int buscarMascotas(Mascota* pMascota, int limite);

#endif /* MASCOTAS_H_ */
