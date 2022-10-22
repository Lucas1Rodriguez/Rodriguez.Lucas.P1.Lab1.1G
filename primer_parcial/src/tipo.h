/*
 * tipo.h
 *
 *  Created on: 21 oct. 2022
 *      Author: USURIO
 */

#ifndef TIPO_H_
#define TIPO_H_


typedef struct
{
	int id;
	char descripcion[20];
}tipo;

int obtenerDescripcionTipo(tipo tipoList[],int id, int len, char descripcion[]);
int printTipos(tipo tipoList[], int len);
#endif /* TIPO_H_ */
