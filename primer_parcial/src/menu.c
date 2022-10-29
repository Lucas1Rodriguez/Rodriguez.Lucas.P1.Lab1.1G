#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "avion.h"
#include "aerolinea.h"
#include "tipo.h"
#include "destino.h"
#include "vuelo.h"
#include "informes.h"
#include "utn_biblioteca.h"


void menu(avion avionList[], int len, aerolinea aerolineaList[], int lenAerolinea, tipo tipoList[], int lenTipo, destino destinoList[], int lenDestino, vuelo vueloList[], int lenVuelo, piloto pilotoList[], int lenPiloto)
{
	int option;
	int optionInformes;
	int lugarLibre;
	int flag = 0;
	int flagVuelo = 0;
	do{
		if (utn_getNumeroInt(&option, "\nBienvenido \n1)Alta Avion:\n2)Modificar Avion:\n3)Baja Avion:\n4)Listar Aviones:\n5)Listar Aerolineas\n6)Listar Tipos de Aviones\n7)Listar Destinos\n8)Alta Vuelo\n9)Listar Vuelo\n10)Informes\n11)Salir\n", "\nError opcion Invalida",  1, 11, 5)==0)
			{
			switch (option)
				{
					case 1:
						//Busco lugar libre
						lugarLibre = findEmptyPosition(avionList, len);
						//Pido y cargo los datos ingresados
						addAviones(&avionList[lugarLibre], &aerolineaList[lugarLibre], &tipoList[lugarLibre], &pilotoList[lugarLibre], len, lenAerolinea, lenTipo, lenPiloto, avionList[lugarLibre].id, avionList[lugarLibre].capacidad);
						flag=1;
						break;

					case 2:
						//verifico que se haya cumplido la opcion 1
						if(flag==1)
						{
							int idIngresado;
							int indexAModif;
							printAviones(avionList, len, aerolineaList, lenAerolinea, tipoList, lenTipo, pilotoList, lenPiloto);
							//pido que ingrese un numero a buscar
							//verifico que exista
							//llamo a la funcion modificar y imprimo
							if (utn_getNumeroInt(&idIngresado, "\nIngrese ID\n", "Error", 1, 20, 5) ==0)
							{
								indexAModif = findAvionById(avionList,len,idIngresado);
								if(indexAModif >=0)
								{
									modifyAvion(&avionList[indexAModif]);
									printAvion(&avionList[indexAModif], len, aerolineaList, lenAerolinea, tipoList, lenTipo, pilotoList, lenPiloto);
								}
							}
						}
						else{
							printf("Error, no hay aviones cargados\n");
						}
						break;

					case 3:
						//verifico que la opcion 1 se haya ingresado
						if(flag ==1)
						{
							int idIngresado;
							int idDarBaja;

							printAviones(avionList, len, aerolineaList, lenAerolinea, tipoList, lenTipo, pilotoList, lenPiloto);
							//pido que ingrese un numero a buscar
							//verifico que exista
							//llamo a la funcion eliminar y imprimo
							if (utn_getNumeroInt(&idIngresado, "\nIngrese ID a eliminar\n", "Error", 1, 20, 5) ==0)
							{
								idDarBaja = findAvionById(avionList,len,idIngresado);
								if(idDarBaja>=0)
								{
									removeAvion(avionList,len,idIngresado);
									printf("avion eliminado\n");
								}
							}
						}
						else
						{
							printf("Error, no hay aviones cargados\n");
						}
						break;

					case 4:
						//verifico que la opcion 1 se haya ingresado
						if(flag==1)
						{
							//llamo funcion ordenar
							//verifico que la funcion ordenar devuelva 0
							//imprimo
							if(sortAvionesPorAerolineaYCapacidad(avionList, len)==1)
							{
								printAviones(avionList, len, aerolineaList, lenAerolinea, tipoList, lenTipo, pilotoList, lenPiloto);
							}
						}
						else
						{
							printf("\nError, No hay aviones cargados\n");
						}

						break;

					case 5:
						printAerolineas(aerolineaList, lenAerolinea);
						break;

					case 6:
						printTipos(tipoList, lenTipo);
						break;

					case 7:
						printDestinos(destinoList, lenDestino);
						break;

					case 8:
						lugarLibre = findEmptyPositionVuelo(vueloList, lenVuelo);
						addVuelos(&vueloList[lugarLibre], destinoList,lenVuelo, lenDestino);
						flagVuelo = 1;
						break;

					case 9:
						if(flagVuelo == 1)
						{
							printVuelos(vueloList, lenVuelo);
						}
						else
						{
							printf("No hay vuelos cargados");
						}
						break;

					case 10:
						if (utn_getNumeroInt(&optionInformes, "\nBienvenido \n1)Listar avion por aerolinea elegida:\n2)Listar avion por tipo elegido:\n3)Promedio de Jets:\n4)Aerolinea con menor cantidad de aviones:\n", "\nError opcion Invalida",  1, 4, 5)==0)
						{
							int idIngresado;
							switch(optionInformes)
							{
								case 1:
									printAvionSegunAerolinea(aerolineaList, lenAerolinea, avionList, len, tipoList, lenTipo, pilotoList, lenPiloto, idIngresado);
									break;
								case 2:
									printAvionSegunTipo(tipoList, lenTipo, aerolineaList, lenAerolinea, avionList, len, pilotoList, lenPiloto, idIngresado);
									break;
								case 3:
									promedioAvionJet(avionList, len, tipoList, lenTipo);
									break;
								case 4:
									printAerolineaMenorCantidadAviones(avionList, len, aerolineaList, lenAerolinea);
									break;
							}


						}
						break;
					case 11:
						printf("Saliendo");
					break;
				}
			}
	}while (option <=10);
}

