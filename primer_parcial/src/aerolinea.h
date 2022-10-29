#ifndef AEROLINEA_H_
#define AEROLINEA_H_


typedef struct
{
	int id;
	char descripcion[20];
}aerolinea;

int obtenerDescripcionAerolinea(aerolinea aerolineasList[],int id, int len, char descripcion[]);
int printAerolineas(aerolinea aerolineasList[], int len);
#endif /* AEROLINEA_H_ */
