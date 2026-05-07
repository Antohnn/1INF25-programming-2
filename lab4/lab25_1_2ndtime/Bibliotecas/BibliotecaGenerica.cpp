//
// Created by ANTONIO on 7/05/2026.
//
#include <fstream>
#include <iostream>

using namespace std;

#include "BibliotecaGenerica.h"
#include "BibliotecaConductores.h"
#include "enums.h"

void generalista(void *&lista) {
    void **auxLista=new void*[1];
    auxLista[CABEZA]=nullptr;
    lista=auxLista;
}
void creaLista(void *lista,bool (*leeDatos)(ifstream &,void *&),int (*cmp)(void *,void *),void *(*buscalista)(void *,void *),
    const char *nombArch) {
    ifstream arch;
    abrirIn(arch,nombArch);
    void *dato;

    while (leeDatos(arch,dato)) {
        insertaLista(lista,cmp,buscalista,dato);
    }
}
void insertaLista(void *lista,int (*cmp)(void *,void *),void *(*buscalista)(void *,void *),void *dato) {
    void *listaInsertar=buscalista(lista,dato);
    void **auxLista=(void **)listaInsertar;
    void **nodoActual=(void **)auxLista[CABEZA];
    void **anterior=nullptr;

    while (nodoActual!=nullptr and cmp(nodoActual[DATO],dato)<0) {
        void **siguiente=(void **)nodoActual[SIGUIENTE];
        anterior=nodoActual;
        nodoActual=siguiente;
    }
    insertaSiguiente(lista,anterior,dato);
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
void insertaSiguiente(void *lista,void *nodo,void *dato) {
    void **auxLista=(void **)lista;
    void **nodoActual=(void **)auxLista[CABEZA];

    void **nuevoNodo=new void*[2];
    nuevoNodo[DATO]=dato;
    nuevoNodo[SIGUIENTE]=nullptr;

    if (nodo==nullptr) {
        if (esListaVacia(lista)) {
            auxLista[CABEZA]=nuevoNodo;
        }else {
            nuevoNodo[SIGUIENTE]=auxLista[CABEZA];
            auxLista[CABEZA]=nuevoNodo;
        }
    }else {
        void **auxNodo=(void **)nodo;

        nuevoNodo[SIGUIENTE]=auxNodo[SIGUIENTE];
        auxNodo[SIGUIENTE]=nuevoNodo;
    }
}

bool esListaVacia(void *lista) {
    void **auxLista=(void **)lista;

    return auxLista[CABEZA]==nullptr;
}

