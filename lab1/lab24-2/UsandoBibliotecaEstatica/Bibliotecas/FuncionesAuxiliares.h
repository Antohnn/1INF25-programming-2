//
// Created by ANTONIO on 9/04/2026.
//

#ifndef USANDOBIBLIOTECAESTATICA_FUNCIONESAUXILIARES_H
#define USANDOBIBLIOTECAESTATICA_FUNCIONESAUXILIARES_H
#include "Estructuras.h"

void cargarPlatos(ifstream &archPlato,Plato *arrPlato) ;
void cargarRepartidores(ifstream &archRepar,Repartidor *arrRepartidor);
void cargarPedidos(ifstream &archPedido,Plato *arrPlato,Repartidor *arrRepartidor) ;

void actualizarOrdenes(Repartidor *arrRepartidor);

void imprimirPlatos(ofstream &archRepPlato,const Plato *arrPlato);
void imprimirRepartidores(ofstream &archRepRepart,const Repartidor *arrRepartidor) ;

#endif //USANDOBIBLIOTECAESTATICA_FUNCIONESAUXILIARES_H
