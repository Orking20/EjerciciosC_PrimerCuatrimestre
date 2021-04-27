/*
 * Relacion.h
 *
 *  Created on: 23 abr. 2021
 *      Author: mateo
 */

#ifndef RELACION_H_
#define RELACION_H_

int altaContratacion(Contratacion* pContratacion, Pantalla* pPantalla, int indice, int limiteRazas);
int modificarContratacion(Contratacion* pContratacion, Pantalla* pPantalla, int limiteCont);
int bajaPantalla(Pantalla* pPantalla, Contratacion* pContratacion, int limitePant);
int borrarContratacion(Contratacion* pContratacion, Pantalla* pPantalla, int limite);
int consultaFacturacion(Contratacion* pContratacion, Pantalla* pPantalla, int limiteCont);

int mostrarContratacion(Contratacion* pContratacion, Pantalla* pPantalla, int limite);
int mostrarContratacionId(Contratacion* pContratacion, Pantalla* pPantalla, int limite);
int ordenarPorPeso(Contratacion* pContratacion, Pantalla* pPantalla, int limite);
int buscarIdContratacion(Contratacion* pContratacion, int limite, int id);

#endif /* RELACION_H_ */
