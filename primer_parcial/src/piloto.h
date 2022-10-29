/*
 * piloto.h
 *
 *  Created on: 28 oct. 2022
 *      Author: USURIO
 */

#ifndef PILOTO_H_
#define PILOTO_H_

typedef struct
{
	int id;
	char nombre[20];
	char sexo[6];
}piloto;


int obtenerNombrePiloto(piloto pilotosList[],int id, int len, char nombre[]);
int printPilotos(piloto pilotosList[], int len);
#endif /* PILOTO_H_ */
