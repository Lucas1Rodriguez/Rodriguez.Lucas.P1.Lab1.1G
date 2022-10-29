#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avion.h"
#include "aerolinea.h"
#include "tipo.h"
#include "destino.h"
#include "vuelo.h"
#include "piloto.h"
#include "menu.h"
#include "utn_biblioteca.h"

#define LEN_AVION 10
#define LEN_AEROLINEA 5
#define LEN_TIPO 4
#define LEN_DESTINO 4
#define LEN_VUELO 10
#define LEN_PILOTO 10

int main(void) {

	avion avionesList[LEN_AVION] =
	{
		{1, 30, "Iberia","Jet", "Martin Alamo"},
		{2, 295, "Lan","Helice", "Axel Carballo"},
		{3, 123, "Norwegian","Planeador", "Eric Olmedo"},
		{4, 235, "American","Carga", "Sabrina Cervera"},
		{5, 54, "Austral","Jet", "Margarita Arjona"},
		{6, 239, "Austral","Helice", "Alícia Merchan"},
		{7, 104, "Lan","Planeador", "Gustavo Valle"},
		{8, 259, "Norwegian","Jet", "Nancy Carro"},
		{9, 12, "American","Planeador", "Gines Cruz"},
		{10, 80, "Austral","Jet", "Margarita Arjona"}
	};

	aerolinea aerolineasList[LEN_AEROLINEA] =
	{
		{1000,"Lan"},
		{1001,"Iberia"},
		{1002,"Norwegian"},
		{1003,"American"},
		{1004,"Austral"}
	};

	tipo tipoList[LEN_TIPO] =
	{
		{5000,"Jet"},
		{5001,"Helice"},
		{5002,"Planeador"},
		{5003,"Carga"}
	};

	destino destinoList[LEN_DESTINO] =
	{
		{2000,"Calafate: ",22250},
		{2001,"Miami: ",103000},
		{2002,"Milan: ",84400},
		{2003,"Amsterdam: ",95600}
	};

	vuelo vueloList[LEN_VUELO];

	piloto pilotoList[LEN_PILOTO]={
		{3000,"Martin Alamo","Hombre"},
		{3001,"Axel Carballo","Hombre"},
		{3002,"Margarita Arjona","Mujer"},
		{3003,"Sabrina Cervera","Mujer"},
		{3004,"Eric Olmedo","Hombre"},
		{3005,"Alícia Merchan","Mujer"},
		{3006,"Gustavo Valle","Hombre"},
		{3007,"Nancy Carro","Mujer"},
		{3008,"Gines Cruz","Mujer"},
		{3009,"Mateo Carreño","Hombre"}
	};

	initAviones(avionesList,LEN_AVION);

	initVuelos(vueloList, LEN_VUELO);


	menu(avionesList, LEN_AVION, aerolineasList, LEN_AEROLINEA, tipoList, LEN_TIPO, destinoList, LEN_DESTINO, vueloList, LEN_VUELO, pilotoList, LEN_PILOTO);

	return EXIT_SUCCESS;
}
