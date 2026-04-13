//
// Created by ANTONIO on 9/04/2026.
//

#ifndef FUENTES_BIBLIOTECA_2024_2_SOBRECARGA_H
#define FUENTES_BIBLIOTECA_2024_2_SOBRECARGA_H
#include "Estructuras.h"

using namespace std;
//Lectura
void operator>>(ifstream &archPlato,Plato &plato);
void operator>>(ifstream &archRepartidor,Repartidor &repartidor);
void operator>>(ifstream &archPedido,Pedido &pedido);
//Operaciones
bool operator<=(Pedido &pedido,Plato *arrPlato) ;
void operator<=(Repartidor *arrRepartidor,Pedido &pedido);
void operator!(OrdenDeCompra &orden);
void operator!(Repartidor &repartidor);
//Impresion
void operator<<(ofstream &archRepPlato,const Plato &plato);
void operator<<(ofstream &archRepRepart,const Repartidor &repartidor) ;
//Aux
void abrirIn(ifstream &archEntrada,const char * nombArch);
void abrirOut(ofstream &archReporte,const char * nombArch);

#endif //FUENTES_BIBLIOTECA_2024_2_SOBRECARGA_H
