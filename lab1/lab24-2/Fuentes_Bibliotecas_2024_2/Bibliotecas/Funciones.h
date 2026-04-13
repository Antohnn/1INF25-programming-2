//
// Created by ANTONIO on 9/04/2026.
//

#ifndef FUENTES_BIBLIOTECAS_2024_2_FUNCIONES_H
#define FUENTES_BIBLIOTECAS_2024_2_FUNCIONES_H
#include "Estructuras.h"
#include <fstream>

using namespace std;

void operator>>(ifstream &archPlato,Plato &plato);
void operator>>(ifstream &archRepartidor,Repartidor &repartidor) ;
void operator>>(ifstream &archPedido,Pedido &pedido);

bool operator<=(Pedido &pedido,Plato *arrPlatos);
void operator<=(Repartidor *arrRepartidores,Pedido &pedido);

void operator!(OrdenDeCompra &ordenDeCompra);
void operator!(Repartidor &repartidor) ;

void operator<<(ofstream &archRepPlato,const Plato &plato);
void operator<<(ofstream &archRepRepar,const Repartidor &repartidor);

void abrirIn(ifstream &archEntrada,const char *nombArch);
void abrirOut(ofstream &archReporte,const char *nombArch);
#endif //FUENTES_BIBLIOTECAS_2024_2_FUNCIONES_H
