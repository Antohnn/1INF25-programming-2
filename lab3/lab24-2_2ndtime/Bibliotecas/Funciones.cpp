//
// Created by ANTONIO on 24/04/2026.
//
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#include "Funciones.h"
#include "enums.h"

void cargarInventario(const char *nombArch,void *&inventario) {
    ifstream arch;
    abrirIn(arch,nombArch);
    void **regInventario=nullptr;
    int num=0,capacidad=0;
    void *insumo;
    while (leerInventario(arch,insumo)) {
        if (num==capacidad) {
            aumentarRegistro(regInventario,num,capacidad);
        }
        regInventario[num++]=insumo;
    }
    if (regInventario==nullptr) regInventario=new void*[1]{};
    else regInventario[num]=nullptr;
    inventario=regInventario;
}
bool leerInventario(ifstream &arch,void *&insumo) {
    char *codInsumo,*nombInsumo,*unidadMedida,c;
    double cantidadDis;

    codInsumo=leerCadena(arch,',');
    if (arch.eof())return false;
    nombInsumo=leerCadena(arch,',');
    arch>>cantidadDis>>c;
    unidadMedida=leerCadena(arch,'\n');

    void **reg=new void*[invNumCampos]{};
    reg[invCodigo]=codInsumo;
    reg[invNombre]=nombInsumo;
    reg[invCantDisponible]=new double(cantidadDis);
    reg[invCantRequerida]=new double(0.0);
    reg[invUnidadMedida]=unidadMedida;

    insumo=reg;
    return true;
}
//aux
void abrirIn(ifstream &arch,const char *nombArch) {
    arch.open(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR AL ABRIR "<<nombArch<<endl;
        exit(1);
    }
}
void abrirOut(ofstream &arch,const char *nombArch) {
    arch.open(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR AL ABRIR "<<nombArch<<endl;
        exit(1);
    }
}
char *leerCadena(ifstream &arch,char delim) {
    char aux[300],*cad;
    arch.getline(aux,300,delim);
    if (arch.eof())return nullptr;
    cad=new char[strlen(aux)+1];
    strcpy(cad,aux);
    return cad;
}
void aumentarRegistro(void **&regInventario,int num,int &capacidad) {
    capacidad+=5;
    if (regInventario==nullptr) {
        regInventario=new void*[capacidad+1]{};
    }else {
        void **aux=new void*[capacidad+1]{};
        for (int i=0;i<num;i++) {
            aux[i]=regInventario[i];
        }
        delete [] regInventario;
        regInventario=aux;
    }
}