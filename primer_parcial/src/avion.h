/*
 * avion.h
 *
 *  Created on: 21 oct. 2022
 *      Author: USURIO
 */
#ifndef AVION_H_
#define AVION_H_
#include "aerolinea.h"
#include "tipo.h"

typedef struct{
	int id;
	int idAerolinea;
	int idTipo;
	int capacidad;
	int isEmpty;
}avion;

int initAviones(avion avionList[],int len);
int addAviones(avion* list, int len, int id, int idAerolinea,int idTipo, int capacidad);
int findAvionById(avion* pAvion, int len, int idBuscado);
int findEmptyPosition(avion* pAvion, int len);
int removeAvion(avion avionList[], int len, int idBuscado);
int modifyAvion(avion* pAvion);
int printAviones(avion* pAvion, int len, aerolinea* pAerolinea, int lenAerolinea, tipo* pTipo, int lenTipo);
int printAvion(avion pAvion, aerolinea pAerolinea[], int lenAerolinea, tipo pTipo[], int lenTipo);
int sortAvionesPorAerolineaYCapacidad(avion *avionList, int limit);
#endif /* AVION_H_ */
