/*
 * Informes.h
 *
 *  Created on: 25 abr. 2021
 *      Author: mateo
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int infoContratacionesConImportePorCliente(Contratacion* pContrataciones, Pantalla* pPantallas, int limiteContrataciones, int limitePantalla);
int info_imprimirContratacionesConImporte(Contratacion* pContrataciones, Pantalla* pPantallas, int limiteContrataciones, int limitePantalla, char* auxiliarCuit);

#endif /* INFORMES_H_ */
