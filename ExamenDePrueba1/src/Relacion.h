/*
 * Relacion.h
 *
 *  Created on: 23 abr. 2021
 *      Author: mateo
 */

#ifndef RELACION_H_
#define RELACION_H_

int altaMascota(Mascota* pMascotas, Raza* pRazas, int indice, int limiteRazas);
int modificarMascota(Mascota* pMascotas, Raza* pRazas, int limite);
int borrarMascota(Mascota* pMascotas, Raza* pRazas, int limite);
int mostrarMascotas(Mascota* pMascotas, Raza* pRazas, int limite);
int mostrarMascotasId(Mascota* pMascotas, Raza* pRazas, int limite);
int ordenarPorPeso(Mascota* pMascotas, Raza* pRazas, int limite);

#endif /* RELACION_H_ */
