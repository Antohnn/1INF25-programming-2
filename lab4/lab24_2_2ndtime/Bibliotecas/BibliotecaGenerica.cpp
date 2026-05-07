//
// Created by ANTONIO on 6/05/2026.
//

#include <iostream>
#include <fstream>

#include "enums.h"

using namespace std;

#include "BibliotecaGenerica.h"
#include "enums.h"

void creaLista(void *&lista,bool (*leeDatos)(ifstream &,void *&),const char *nombArch) {
    ifstream arch;
    abrirIn(arch,nombArch);
    construirLista(lista);
    void *dato;

    while (leeDatos(arch,dato)) {
        void *ultimoNodo=obtenerUltimo(lista);
        insertaSiguiente(lista,ultimoNodo,dato);
    }
}
void cargaLista(void *lista,bool (*cmp)(void *,void *),bool (*leeDatos)(ifstream &,void *&,void *&),const char *nombArch) {
    ifstream arch;
    abrirIn(arch,nombArch);

    void *dato,*clave;

    while (leeDatos(arch,dato,clave)) {
        void *dupla=buscarDupla(lista,clave,cmp);
        if (dupla!=nullptr) {
            insertaEnDupla(dupla,dato);
        }
    }
}
void *buscarDupla(void *lista,void *clave,bool (*cmp)(void *,void *)) {
    void **auxLista=(void **)lista;
    void **nodoActual=(void **)auxLista[CABEZA];

    while (nodoActual!=nullptr) {
        void **siguiente=(void **)nodoActual[SIGUIENTE];

        if (cmp (nodoActual[DATO],clave)) {
            return nodoActual[DATO];
        }
        nodoActual=siguiente;
    }
    return nullptr;
}
void insertaEnDupla(void *dupla,void *dato) {
    void **datoDupla=(void **)dupla;
    void **registros=(void **)datoDupla[duplaArrDato];

    insertarExacto(registros,dato);
    datoDupla[duplaArrDato]=registros;
}
void insertarExacto(void **&registros,void *dato) {
    int num=0;
    if (registros!=nullptr) {
        while (registros[num]) num++;
    }
    void **aux=new void*[num+2];
    for (int i=0;i<num;i++) {
        aux[i]=registros[i];
    }
    aux[num]=dato;
    aux[num+1]=nullptr;
    delete []registros;
    registros=aux;
}
void muestraLista(void *lista,void (*imprime)(ofstream &,void*),const char *nombArch) {
    ofstream archRep;
    abrirOut(archRep,nombArch);
    void **auxLista=(void **)lista;
    void **nodoActual=(void **)auxLista[CABEZA];

    while (nodoActual!=nullptr) {
        void **siguiente=(void **)nodoActual[SIGUIENTE];
        imprime(archRep,nodoActual[DATO]);
        nodoActual=siguiente;
    }
}
//aux
void construirLista(void *&lista) {
    void **auxLista=new void*[3];

    auxLista[CABEZA]=nullptr;
    auxLista[COLA]=nullptr;
    auxLista[LONGITUD]=new int(0);

    lista=auxLista;
}
void *obtenerUltimo(void *lista) {
    void **auxLista=(void **)lista;
    void **nodoActual=(void **)auxLista[CABEZA];
    void **anterior=nullptr;

    while (nodoActual!=nullptr) {
        void **siguiente=(void **)nodoActual[SIGUIENTE];

        anterior=nodoActual;
        nodoActual=siguiente;
    }
    return anterior;
}
void insertaSiguiente(void *lista,void *nodo,void *dato) {
    void **auxLista=(void **)lista;

    void **nuevoNodo=new void*[2];
    nuevoNodo[DATO]=dato;
    nuevoNodo[SIGUIENTE]=nullptr;

    if (nodo==nullptr) {
        if (esListaVacia(lista)) {
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
bool esListaVacia(void *lista) {
    void **auxLista=(void **)lista;

    return auxLista[CABEZA]==nullptr;
}
//arch
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
