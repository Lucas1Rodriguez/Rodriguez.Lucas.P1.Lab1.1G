#ifndef DESTINO_H_
#define DESTINO_H_

typedef struct
{
	int id;
	char descripcion[20];
	int precio;
}destino;


int printDestinos(destino destinoList[], int len);
int validarDestinos(int id, destino destinos[], int len);
#endif /* DESTINO_H_ */
