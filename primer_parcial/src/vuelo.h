#ifndef VUELO_H_
#define VUELO_H_
#include "avion.h"
#include "destino.h"


typedef struct{
	int dia;
	int mes;
	int ano;
}eFecha;

typedef struct{
	int id;
	int idAvion;
	int idDestino;
	eFecha fecha;
	int isEmpty;
}vuelo;


int initVuelos(vuelo vuelosList[],int len);
int addVuelos(vuelo* list, destino* destinoList, int len, int lenDestino);
int printVuelos(vuelo vuelosList[], int len);
int findEmptyPositionVuelo(vuelo* pVuelo, int len);
#endif /* VUELO_H_ */
