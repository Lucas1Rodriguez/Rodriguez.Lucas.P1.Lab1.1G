/*
 * destino.h
 *
 *  Created on: 21 oct. 2022
 *      Author: USURIO
 */

#ifndef DESTINO_H_
#define DESTINO_H_

typedef struct
{
	int id;
	char descripcion[20];
	int precio;
}destino;


int printDestinos(destino destinoList[], int len);
#endif /* DESTINO_H_ */
