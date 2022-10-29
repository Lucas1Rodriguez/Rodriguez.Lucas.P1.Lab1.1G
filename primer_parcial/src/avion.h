#ifndef AVION_H_
#define AVION_H_
#include "aerolinea.h"
#include "tipo.h"
#include "piloto.h"

typedef struct{
	int id;
	int idAerolinea;
	int idTipo;
	int idPiloto;
	int capacidad;
	int isEmpty;
}avion;

int initAviones(avion avionList[],int len);
int addAviones(avion* list, aerolinea* aerolineasList, tipo* tipoList, piloto* pilotosList, int len, int lenAerolinea, int lenTipo, int lenPiloto, int id, int capacidad);
int findAvionById(avion* pAvion, int len, int idBuscado);
int findEmptyPosition(avion* pAvion, int len);
int removeAvion(avion avionList[], int len, int idBuscado);
int modifyAvion(avion* pAvion);
int printAviones(avion* pAvion, int len,  aerolinea* pAerolinea, int lenAerolinea, tipo* pTipo, int lenTipo, piloto* pPiloto, int lenPiloto);
int printAvion(avion pAvion[], int len, aerolinea pAerolinea[], int lenAerolinea, tipo pTipo[], int lenTipo, piloto pPiloto[], int lenPiloto);
int sortAvionesPorAerolineaYCapacidad(avion *avionList, int limit);
#endif /* AVION_H_ */
