//
// Created by ANTONIO on 3/05/2026.
//
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "ListaconRegistros.h"
#include "BibliotecaGenerica.h"
#include "Lista.h"
#include "enums.h"

bool leeregistros(ifstream &arch,void *&registro) {
    char *codRepartidor,*nombRepartidor,*vehiRepartidor;

    codRepartidor=leerCadenaExacta(arch,',');
    if (arch.eof())return false;
    nombRepartidor=leerCadenaExacta(arch,',');
    vehiRepartidor=leerCadenaExacta(arch,'\n');

    void **reg=new void*[cantDatosDupla];

    reg[duplaArr]=nullptr;

    void **regRepartidor=new void*[cantDatoRepart];
    regRepartidor[repartidorCod]=codRepartidor;
    regRepartidor[repartidorNomb]=nombRepartidor;
    regRepartidor[repartidorVehi]=vehiRepartidor;

    reg[duplaDato]=regRepartidor;

    registro=reg;

    return true;
}
bool leeordenes(ifstream &arch,void *&registro,void *&clave) {
    int dniOrden,cantOrden;
    char *codPlato,*codRepartidor,c;

    arch>>dniOrden;
    if (arch.eof())return false;
    arch>>c>>cantOrden>>c;
    codPlato=leerCadenaExacta(arch,',');
    codRepartidor=leerCadenaExacta(arch,'\n');

    void **reg=new void*[cantDatoOrden];
    reg[ordenDni]=new int(dniOrden);
    reg[ordenCant]=new int(cantOrden);
    reg[ordenPlato]=codPlato;

    registro=reg;
    clave=codRepartidor;
    return true;
}
bool compruebaregistro(void *datoNodo,void *clave){
    void **dupla=(void **)datoNodo;
    void **datoRepartidor=(void **)dupla[duplaDato];

    char *codRepartidor=(char *)datoRepartidor[repartidorCod];
    char *codActual=(char *)clave;

    return strcmp(codRepartidor,codActual)==0;
}
void imprimeregistros(ofstream &arch,void *datoNodo) {
    void **dupla=(void **)datoNodo;
    void **datoRepartidor=(void **)dupla[duplaDato];

    char *codRepartidor=(char *)datoRepartidor[repartidorCod];
    char *nombRepartidor=(char *)datoRepartidor[repartidorNomb];

    void **regOrdenes=(void **)dupla[duplaArr];

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
