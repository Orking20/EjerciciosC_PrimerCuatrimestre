/*
 * utn.h
 *
 *  Created on: 25 mar. 2021
 *      Author: mateo
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pNumero, const char* pTexto, const char* mensajeError, int min, int max, int reintentos);
int utn_getDecimal(float* pNumero, const char* pTexto, const char* mensajeError, float min, float max, int reintentos);
int utn_getTexto(char* pString, int limite, const char* pMensaje, const char* pMensajeError);
int utn_getCaracter(char* pChar, const char* pTexto, const char* mensajeError, char min, char max, int reintentos);

#endif /* UTN_H_ */
