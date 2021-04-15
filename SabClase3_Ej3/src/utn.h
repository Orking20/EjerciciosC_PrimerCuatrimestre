/*
 * utn.h
 *
 *  Created on: 25 mar. 2021
 *      Author: mateo
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pNumero, const char* pTexto, const char* mensajeError, int min, int max, int reintentos);
float utn_getFloat (float* pNumero,	const char* pTexto,	const char* mensajeError, float min, float max, int reintentos);
char utn_getChar (char* pChar, const char* pTexto, const char* mensajeError, char min, char max, int reintentos);

int ordenamientoCreciente(int* cadena, int limite);
int ordenamientoDecreciente(int* cadena, int limite);

#endif /* UTN_H_ */
