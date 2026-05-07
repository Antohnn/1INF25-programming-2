//
// Created by ANTONIO on 7/05/2026.
//
#include <cstring>
#include <iostream>
#include <fstream>

#include "BibliotecaGenerica.h"
#include "enums.h"

using namespace std;

#include "BibliotecaConductores.h"

bool leeconductores(ifstream &arch,void *&dato) {
    int licenciaConduc;
    char *nombConductor;

    arch>>licenciaConduc;
    if (arch.eof())return false;
    arch.get();
    nombConductor=leerCadenaExacta(arch,'\n');

    void *listaPlaca;
    generalista(listaPlaca);

    void **reg=new void*[4];
    reg[conductorLic]=new int(licenciaConduc);
    reg[conductorNomb]=nombConductor;
    reg[conductorArrPlaca]=nullptr;
    reg[conductorLista]=listaPlaca;

    dato=reg;
    return true;
}
void *buscalistaconductores(void *lista,void *dato) {
    return lista;
}
int cmpcondcutores(void *nodoActual,void *dato) {
    void **datoConductor=(void **)nodoActual;
    void **datoActual=(void **)dato;

    int licConductorNodo=*(int *)datoConductor[conductorLic];
    int licConductorAct=*(int *)datoActual[conductorLic];

    return licConductorNodo-licConductorAct;
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
