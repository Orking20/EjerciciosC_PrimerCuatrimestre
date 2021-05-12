/*
 * Relacion.h
 *
 *  Created on: 23 abr. 2021
 *      Author: mateo
 */

#ifndef RELACION_H_
#define RELACION_H_

int contratacion_alta(Contratacion* pContratacion, Pantalla* pPantalla, int indice, int limiteRazas);
int contratacion_modificar(Contratacion* pContratacion, Pantalla* pPantalla, int limiteCont);
int pantalla_baja(Pantalla* pPantalla, Contratacion* pContratacion, int limitePant);
int contratacion_borrar(Contratacion* pContratacion, Pantalla* pPantalla, int limite);
int consultaFacturacion(Contratacion* pContratacion, Pantalla* pPantalla, int limiteCont);

int contratacion_mostrar(Contratacion* pContratacion, Pantalla* pPantalla, int limite);
int contratacion_mostrarConId(Contratacion* pContratacion, Pantalla* pPantalla, int limite);
int contratacion_buscarId(Contratacion* pContratacion, int limite, int id);

int ordenarPorPeso(Contratacion* pContratacion, Pantalla* pPantalla, int limite);

#endif /* RELACION_H_ */
