/*
 * Relacion.h
 *
 *  Created on: 23 abr. 2021
 *      Author: mateo
 */

#ifndef RELACION_H_
#define RELACION_H_

int altaAutomovil(Automovil* pAutomovil, Propietario* pPropietario, int indice, int limiteRazas);
int modificarAutomovil(Automovil* pAutomovil, Propietario* pPropietario, int limiteCont);
int bajaPropietario(Propietario* pPropietario, Automovil* pAutomovil, int limitePant);
int borrarAutomovil(Automovil* pAutomovil, Propietario* pPropietario, int limite);
int consultaFacturacion(Automovil* pAutomovil, Propietario* pPropietario, int limiteCont);

int mostrarAutomovil(Automovil* pAutomovil, Propietario* pPropietario, int limite);
int mostrarAutomovilId(Automovil* pAutomovil, Propietario* pPropietario, int limite);
int ordenarPorPeso(Automovil* pAutomovil, Propietario* pPropietario, int limite);
int buscarIdAutomovil(Automovil* pAutomovil, int limite, int id);

#endif /* RELACION_H_ */
