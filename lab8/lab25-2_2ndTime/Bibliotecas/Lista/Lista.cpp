//
// Created by ANTONIO on 18/06/2026.
//

#include <iostream>
using namespace std;
#include "Lista.h"
#include "Nodo.h"

Lista::Lista() {
    listaDoblementeLigada=nullptr;
}
//
void Lista::insertarOrdenado(Metrica *metrica) {
    Nodo *nuevo=new Nodo();
    nuevo->metrica=metrica;

    Nodo* rec=listaDoblementeLigada;
    Nodo* ant=nullptr;

    while (rec!=nullptr and !vaAntes(rec->metrica,metrica)) {
        ant=rec;
        rec=rec->siguiente;
    }
    nuevo->anterior=ant;
    nuevo->siguiente=rec;
    if (ant!=nullptr) {
        ant->siguiente=nuevo;
    }else {
        listaDoblementeLigada=nuevo;
    }
    if (rec!=nullptr) {
        rec->anterior=nuevo;
    }
}
bool Lista::vaAntes(Metrica *actual,Metrica *nueva) {
    if (actual->get_tipo()!=nueva->get_tipo()) {
        return actual->get_tipo()>nueva->get_tipo();
    }
    return actual->get_descripcion()>nueva->get_descripcion();
}
void Lista::imprimir(ofstream &archRep) {
    Nodo *rec=listaDoblementeLigada;
    int tipoAnterior=-1,activas=0,expiradas=0;
    while (rec!=nullptr) {
        if (rec->metrica->get_tipo()!=tipoAnterior) {
            if (tipoAnterior!=-1) {
                imprimirLinea(archRep,'-');
            }
            tipoAnterior=rec->metrica->get_tipo();
        }
        rec->metrica->imprimir(archRep);
        if (rec->metrica->get_estado()) {
            activas++;
        }else {
            expiradas++;
        }
        rec=rec->siguiente;
    }
}
void Lista::imprimirLinea(ofstream &arch, char car) {
    arch << string(120, car) << endl;
}
void Lista::eliminarNodo(Nodo *nodo) {
    Nodo *ant=nodo->anterior;
    Nodo *sig=nodo->siguiente;

    if (ant!=nullptr) {
        ant->siguiente=sig;
    }else {
        listaDoblementeLigada=sig;
    }
    if (sig!=nullptr) {
        sig->anterior=ant;
    }
    delete nodo;
}
void Lista::eliminarLista() {
    Nodo *rec=listaDoblementeLigada;

    while (rec!=nullptr) {
        Nodo *sale=rec;
        rec=rec->siguiente;
        delete sale;
    }
    listaDoblementeLigada=nullptr;
}
void Lista::eliminarExpiradas() {
   Nodo *rec=listaDoblementeLigada;
    while (rec!=nullptr) {
        Nodo *sig=rec->siguiente;
        if (!rec->metrica->get_estado()) {
            eliminarNodo(rec);
        }
        rec=sig;
    }
}
//destructor
Lista::~Lista() {
    eliminarLista();
}

