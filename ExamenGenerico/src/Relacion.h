/*
 * Relacion.h
 *
 *  Created on: 27 abr. 2021
 *      Author: mateo
 */

#ifndef RELACION_H_
#define RELACION_H_

int altaEstructura(Estructura* pEstructura, Estructura2* pEstructura2, int indice, int limiteRazas);
int modificarEstructura(Estructura* pEstructura, Estructura2* pEstructura2, int limiteCont);
int bajaPropietario(Estructura2* pEstructura2, Estructura* pEstructura, int limitePant);
int borrarEstructura(Estructura* pEstructura, Estructura2* pEstructura2, int limite);
int consultaFacturacion(Estructura* pEstructura, Estructura2* pEstructura2, int limiteCont);

int mostrarEstructura(Estructura* pEstructura, Estructura2* pEstructura2, int limite);
int mostrarEstructuraId(Estructura* pEstructura, Estructura2* pEstructura2, int limite);
int ordenarPorPeso(Estructura* pEstructura, Estructura2* pEstructura2, int limite);
int buscarIdEstructura(Estructura* pEstructura, int limite, int id);

#endif /* RELACION_H_ */
