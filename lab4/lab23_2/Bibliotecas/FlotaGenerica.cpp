//
// Created by ANTONIO on 7/05/2026.
//

#include <fstream>
#include <iostream>

using namespace std;

#include "FlotaGenerica.h"
#include "enums.h"

void cargacamiones(void *&flota,int numcamiones,double pesomaximo,
    bool (*lee)(ifstream &,void *&),double (*calcula)(void *),const char *nombArch) {
    ifstream arch;
    abrirIn(arch,nombArch);
    void *dato;

    construyeFlota(flota,numcamiones);
    void **auxFlota=(void **)flota;
    int camion=0;

    //leo el dato
    while (lee(arch,dato)) {
        //saco el peso del dato actual guardado
        double pesoDato=calcula(dato);
        //busco el peso guardado en el arreglo flota y sumo el peso
        if (obtenerPeso(auxFlota[camion]) + pesoDato<=pesomaximo) {
            //push a la fila
            push(auxFlota[camion],dato,pesoDato);
        }else {
            //sino aumento el camion
            camion++;
        }
        //si el camion es igual a numcamiones
        if (camion==numcamiones)break;
        //hago push
        push(auxFlota[camion],dato,pesoDato);
    }
}
void construyeFlota(void *&flota,int numcamiones) {
    void **auxFlota=new void *[numcamiones];

    for (int i=0;i<numcamiones;i++) {
        construyePila(auxFlota[i]);
    }
    flota=auxFlota;
}
void construyePila(void *&flota) {
    construyeLista(flota);
}
void push(void *&flota,void *&dato,double pesoDato) {
    insertarSiguiente(flota,nullptr,dato);
    aumentoPeso(flota,pesoDato);
}
double obtenerPeso(void *auxFlota) {
    void **auxPila=(void **)auxFlota;
    double peso=*(double *)auxPila[PESO];

    return peso;
}
void aumentoPeso(void *flota,double pesoDato) {
    void **auxPila=(void **)flota;
    double *peso=(double *)auxPila[PESO];

    *peso+=pesoDato;
}
//aux
void abrirIn(ifstream &arch,const char *nombArch) {
    arch.open(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR AL ABRIR "<<nombArch<<endl;
        exit(1);
    }
}
void abrirOut(ofstream &archRep,const char *nombArch) {
    archRep.open(nombArch,ios::out);
    if (not archRep.is_open()) {
        cout<<"ERROR AL ABRIR "<<nombArch<<endl;
        exit(1);
    }
}
void construyeLista(void *&pila) {
    void **auxLista=new void*[3];

    auxLista[CABEZA]=nullptr;
    auxLista[PESO]=new double(0);

    pila=auxLista;
}
void insertarSiguiente(void *flota,void *nodo,void *dato) {
    void **auxLista=(void **)flota;

    void **nuevoNodo=new void*[2];
    nuevoNodo[DATO]=dato;
    nuevoNodo[SIGUIENTE]=nullptr;

    if (nodo==nullptr) {
        if (esListaVacia(flota)) {
            auxLista[CABEZA]=nuevoNodo;
            auxLista[COLA]=nuevoNodo;
        }else {
            nuevoNodo[SIGUIENTE]=auxLista[CABEZA];
            auxLista[CABEZA]=nuevoNodo;
        }
    }else {
        void **auxNodo=(void **)nodo;

        nuevoNodo[SIGUIENTE]=auxNodo[SIGUIENTE];
        auxNodo[SIGUIENTE]=nuevoNodo;

        if (nodo==auxLista[COLA]) {
            auxLista[COLA]=nuevoNodo;
        }
    }
}
bool esListaVacia(void *flota) {
    void **auxLista=(void **)flota;

    return auxLista[CABEZA]==nullptr;
}