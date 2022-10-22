#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avion.h"
#include "aerolinea.h"
#include "tipo.h"
#include "destino.h"
#include "menu.h"
#include "utn_biblioteca.h"

#define LEN_AVION 20
#define LEN_AEROLINEA 5
#define LEN_TIPO 4
#define LEN_DESTINO 4

int main(void) {

	avion avionesList[LEN_AVION];

	aerolinea aerolineasList[LEN_AEROLINEA]=
	{
		{1000,"Lan"},
		{1001,"Iberia"},
		{1002,"Norwegian"},
		{1003,"American"},
		{1004,"Austral"}
	};

	tipo tipoList[LEN_TIPO]=
	{
		{5000,"Jet"},
		{5001,"Helice"},
		{5002,"Planeador"},
		{5003,"Carga"},
	};

	destino destinoList[LEN_DESTINO]=
		{
			{20000,"Calafate: $",22250},
			{20001,"Miami: $",103000},
			{20002,"Milan: $",84400},
			{20003,"Amsterdam: $",95600},
		};

		initAviones(avionesList,LEN_AVION);

		menuAvion(avionesList, LEN_AVION, aerolineasList, LEN_AEROLINEA, tipoList, LEN_TIPO, destinoList, LEN_DESTINO);

	return EXIT_SUCCESS;
}
