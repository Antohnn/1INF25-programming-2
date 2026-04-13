//
// Created by ANTONIO on 8/04/2026.
//
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

#include "Funciones.h"
#include "Estructuras.h"

using namespace std;

//79464412,PORTUGAL RAFFO ALEXANDER,3902394
//16552775,YALLICO PAREDES LOURDES CARMELA,960176666

bool operator>>(ifstream &archCliente,Cliente &cliente) {
    archCliente>>cliente.dni;
    if (archCliente.eof()) return false;
    archCliente.ignore();
    archCliente.getline(cliente.nombre,60,',');
    archCliente>>cliente.telefono;

    cliente.cantidadProductosEntrgados=0;
    cliente.montoTotal=0;
    return true;
}

//BIT-434,Campana Extractora modelo Glass,375.09,10
//SSE-115,Refrigeradora  CoolStyle 311N Steel,3243.58,3

bool operator>>(ifstream &archProducto,Producto &producto) {
    archProducto.getline(producto.codigo,8,',');
    if (archProducto.eof()) return false;
    archProducto.getline(producto.descripcion,60,',');
    archProducto>>producto.precio;
    archProducto.ignore();
    archProducto>>producto.stock;
    archProducto.ignore();

    producto.cantidadClientesNoServidos=0;
    producto.cantidadClientesServidos=0;
    return true;
}

//JXD-139,50375303
//CRU-009,50375303

bool operator>>(ifstream &archPedido,Pedido &pedido) {
    archPedido.getline(pedido.CodigoProducto,8,',');
    if (archPedido.eof()) return false;
    archPedido>>pedido.dniCliente;
    archPedido.ignore();

    return true;
}

//Agregacion

void operator+=(Cliente *arrClientes,Pedido &pedido) {
    int cantProd;

    for (int i=0;arrClientes[i].dni!=0;i++) {
        if (arrClientes[i].dni==pedido.dniCliente) {
            cantProd=arrClientes[i].cantidadProductosEntrgados;
            strcpy(arrClientes[i].productosEntregados[cantProd].codigo,pedido.CodigoProducto);
            arrClientes[i].productosEntregados[cantProd].precio=pedido.precioProducto;
            arrClientes[i].montoTotal+=pedido.precioProducto;
            arrClientes[i].cantidadProductosEntrgados++;
            break;
        }
    }
}

bool operator+=(Producto *arrProducto,Pedido &pedido) {
    int cantClietServ,cantClientNoServ;

    for (int i=0;strcmp(arrProducto[i].codigo,"XXXXXXX") != 0;i++) {
        // // --- TRAMPA DE IMPRESIÓN ---
        // cout << "Revisando indice i = " << i << endl;
        // cout << "1. Codigo en arreglo: " << arrProducto[i].codigo << endl;
        // // Si explota aquí, el problema es el arreglo o que nos salimos del límite.
        // cout << "2. Codigo en pedido: " << pedido.CodigoProducto << endl;
        // // Si explota aquí, el problema es el pedido.
        // // ---------------------------
        if (strcmp(arrProducto[i].codigo,pedido.CodigoProducto)==0) {
            pedido.precioProducto=arrProducto[i].precio;
            if (arrProducto[i].stock>0) {
                cantClietServ=arrProducto[i].cantidadClientesServidos;
                arrProducto[i].clientesServidos[cantClietServ]=pedido.dniCliente;
                arrProducto[i].stock--;
                arrProducto[i].cantidadClientesServidos++;
                return true;
            }else {
                cantClientNoServ=arrProducto[i].cantidadClientesNoServidos;
                arrProducto[i].clientesNoServidos[cantClientNoServ]=pedido.dniCliente;
                arrProducto[i].cantidadClientesNoServidos++;
                return false;
            }
        }
    }
    return false;
}

void operator<<(ofstream &archRepCliente,Cliente &cliente) {
    archRepCliente<<fixed<<setprecision(2);
    archRepCliente<<cliente.dni<<left<<setw(60)<<cliente.nombre<<right<<setw(10)<<cliente.telefono
    <<setw(15)<<cliente.montoTotal;
    for (int i=0;i<cliente.cantidadProductosEntrgados;i++) {
        archRepCliente<<left<<setw(15)<<cliente.productosEntregados[i].codigo<<right;
    }
    archRepCliente<<endl;
}

void operator<<(ofstream &archRepProd,Producto &producto) {
    archRepProd<<fixed<<setprecision(2);
    archRepProd<<left<<setw(15)<<producto.codigo<<setw(60)<<producto.descripcion<<right<<setw(10)
    <<producto.precio<<setw(15)<<producto.stock<<endl;
    archRepProd<<"Clientes atendidos: ";
    for (int i=0;i<producto.cantidadClientesServidos;i++) {
        archRepProd<<producto.clientesServidos[i]<<setw(10);
    }
    archRepProd<<endl;
    archRepProd<<"Clientes no atendidos: ";
    for (int i=0;i<producto.cantidadClientesNoServidos;i++) {
        archRepProd<<producto.clientesNoServidos[i]<<setw(10);
    }
    archRepProd<<endl;
}







//Auxiliares
void abrirIn(ifstream &archEntrada,const char *nombArch) {
    archEntrada.open(nombArch,ios::in);
    if (not archEntrada.is_open()) {
        cout<<"Error al abrir "<<nombArch<<endl;
        exit(1);
    }
}
void abrirOut(ofstream &archReporte,const char *nombArch) {
    archReporte.open(nombArch,ios::out);
    if (not archReporte.is_open()) {
        cout<<"Error al abrir "<<nombArch<<endl;
        exit(1);
    }
}
