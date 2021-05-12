/*
 * Relacion.h
 *
 *  Created on: 28 abr. 2021
 *      Author: mateo
 */

#ifndef RELACION_H_
#define RELACION_H_

int estructura_alta(Estructura* pEstructura, Entidad* pEntidad, int limiteEstructura, int limiteEntidad, int indice);
int estructura_modificar(Estructura* pEstructura, Entidad* pEntidad, int limiteEstructura, int limiteEntidad);
int entidad_baja(Entidad* pEntidad, Estructura* pEstructura, int limiteEntidad, int limiteEstructura);
int estructura_baja(Estructura* pEstructura, Entidad* pEntidad, int limiteEstructura, int limiteEntidad);
int estructura_mostrar(Estructura* pEstructura, Entidad* pEntidad, int limiteEstructura, int limiteEntidad);

#endif /* RELACION_H_ */
