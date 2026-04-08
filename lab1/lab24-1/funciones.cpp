//
// Created by anton on 6/04/2026.
//
#include <iostream>
#include <fstream>
#include <iomanip>

#include "funciones.h"

#include <cstring>

#include "Estructuras.h"

using namespace std;

void abrirArch(ifstream &archEntrada, const char *archNombre) {
    archEntrada.open(archNombre,ios::in);
    if (not archEntrada.is_open()) {
        cout<<"ERROR AL ABRIR EL ARCHIVO "<<archNombre<<endl;
        exit(1);
    }
}

//Lectura

bool operator>>(ifstream &archLibro,Libro &libro) {
    char c;

    archLibro.getline(libro.codigo,8,',');
    if (archLibro.eof())return false;
    archLibro.getline(libro.tiltulo,80,',');
    archLibro.getline(libro.autor,60,',');
    archLibro>>libro.stock>>c>>libro.precio;
    archLibro.get();
    return true;
}
bool operator>>(ifstream &archCliente,Cliente &cliente) {
    archCliente>>cliente.dni;
    if (archCliente.eof())return false;
    archCliente.getline(cliente.nombre,60,'\n');
    cliente.cantDeLibros=0;
    cliente.pagoTotal=0;

    return true;
}
bool operator>>(LibroSolicitado &libroPedido,Libro *arrLibros) {
    for (int i=0;strcmp(arrLibros[i].codigo,"FIN")!=0;i++) {
        if (strcmp(arrLibros[i].codigo,libroPedido.codigoDelLibro)==0) {
            if (arrLibros[i].stock>0) {
                arrLibros[i].stock--;
                libroPedido.precio=arrLibros[i].precio;
                libroPedido.atendido=true;
                return true;
            }else {
                libroPedido.atendido=false;
                return false;
            }
        }
    }
    return false;
}

bool operator<<(LibroSolicitado &libroPedido,Cliente &cliente) {
    int cantLibros;
    cantLibros=cliente.cantDeLibros;
    if (cantLibros<30) {
        cliente.librosSolicitados[cantLibros].precio=libroPedido.precio;
        cliente.librosSolicitados[cantLibros].atendido=libroPedido.atendido;
        strcpy(cliente.librosSolicitados[cantLibros].codigoDelLibro,libroPedido.codigoDelLibro);
        cliente.cantDeLibros++;
        return true;
    }
    return false;
}

void operator++(Cliente &cliente) {
    for (int i=0;i<cliente.cantDeLibros;i++) {
        if (cliente.librosSolicitados[i].atendido) {
            cliente.pagoTotal+=cliente.librosSolicitados[i].precio;
        }
    }
}

void operator<<(ofstream &archRepLibro,Libro &libro) {
    archRepLibro<<left<<libro.codigo<<setw(80)<<libro.tiltulo<<setw(60)<<libro.autor
    <<right<<libro.stock<<setw(15)<<libro.precio<<endl;
}

void operator<<(ofstream &archRepCliente,Cliente &cliente) {
    archRepCliente<<cliente.dni<<left<<setw(15)<<cliente.nombre<<endl;
    for (int i=0;i<cliente.cantDeLibros;i++) {
        if (cliente.librosSolicitados[i].atendido) {
            archRepCliente<<cliente.librosSolicitados[i].numeroDePedido<<setw(10)
            <<cliente.librosSolicitados[i].codigoDelLibro<<setw(15)<<cliente.librosSolicitados[i].precio<<endl;
        }
    }
    for (int i=0;i<cliente.cantDeLibros;i++) {
        if (!cliente.librosSolicitados[i].atendido) {
            archRepCliente<<cliente.librosSolicitados[i].numeroDePedido<<setw(10)
            <<cliente.librosSolicitados[i].codigoDelLibro<<setw(15)<<endl;
        }
    }
}

