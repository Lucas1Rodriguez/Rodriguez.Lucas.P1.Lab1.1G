#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "avion.h"
#include "aerolinea.h"
#include "tipo.h"
#include "destino.h"
#include "utn_biblioteca.h"


void menuAvion(avion avionList[], int len, aerolinea aerolineaList[], int lenAerolinea, tipo tipoList[], int lenTipo, destino destinoList[], int lenDestino)
	{
		int option;
		int lugarLibre;
		int flag;
		do{
			if (utn_getNumeroInt(&option, "\nBienvenido \n1)Alta Avion:\n2)Modificar Avion:\n3)Baja Avion:\n4)Listar Aviones:\n5)Listar Aerolineas\n6)Listar Destinos\n7)Alta Vuelo\n8)Listar Vuelo\n9)Salir\n", "\nError opcion Invalida",  1, 9, 5)==0)
				{
				switch (option)
					{
						case 1:
							//Busco lugar libre
							lugarLibre = findEmptyPosition(avionList, len);
							//Pido y cargo los datos ingresados
							addAviones(&avionList[lugarLibre], len, avionList[lugarLibre].id, avionList[lugarLibre].idAerolinea, avionList[lugarLibre].idTipo, avionList[lugarLibre].capacidad);
							flag=1;
							break;

						case 2:
							//verifico que se haya cumplido la opcion 1
							if(flag==1)
							{
								int idIngresado;
								int indexAModif;
								printAviones(avionList, len, aerolineaList, lenAerolinea, tipoList, lenTipo);
								//pido que ingrese un numero a buscar
								//verifico que exista
								//llamo a la funcion modificar y imprimo
								if (utn_getNumeroInt(&idIngresado, "\nIngrese ID\n", "Error", 1, 999, 5) ==0)
								{
									indexAModif = findAvionById(avionList,len,idIngresado);
									if(indexAModif >=0)
									{
										modifyAvion(&avionList[indexAModif]);
										printAvion(avionList[indexAModif], aerolineaList, lenAerolinea, tipoList, lenTipo);
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
								int idingresado;
								int idDarBaja;

								printAviones(avionList, len, aerolineaList, lenAerolinea, tipoList, lenTipo);
								//pido que ingrese un numero a buscar
								//verifico que exista
								//llamo a la funcion eliminar y imprimo
								if (utn_getNumeroInt(&idingresado, "\nIngrese ID a eliminar\n", "Error", 1, 300, 5) ==0)
								{
									idDarBaja = findAvionById(avionList,len,idingresado);
									if(idDarBaja>=0)
									{
										removeAvion(avionList,len,idingresado);
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
								if(sortAvionesPorAerolineaYCapacidad(avionList, len)==0)
								{
									printAviones(avionList, len, aerolineaList, lenAerolinea, tipoList, lenTipo);
								}
							}
							else
							{
								printf("\nError, No hay aviones cargados\n");
							}

						break;

						case 5:
							for(int index=0;index< len ;index++)
							{
								printAerolineas(aerolineaList, lenAerolinea);
							}
						break;

						case 6:
							for(int index=0;index< len ;index++)
							{
								printTipos(tipoList, lenTipo);
							}

						break;

						case 7:
							for(int index=0;index< len ;index++)
							{
								printDestinos(destinoList, lenDestino);
							}
						break;

						case 8:
							printf("Entre al case 8");
						break;

						case 9:
							printf("Saliendo");
						break;
					}
				}
		}while (option <=8);
	}
