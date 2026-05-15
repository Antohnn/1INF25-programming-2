//
// Created by ANTONIO on 11/05/2026.
//
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "Cliente.h"
#include "Funciones.h"
#include "Plato.h"

using namespace std;

#include "Restaurante.h"

#define TAM_LINEA 160

Restaurante::Restaurante() {
    clientes=nullptr;
    cantidadClientes=0;
    capacidadClientes=0;
    platos=nullptr;
    cantidadPlatos=0;
    capacidadPlatos=0;
}
Restaurante::~Restaurante() {
    delete[] clientes;
    delete[] platos;
}


void Restaurante::incrementarClientes() {
    capacidadClientes+=5;
    if (clientes==nullptr) {
        clientes=new Cliente[capacidadClientes];
    }else {
        Cliente *aux=new Cliente[capacidadClientes];
        for (int i=0;i<cantidadClientes;i++) {
            aux[i]=clientes[i];
        }
        delete[] clientes;
        clientes=aux;
    }
}
void Restaurante::incrementarPlatos() {
    capacidadPlatos+=5;
    if (platos==nullptr) {
        platos=new Plato[capacidadPlatos];
    }else {
        Plato *aux=new Plato[capacidadPlatos];
        for (int i=0;i<cantidadPlatos;i++) {
            aux[i]=platos[i];
        }
        delete[] platos;
        platos=aux;
    }
}
Restaurante& Restaurante::operator<(const char *nombArch) {
    ifstream arch;
    abrirIn(arch,nombArch);

    Cliente cliente;

    while (arch>>cliente) {
        if (cantidadClientes==capacidadClientes) {
            incrementarClientes();
        }
        clientes[cantidadClientes]=cliente;
        cantidadClientes++;
    }
    return *this;
}
Restaurante& Restaurante::operator<=(const char*nombArch) {
    ifstream arch;
    abrirIn(arch,nombArch);
    Plato plato;

    while (arch>>plato) {
        if (cantidadPlatos==capacidadPlatos) {
            incrementarPlatos();
        }
        platos[cantidadPlatos]=plato;
        cantidadPlatos++;
    }
    return *this;
}
Restaurante& Restaurante::operator<<=(const char*nombArch) {
    ifstream arch;
    abrirIn(arch,nombArch);
    int numPedido,dniCliente;
    char c;
    while (arch>>numPedido) {
        arch.get();
        arch>>dniCliente>>c;
        leerPedidos(arch,numPedido,dniCliente);
    }

    return *this;
}
void Restaurante::leerPedidos(ifstream &arch,int numPedido,int dniCliente) {
    int idCliente,idPlato;
    char *codPlato,c;
    int cantPlatoPedido;
    while (true) {
        codPlato=leerCadenaExacta(arch,',');
        arch>>cantPlatoPedido;
        if (arch.peek()==',') arch.get();
        idCliente=buscarClientePorDni(dniCliente);
        if (idCliente!=-1) {
            idPlato=buscarPlatoPorCod(codPlato);
            if (idPlato!=-1) {
                actualizarDatos(idCliente,idPlato,cantPlatoPedido);
            }
        }
        if (arch.peek()=='\n')break;
    }
}
void Restaurante::actualizarDatos(int idCliente,int idPlato,int cantPlatoPedido) {
    int cantidadAtendida=platos[idPlato].atenderPedido(cantPlatoPedido);
    double montoTotal=platos[idPlato].getPrecio()*cantPlatoPedido;
    double descPlato=platos[idPlato].getDescuento();
    double descCliente=clientes[idCliente].getDescuento();

    if (cantidadAtendida>0) {
        double totalBrutoPlato=platos[idPlato].getPrecio()*cantidadAtendida;
        double totalNeto=totalBrutoPlato*(1-(descPlato)/100.0)*(1-(descCliente/100.0));

        platos[idPlato].sumarTotalBruto(totalBrutoPlato);
        platos[idPlato].sumarTotalNeto(totalNeto);
        clientes[idCliente].agregarMonto(totalNeto);
    }
    platos[idPlato].sumarTotalEsperado(montoTotal);

}

int Restaurante::   buscarClientePorDni(int dniCliente) const {
    for (int i=0;i<cantidadClientes;i++) {
        if (clientes[i].getDni()==dniCliente) {
            return i;
        }
    }
    return -1;
}
int Restaurante::buscarPlatoPorCod(char *codPlato) const {
    for (int i=0;i<cantidadPlatos;i++) {
        if (strcmp(codPlato,platos[i].getCodigo())==0) {
            return i;
        }
    }
    return -1;
}
Restaurante& Restaurante::operator>>(const char *nombArch) {
    ofstream arch;
    abrirOut(arch,nombArch);
    imprimirHeaderPlatos(arch);
    for (int i=0;i<cantidadPlatos;i++) {
        arch<<platos[i];
    }
    imprimirHeaderCliente(arch);
    for (int i=0;i<cantidadClientes;i++) {
        arch<<clientes[i];
    }
    imprimirCaracter(arch,TAM_LINEA,'=');
    return *this;
}
void Restaurante::imprimirHeaderPlatos(ofstream &arch) {
    arch<<setw(80)<<"RESTAURANTE 1INF25"<<endl;
    arch<<setw(60)<<"VENTAS DEL DIA"<<endl;
    imprimirCaracter(arch,TAM_LINEA,'=');
    arch<<setw(60)<<"RELACION DE PLATOS VENDIDOS"<<endl;
    imprimirCaracter(arch,TAM_LINEA,'-');
}
void Restaurante::imprimirHeaderCliente(ofstream &arch) {
    imprimirCaracter(arch,TAM_LINEA,'=');
    arch<<"RELACION DE CLIENTES VENDIDOS"<<endl;
    imprimirCaracter(arch,TAM_LINEA,'-');
}
void Restaurante::imprimirCaracter(ofstream &arch,int n,char c) {
    for (int i=0;i<n;i++) {
        arch.put(c);
    }
    arch<<endl;
}
//aux
void abrirIn(ifstream &arch,const char *nombArch) {
    arch.open(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR AL ABRIR "<<nombArch<<endl;
    }
}
void abrirOut(ofstream &arch,const char *nombArch) {
    arch.open(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR AL ABRIR "<<nombArch<<endl;
    }
}
