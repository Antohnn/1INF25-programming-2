//
// Created by ANTONIO on 15/06/2026.
//

#include <iostream>
using namespace std;
#include "Lista.h"

Lista::Lista() {
    listaDoblementeLigada=nullptr;
}

void Lista::insertar(Metrica *metrica) {
    Nodo *nuevo=new Nodo();
    nuevo->metrica=metrica;

    Nodo *rec=listaDoblementeLigada;
    Nodo *ant=nullptr;

    while(rec!=nullptr and !comprobarOrden(rec->metrica,metrica)) {
        ant=rec;
        rec=rec->siguiente;
    }

    nuevo->anterior=ant;
    nuevo->siguiente=rec;

    if (ant==nullptr) {
        listaDoblementeLigada=nuevo;
    }else {
        ant->siguiente=nuevo;
    }
    if (rec!=nullptr) {
        rec->anterior=nuevo;
    }
}
//
void Lista::imprimir(ofstream &archRep) {
    Nodo *rec=listaDoblementeLigada;
    while(rec!=nullptr) {
        rec->metrica->imprimir(archRep);
        rec=rec->siguiente;
    }
}
void Lista::eliminarNodo(Nodo *nodo) {
    Nodo *ant=nodo->anterior;
    Nodo *sig=nodo->siguiente;

    if (nodo->anterior!=nullptr) {
        ant->siguiente=sig;
    }else {
        listaDoblementeLigada=sig;
    }
    if (nodo->siguiente!=nullptr) {
        sig->anterior=ant;
    }
    delete nodo;
}
void Lista::eliminarExpiradas() {
    Nodo *rec=listaDoblementeLigada;
    while(rec!=nullptr) {
        Nodo *sig=rec->siguiente;
        if (!rec->metrica->get_estado()) {
            eliminarNodo(rec);
        }
        rec=sig;
    }
}
void Lista::eliminarLista() {
    Nodo *rec=listaDoblementeLigada;

    while(rec!=nullptr) {
        Nodo *sale=rec;
        rec=rec->siguiente;
        delete sale;
    }
    listaDoblementeLigada=nullptr;
}
//
bool Lista::comprobarOrden(Metrica *actual,Metrica *nuevo) {
    if (actual->getTipo()!=nuevo->getTipo()) {
        return actual->getTipo()>nuevo->getTipo();
    }
    return actual->get_descripcion()>nuevo->get_descripcion();
}
bool Lista::estaVacia() const {
    return listaDoblementeLigada==nullptr;
}
Lista::~Lista() {
    delete [] listaDoblementeLigada;
}