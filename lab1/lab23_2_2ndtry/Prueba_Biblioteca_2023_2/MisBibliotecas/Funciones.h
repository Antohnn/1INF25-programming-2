//
// Created by ANTONIO on 8/04/2026.
//

#ifndef FUENTES_BIBLIOTECA_2023_2_FUNCIONES_H
#define FUENTES_BIBLIOTECA_2023_2_FUNCIONES_H
#include "Estructuras.h"

using namespace std;

//Auxiliares
void abrirIn(ifstream &archEntrada,const char *nombArch);
void abrirOut(ofstream &archReporte,const char *nombArch);

bool operator>>(ifstream &archCliente,Cliente &cliente);
bool operator>>(ifstream &archProducto,Producto &producto);
bool operator>>(ifstream &archPedido,Pedido &pedido);
void operator+=(Cliente *arrClientes,Pedido &pedido) ;
bool operator+=(Producto *arrProducto,Pedido &pedido) ;

void operator<<(ofstream &archReporte,Cliente &cliente);
void operator<<(ofstream &archRepProd,Producto &producto);
#endif //FUENTES_BIBLIOTECA_2023_2_FUNCIONES_H
