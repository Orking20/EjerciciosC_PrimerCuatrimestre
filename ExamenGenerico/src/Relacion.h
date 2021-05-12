/*
 * Relacion.h
 *
 *  Created on: 27 abr. 2021
 *      Author: mateo
 */

#ifndef RELACION_H_
#define RELACION_H_

int estructura_alta(Estructura* pEstructura, Estructura2* pEstructura2, int indice, int limiteRazas);
int estructura_modificar(Estructura* pEstructura, Estructura2* pEstructura2, int limiteCont);
int estructura2_baja(Estructura2* pEstructura2, Estructura* pEstructura, int limitePant);
int estructura_borrar(Estructura* pEstructura, Estructura2* pEstructura2, int limite);
int consultaFacturacion(Estructura* pEstructura, Estructura2* pEstructura2, int limiteCont);

int estructura_mostrar(Estructura* pEstructura, Estructura2* pEstructura2, int limite);
int estructura_mostrarConId(Estructura* pEstructura, Estructura2* pEstructura2, int limite);
int ordenarPorPeso(Estructura* pEstructura, Estructura2* pEstructura2, int limite);
int estructura_buscarPorId(Estructura* pEstructura, int limite, int id);

#endif /* RELACION_H_ */
