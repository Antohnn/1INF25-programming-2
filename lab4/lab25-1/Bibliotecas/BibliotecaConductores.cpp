//
// Created by ANTONIO on 6/05/2026.
//
#include <iostream>
#include <fstream>
#include <cstring>

#include "BibliotecaConductores.h"

#include <iomanip>

#include "BibliotecaGenerica.h"
#include "enums.h"



using namespace std;

bool leeconductores(ifstream &arch,void *&dato) {
    int licenciaConductor;
    char c,*nombConductor;
    void *listaPlaca;

    arch>>licenciaConductor;
    if (arch.eof())return false;
    arch.get();
    nombConductor=leerCadenaExacta(arch,'\n');
    generaLista(listaPlaca);

    void **reg=new void*[cantNumConduc];
    reg[conducLic]=new int(licenciaConductor);
    reg[conducNomb]=nombConductor;
    reg[conducRegPlaca]=nullptr;
    reg[conducListFalta]=listaPlaca;

    dato=reg;
    return true;
}
void *buscalistaconductores(void *lista,void *dato) {
    return lista;
}
int cmpconductores(void *nodoAct,void *dato) {
    void **datoNodo=(void **)nodoAct;
    void **datoAct=(void **)dato;

    int licNodo=*(int *)datoNodo[conducLic];
    int licAct=*(int *)datoAct[conducLic];

    return licNodo-licAct;
}
void cargaUnidades(void *lista,const char *nombArch) {
    ifstream arch;
    abrirIn(arch,nombArch);
    void *dato;
    int licenciaConductor;

    while (leerLista(arch,dato,licenciaConductor)) {
        void *conducActual=buscarConductor(lista,licenciaConductor);
        if (conducActual!=nullptr) {
            insertarEnListaConductor(conducActual,dato);
        }
    }
}
bool leerLista(ifstream &arch,void *&dato,int &licenciaConductor) {
    char *placa;

    arch>>licenciaConductor;
    if (arch.eof())return false;
    arch.get();
    placa=leerCadenaExacta(arch,'\n');

    void **reg=new void*[1];
    reg[0]=placa;

    dato=reg;
    return true;
}
void *buscarConductor(void *&lista,int licenciaConductor) {
    void **auxLista=(void **)lista;
    void **nodoActual=(void **)auxLista[CABEZA];

    while (nodoActual!=nullptr) {
        void **siguiente=(void **)nodoActual[SIGUIENTE];

        void **datoNodo=(void **)nodoActual[DATO];
        int licenciaActual=*(int *)datoNodo[conducLic];
        if (licenciaActual==licenciaConductor) {
            return nodoActual[DATO];
        }
        nodoActual=siguiente;
    }
    return nullptr;
}
void insertarEnListaConductor(void *conducActual,void *dato) {
    void **datoConductor=(void **)conducActual;
    void **registroPlacas=(void **)datoConductor[conducRegPlaca];
    incrementarExacto(registroPlacas,dato);
    datoConductor[conducRegPlaca]=registroPlacas;
}
void incrementarExacto(void **&registroPlacas,void *dato) {
    int num=0;
    if (registroPlacas!=nullptr) {
        while (registroPlacas[num]) num++;
    }
    void **aux=new void*[num+2]{};
    for (int i=0;i<num;i++) {
        aux[i]=registroPlacas[i];
    }
    aux[num]=dato;
    aux[num+1]=nullptr;
    delete[] registroPlacas;
    registroPlacas=aux;
}
void imprimeconductores(ofstream &archRep,void *nodoActual) {
    void **datoNodo=(void **)nodoActual;
    int licenciaConductor=*(int *)datoNodo[conducLic];
    char *nombConductor=(char *)datoNodo[conducNomb];
    void **regPlacas=(void **)datoNodo[conducRegPlaca];
    void **listaFaltas=(void **)datoNodo[conducListFalta];

    archRep<<licenciaConductor<<" "<<nombConductor<<endl;
    archRep<<"Placas: ";
    if (regPlacas!=nullptr) {
        for (int i=0;regPlacas[i]!=nullptr;i++) {
            imprimePlaca(archRep,regPlacas[i]);
        }
    }
    archRep<<endl;
    archRep<<"Fecha"<<setw(20)<<"Placa"<<setw(20)<<"Infraccion"<<endl;
    if (listaFaltas!=nullptr) {
        void **nodoFalta=(void **)listaFaltas[CABEZA];

        while (nodoFalta!=nullptr) {
            void **siguiente=(void **)nodoFalta[SIGUIENTE];
            void **infraccion=(void **)nodoFalta[DATO];
            imprimeInfraccion(archRep,infraccion);
            nodoFalta=siguiente;
        }
    }
}
void imprimePlaca(ofstream &archRep,void *placa) {
    void **regPlacas=(void **)placa;
    char *placaAct=(char *)regPlacas[0];

    archRep<<placaAct<<" ";
}
void imprimeInfraccion(ofstream &archRep,void *infraccion) {
    void **regInfraccion=(void **)infraccion;
    int fechaInf=*(int *)regInfraccion[infracFecha];
    char *placaAct=(char *)regInfraccion[infracPlaca];
    int infracTipo=*(int *)regInfraccion[infracTipoFalta];

    archRep<<fechaInf<<" "<<placaAct<<" "<<infracTipo<<endl;
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
