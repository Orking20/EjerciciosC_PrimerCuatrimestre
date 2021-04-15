/*
 * utn.h
 *
 *  Created on: 25 mar. 2021
 *      Author: mateo
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pNumero, char* pMensaje, char* pMensajeError, int min, int max, int reintentos);
int utn_getDecimal(float* pNumero, char* pMensaje, char* pMensajeError, float min, float max, int reintentos);
int utn_getTexto(char* pString, int limite, char* pMensaje, char* pMensajeError);
int utn_getCaracter(char* pChar, char* pMensaje, char* pMensajeError, char min, char max, int reintentos);

int utn_getNombre(char* pResultado, int limite, char* pMensaje, char* pMensajeError);

#endif /* UTN_H_ */
