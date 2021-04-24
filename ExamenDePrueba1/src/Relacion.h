/*
 * Relacion.h
 *
 *  Created on: 23 abr. 2021
 *      Author: mateo
 */

#ifndef RELACION_H_
#define RELACION_H_
#define CHICO 1
#define MEDIANO 2
#define GRANDE 3

int altaMascota(Mascota* pMascotas, Raza* pRazas, int indice, int limiteRazas);
int borrarMascota(Mascota* pMascotas, Raza* pRazas, int limite);
int mostrarMascotas(Mascota* pMascotas, Raza* pRazas, int limite);
int mostrarMascotasId(Mascota* pMascotas, Raza* pRazas, int limite);
int ordenarPorId(Mascota* pMascotas, int limite);
int ordenarPorIsEmpty(Mascota* pMascotas, int limite);
int ordenarPorPeso(Mascota* pMascotas, Raza* pRazas, int limite);

#endif /* RELACION_H_ */
