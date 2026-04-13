//
// Created by ANTONIO on 9/04/2026.
//
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#include "FuncionesAuxiliares.h"
#include "Estructuras.h"
#include "Funciones.h"

void cargarPlatos(ifstream &archPlato,Plato *arrPlato) {
    for (int i=0;i<150;i++) {
        archPlato>>arrPlato[i];
        if (archPlato.eof()) {
            strcpy(arrPlato[i].codigo,"FIN");
            break;
        }
    }
}

void cargarRepartidores(ifstream &archRepar,Repartidor *arrRepartidor) {
    for (int i=0;i<50;i++) {
        archRepar>>arrRepartidor[i];
        if (archRepar.eof()) {
            strcpy(arrRepartidor[i].codigo,"FIN");
            break;
        }
    }
}

void cargarPedidos(ifstream &archPedido,Plato *arrPlato,Repartidor *arrRepartidor) {
    Pedido pedido;
    while (true) {
        archPedido>>pedido;
        if (archPedido.eof()) break;
        pedido<=arrPlato;
        arrRepartidor<=pedido;
    }
}

void actualizarOrdenes(Repartidor *arrRepartidor) {
    for (int i=0;strcmp(arrRepartidor[i].codigo,"FIN")!=0;i++) {
        for (int j=0;j<arrRepartidor[i].cantidadDeOrdenes;j++) {
            !arrRepartidor[i].ordenesDeCompra[j];
        }
        !arrRepartidor[i];
    }
}

void imprimirPlatos(ofstream &archRepPlato,const Plato *arrPlato) {
    for (int i=0;strcmp(arrPlato[i].codigo,"FIN")!=0;i++) {
        archRepPlato<<arrPlato[i];
    }
}

void imprimirRepartidores(ofstream &archRepRepart,const Repartidor *arrRepartidor) {
    for (int i=0;strcmp(arrRepartidor[i].codigo,"FIN")!=0;i++) {
        archRepRepart<<arrRepartidor[i];
    }
}
