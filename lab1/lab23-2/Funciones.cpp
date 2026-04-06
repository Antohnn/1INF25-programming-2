//
// Created by ANTONIO on 1/04/2026.
//
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Funciones.h"
#include "Estructuras.h"

void abrirArch(ifstream &archEntrada,const char *nombArch) {
    archEntrada.open(nombArch,ios::in);
    if (not archEntrada.is_open()) {
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
}
void abrirOut(ofstream &archReporte,const char* nombArch) {
    archReporte.open(nombArch,ios::out);
    if (not archReporte.is_open()) {
        cout<<"ERROR al abrir el archivo"<<endl;
    }
}

bool operator>>(ifstream &archCliente,Cliente &cliente) {
    char c;

    archCliente>>cliente.dni>>c;
    if (archCliente.eof()) return false;
    archCliente.getline(cliente.nombre,60,',');
    archCliente>>cliente.telefono;
    cliente.cantidadProductosEntrgados=0;
    cliente.montoTotal=0;
    return true;
}
bool operator>>(ifstream &archProd,Producto &producto) {
    char c;

    archProd.getline(producto.codigo,8,',');
    if (archProd.eof()) return false;
    archProd.getline(producto.descripcion,60,',');
    archProd>>producto.precio>>c>>producto.stock;
    archProd.get();
    producto.cantidadClientesNoServidos=0;
    producto.cantidadClientesServidos=0;

    return true;
}
bool operator>>(ifstream &archPedido,Pedido &pedido) {

    archPedido.getline(pedido.CodigoProducto,8,',');
    if (archPedido.eof()) return false;
    archPedido>>pedido.dniCliente;
    archPedido.get();

    return true;
}
//Asignacion
void operator+=(Cliente *arrClientes,Pedido &pedido) {
    int cantPedido;
    for (int i=0;arrClientes[i].dni!=0;i++) {
        if (arrClientes[i].dni==pedido.dniCliente) {
            cantPedido=arrClientes[i].cantidadProductosEntrgados;
            strcpy(arrClientes[i].productosEntregados[cantPedido].codigo,pedido.CodigoProducto);
            arrClientes[i].productosEntregados[cantPedido].precio=pedido.precioProducto;
            arrClientes[i].montoTotal+=pedido.precioProducto;
            arrClientes[i].cantidadProductosEntrgados++;
            break;
        }
    }
}
bool operator+=(Producto *arrProductos,Pedido &pedido) {
    int cantServido,cantNoServido;
    for (int i=0;strcmp(arrProductos[i].codigo,"XXXXXXX")!=0;i++) {
        if (strcmp(arrProductos[i].codigo,pedido.CodigoProducto)==0) {
            pedido.precioProducto=arrProductos[i].precio;
            if (arrProductos[i].stock>0) {
                cantServido=arrProductos[i].cantidadClientesServidos;
                arrProductos[i].clientesServidos[cantServido]=pedido.dniCliente;
                arrProductos[i].cantidadClientesServidos++;
                arrProductos[i].stock--;
                return true;
            }else {
                cantNoServido=arrProductos[i].cantidadClientesNoServidos;
                arrProductos[i].clientesNoServidos[cantNoServido]=pedido.dniCliente;
                arrProductos[i].cantidadClientesNoServidos++;
                return false;
            }
        }
    }
    return false;
}

void operator<<(ofstream &archRepCliente,Cliente &cliente) {
    archRepCliente<<fixed<<setprecision(2);
    archRepCliente<<cliente.dni<<setw(60)<<cliente.nombre<<setw(15)<<cliente.telefono<<setw(15)<<cliente.montoTotal;
    archRepCliente<<"Productos entregados: ";
    if (cliente.cantidadProductosEntrgados>0) {
        for (int i=0;i<cliente.cantidadProductosEntrgados;i++) {
            archRepCliente<<cliente.productosEntregados[i].codigo;
        }
        archRepCliente<<endl;
    }else archRepCliente<<"NO SE LE ENTRAGRON PRODUCTOS"<<endl;
}

void operator<<(ofstream &archRepProducto,Producto &producto) {
    archRepProducto<<fixed<<setprecision(2);
    archRepProducto<<producto.codigo<<setw(60)<<producto.descripcion<<setw(15)<<producto.precio<<setw(15)
    <<producto.stock<<endl;
    archRepProducto<<"Clientes atendidos: ";
    if (producto.cantidadClientesServidos>0) {
        for (int i=0;i<producto.cantidadClientesServidos;i++) {
            archRepProducto<<setw(2)<<producto.clientesServidos[i];
        }
        archRepProducto<<endl;
    }else archRepProducto<<"NO SE ATENDIERON PEDIDOS"<<endl;
    if (producto.cantidadClientesNoServidos>0) {
        for (int i=0;i<producto.cantidadClientesNoServidos;i++) {
            archRepProducto<<setw(2)<<producto.clientesNoServidos[i];
        }
        archRepProducto<<endl;
    }else archRepProducto<<"NO HAY CLIENTES SIN ATENDER"<<endl;
}

