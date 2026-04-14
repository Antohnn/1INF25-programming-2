//
// Created by ANTONIO on 14/04/2026.
//
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

#include "MetodoExactoDeMemoria.h"
#define NO_ENCONTRADO -1
//lectura de libros
void lecturaDeLibros(const char *nombArch,char ***&libros,int **&stock) {
    ifstream archLib(nombArch,ios::in);
    if (not archLib.is_open()) {
        cout<<"ERROR AL ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    //1. declarar los buffers
    char **buffLib[300];
    int *buffStock[300];
    //2. leemos el archivos
    int n=0;
    while (true) {
        buffLib[n]=leerLibros(archLib);
        if (archLib.eof())break;
        buffStock[n]=leerStock(archLib);
        n++;
    }
    //3. cargar arreglos
    libros=new char**[n+1];
    stock=new int*[n+1];
    for (int i=0;i<n;i++) {
        libros[i]=buffLib[i];
        stock[i]=buffStock[i];
    }
    libros[n]=nullptr;
    stock[n]=nullptr;

}
char **leerLibros(ifstream &archLib) {
    char **tripleta,*codLibro;

    codLibro=leerCadenaExacta(archLib,',');
    if (archLib.eof())return nullptr;
    tripleta=new char*[3];

    tripleta[0]=codLibro;
    tripleta[1]=leerCadenaExacta(archLib,',');
    tripleta[2]=leerCadenaExacta(archLib,',');
    return tripleta;
}
char *leerCadenaExacta(ifstream &arch,char delim) {
    char buffer[300],*cad;
    arch.getline(buffer,300,delim);
    if (arch.eof())return nullptr;
    cad= new char [strlen(buffer)+1];
    strcpy(cad,buffer);
    return cad;
}
int *leerStock(ifstream &archLib) {
    int *dupla,stock;
    double precio;
    char c;

    archLib>>stock;
    archLib>>c>>precio;
    archLib.get();

    dupla=new int[2];
    dupla[0]=stock;
    dupla[1]=0;
    return dupla;
}
//prueba reporte libros
void pruebaDeLecturaDeLibros(const char *nombArch,char ***libros,int **stock) {
    ofstream archRep(nombArch,ios::out);
    if (not archRep.is_open()) {
        cout<<"ERROR AL ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    archRep<<fixed<<setprecision(2);
    char **auxLib;
    int *auxStock;

    for (int i=0;libros[i]!=nullptr;i++) {
        auxLib=libros[i];
        auxStock=stock[i];

        archRep<<left<<setw(10)<<auxLib[0]<<setw(60)<<auxLib[1]<<setw(60)<<auxLib[2]<<right<<setw(8)
        <<auxStock[0]<<setw(8)<<auxStock[1]<<endl;
    }
}
//lectura pedidos
void atencionDePedidos(const char *nombArch,char ***libros,int **stock,int **&pedidosClientes,char ***&pedidosLibros,
    bool **&pedidosAtendidos) {
    ifstream archPed(nombArch,ios::in);
    if (not archPed.is_open()) {
        cout<<"ERROR AL ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    //1. declarar buffers
    int *buffPedCli[300]{};
    char **buffPedLib[300]{};
    bool *buffPedAten[300]{};
    //2. lectura del archivo
    int cantCli=0,numPed,dni,idCliente=NO_ENCONTRADO,cantLibEnPed[300]{},cantPed=0;
    while (true) {
        archPed>>numPed;
        if (archPed.eof())break;
        archPed.get();
        archPed>>dni;
        if (cantCli>0) idCliente=buscarCliente(buffPedCli,dni);
        if (idCliente==NO_ENCONTRADO) {
            agregarCliente(buffPedCli[cantCli],dni,idCliente,cantCli);
        }
        agregarPedido(buffPedCli[idCliente],numPed);
        leerPedidos(archPed,libros,stock,buffPedLib[numPed],buffPedAten[numPed],cantLibEnPed[numPed]);
        cantPed++;
    }
    //3. carga de arreglos
}
int buscarCliente(int **buffPedCli,int dni) {
    int *auxDni;
    for (int i=0;buffPedCli[i]!=nullptr;i++) {
        auxDni=buffPedCli[i];
        if (auxDni[0]==dni) {
            return i;
        }
    }
    return NO_ENCONTRADO;
}
void agregarCliente(int *&buffPedCli,int dni,int &idCliente,int &cantCli) {
    buffPedCli= new int[20];
    buffPedCli[0]=dni;
    buffPedCli[1]=0;
    idCliente=cantCli;
    cantCli++;
}
void agregarPedido(int *buffPedCli,int numPed) {
    buffPedCli[2+buffPedCli[1]]=numPed;
    buffPedCli[1]++;
}
void leerPedidos(ifstream &archPed,char ***libros,int **stock,char **&buffPedLib,bool *&buffPedAten,int &cantLibEnPed) {
    int idLibro;
    char codLib[8];
    buffPedLib=new char *[20];
    buffPedAten=new bool[20];

    while (true) {
        archPed>>codLib;
        copiarCadena(buffPedLib[cantLibEnPed],codLib);
        idLibro=buscarLibro(libros,codLib);
        modificarPedidoAtendido(stock[idLibro],buffPedAten[cantLibEnPed]);
        cantLibEnPed++;
        if (archPed.get()=='\n')break;
    }
}
void copiarCadena(char *destino,const char *origen) {
    char *aux;
    aux=new char[strlen(origen)+1];
    strcpy(destino,aux);
    delete [] aux;
}
int buscarLibro(char ***libros,char *codLib) {
    char **auxLib;
    for (int i=0;libros[i]!=nullptr;i++) {
        auxLib=libros[i];
        if (strcmp(auxLib[0],codLib)==0) {
            return i;
        }
    }
    return NO_ENCONTRADO;
}
void modificarPedidoAtendido(int *stock,bool &seAtendio) {
    if (stock[0]>0) {
        seAtendio=true;
        stock[0]--;
    }else {
        seAtendio=false;
        stock[1]++;
    }
}
//reporte Pedidos
void reporteDeEntregaDePedidos(const char *nombArch,int **pedidosClientes,char ***pedidosLibros,bool **pedidosAtendidos) {

}
