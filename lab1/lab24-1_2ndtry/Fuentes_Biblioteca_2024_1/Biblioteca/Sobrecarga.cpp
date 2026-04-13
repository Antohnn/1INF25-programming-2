//
// Created by ANTONIO on 9/04/2026.
//
#include <iostream>
#include <cstring>
#include <fstream>

#include "Estructuras.h"
#include "Sobrecarga.h"

#include <iomanip>

using namespace std;

//Lectura
bool operator>>(ifstream &archLibro,Libro &libro) {
    //archLibro>>libro;
    archLibro.getline(libro.codigo,8,',');
    if (archLibro.eof())return false;
    archLibro.getline(libro.tiltulo,80,',');
    archLibro.getline(libro.autor,60,',');
    archLibro>>libro.stock>>libro.precio;
    archLibro.get();

    return true;
}
bool operator>>(ifstream &archCliente,Cliente &cliente) {
    archCliente>>cliente.dni;
    if (archCliente.eof())return false;
    archCliente.get();
    archCliente.getline(cliente.nombre,60);

    cliente.cantDeLibros=0;
    cliente.pagoTotal=0;
    return true;
}
//Operaciones
bool operator>>(LibroSolicitado &libroSol,Libro *arrLibros) {
    for (int i=0;strcmp(arrLibros[i].codigo,"FIN")!=0;i++) {
        if (strcmp(arrLibros[i].codigo,libroSol.codigoDelLibro)==0) {
            if (arrLibros[i].stock>0) {
                libroSol.precio=arrLibros[i].precio;
                libroSol.atendido=true;
                arrLibros[i].stock--;
                return true;
            }
            libroSol.atendido=false;
            return false;
        }
    }
    return false;
}

bool operator<<(LibroSolicitado &libroSol,Cliente &cliente) {
    //cliente<<pedido
    int cantLibro;

    if (cliente.cantDeLibros<30) {
        cantLibro=cliente.cantDeLibros;
        cliente.librosSolicitados[cantLibro]=libroSol;
        cliente.cantDeLibros++;
        return true;
    }
    return false;
}

void operator ++(Cliente &cliente) {
    for (int i=0;i<cliente.cantDeLibros;i++) {
        if (cliente.librosSolicitados[i].atendido) {
            cliente.pagoTotal+=cliente.librosSolicitados[i].precio;
        }
    }
}

void operator<<(ofstream &archRepLibro,Libro &libro) {
    archRepLibro<<fixed<<setprecision(2);
    archRepLibro<<left<<setw(8)<<libro.codigo<<setw(80)<<libro.tiltulo<<setw(60)<<libro.autor<<right
    <<setw(15)<<libro.stock<<setw(15)<<libro.precio<<endl;
}

void operator<<(ofstream &archRepCliente,Cliente &cliente) {
    archRepCliente<<fixed<<setprecision(2);
    archRepCliente<<cliente.dni<<left<<setw(60)<<cliente.nombre<<right<<endl;
    archRepCliente<<"Libros Entregados: "<<endl;
    archRepCliente<<setw(20)<<"Pedido No:"<<setw(30)<<"Codigo"<<setw(30)<<"Precio"<<endl;
    for (int i=0;i<cliente.cantDeLibros;i++) {
        if (cliente.librosSolicitados[i].atendido) {
            archRepCliente<<cliente.librosSolicitados[i].numeroDePedido<<left<<setw(25)
        <<cliente.librosSolicitados[i].codigoDelLibro<<right<<setw(15)<<cliente.librosSolicitados[i].precio<<endl;
        }
    }
    archRepCliente<<"Libros no entregados por falta de stock: "<<endl;
    for (int i=0;i<cliente.cantDeLibros;i++) {
        if (not cliente.librosSolicitados[i].atendido) {
            archRepCliente<<cliente.librosSolicitados[i].numeroDePedido<<left<<setw(25)
        <<cliente.librosSolicitados[i].codigoDelLibro<<right<<endl;
        }
    }
}



//aux
void abrirIn(ifstream &archEntrada,const char *nombArch) {
    archEntrada.open(nombArch,ios::in);
    if (not archEntrada.is_open()) {
        cout<<"ERROR AL ABRIR "<<nombArch<<endl;
        exit(1);
    }
}
void abrirOut(ofstream &archReporte,const char *nombArch) {
    archReporte.open(nombArch,ios::out);
    if (not archReporte.is_open()) {
        cout<<"ERROR AL ABRIR "<<nombArch<<endl;
        exit(1);
    }
}

