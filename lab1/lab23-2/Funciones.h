//
// Created by ANTONIO on 1/04/2026.
//

#ifndef LAB23_2_FUNCIONES_H
#define LAB23_2_FUNCIONES_H

#include <iostream>
#include "Estructuras.h"

void abrirArch(ifstream &archEntrada,const char *nombArch);
void abrirOut(ofstream &archReporte,const char* nombArch);

bool operator>>(ifstream &archCliente,Cliente &cliente);
bool operator>>(ifstream &archProd,Producto &producto);
bool operator>>(ifstream &archPedido,Pedido &pedido);
//asignacion
void operator+=(Cliente *arrClientes,Pedido &pedido);
bool operator +=(Producto *arrProductos,Pedido &pedido);

void operator<<(ofstream &archRepCliente,Cliente &cliente) ;
void operator<<(ofstream &archRepProducto,Producto &producto);
#endif //LAB23_2_FUNCIONES_H
