//
// Created by ANTONIO on 6/05/2026.
//
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "enums.h"

using namespace std;

#include "ListaconRegistros.h"

bool leeregistros(ifstream &arch,void *&dato) {
    char *codRepartidor,*nombRepartidor,*vehiRepartidor;

    codRepartidor=leerCadenaExacta(arch,',');
    if (arch.eof())return false;
    nombRepartidor=leerCadenaExacta(arch,',');
    vehiRepartidor=leerCadenaExacta(arch,'\n');

    void **reg=new void*[cantNumRepartidor];
    reg[codRepart]=codRepartidor;
    reg[nombRepart]=nombRepartidor;
    reg[vehiRepart]=vehiRepartidor;

    void **dupla=new void *[2];
    dupla[duplaDato]=reg;
    dupla[duplaArrDato]=nullptr;
    dato=dupla;
    return true;
}
bool leeordenes(ifstream &arch,void *&dato,void *&clave) {
    int dni,cantidad;
    char *codPlato,*codRepartidor,c;

    arch>>dni;
    if (arch.eof())return false;
    arch>>c>>cantidad>>c;
    codPlato=leerCadenaExacta(arch,',');
    codRepartidor=leerCadenaExacta(arch,'\n');

    void **reg=new void*[cantOrdenDat];
    reg[ordenDni]=new int(dni);
    reg[ordenCant]=new int(cantidad);
    reg[ordenPlato]=codPlato;

    clave=codRepartidor;
    dato=reg;
    return true;
}
bool compruebaregistro(void *nodoActual,void *clave) {
    void **datoActual=(void **)nodoActual;
    void **datoRepartidor=(void **)datoActual[duplaDato];

    char *codRepNodo=(char *)datoRepartidor[codRepart];
    char *codRep=(char *)clave;

    return strcmp(codRep,codRepNodo)==0;
}
void imprimeregistros(ofstream &arch,void *datoNodo) {
    void **dupla=(void **)datoNodo;
    void **datoRepartidor=(void **)dupla[duplaDato];

    char *codRepartidor=(char *)datoRepartidor[codRepart];
    char *nombRepartidor=(char *)datoRepartidor[nombRepart];

    void **regOrdenes=(void **)dupla[duplaArrDato];

    arch<<codRepartidor<<"  "<<nombRepartidor<<endl;
    arch<<"Ordenes: "<<endl;

    if (regOrdenes!=nullptr) {
        for (int i=0;regOrdenes[i]!=nullptr;i++) {
            void **datoOrden=(void **)regOrdenes[i];
            int dniOrden=*(int*)datoOrden[ordenDni];
            int cantOrden=*(int*)datoOrden[ordenCant];
            char *codPlato=(char *)datoOrden[ordenPlato];

            arch<<dniOrden<<setw(10)<<cantOrden<<' '<<codPlato<<endl;
        }
    }

    arch<<endl;
}
//aux
char *leerCadenaExacta(ifstream &arch,char delim) {
    char aux[300],*cad;
    arch.getline(aux,300,delim);
    if (arch.eof())return nullptr;
    cad=new char[strlen(aux)+1];
    strcpy(cad,aux);
    return cad;
}
