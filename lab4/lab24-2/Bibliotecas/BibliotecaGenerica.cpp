//
// Created by ANTONIO on 3/05/2026.
//
#include <fstream>
#include <iostream>



using namespace std;

#include "BibliotecaGenerica.h"
#include "ListaConEnteros.h"
#include "Lista.h"
#include "enums.h"

void creaLista(void *&lista,bool (*leeDatos)(ifstream &,void*& ),const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR AL ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    void *registro;

    construirLista(lista);
    while (leeDatos(arch,registro)) {
        void *ultimoNodo=ultimo(lista);
        insertarSiguiente(lista,ultimoNodo,registro);
    }
}
void cargarlista(void *lista,bool (*comprueba)(void *,void *),bool (*leeDatos)(ifstream &,void*&,void*&),const char *nombArch) {
    ifstream arch;
    abrirIn(arch,nombArch);
    void *registro,*clave;
    while (leeDatos(arch,registro,clave)) {
        void *dupla=buscarDupla(comprueba,lista,clave);
        if (dupla!=nullptr) {
            insertarEnDupla(dupla,registro);
        }
    }
}
void *buscarDupla(bool (*comprueba)(void *,void *),void *lista,void *clave) {
    void **auxLista=(void **)lista;
    void **nodoActual=(void **)auxLista[CABEZA];

    while (nodoActual!=nullptr) {
        void **siguiente=(void **)nodoActual[SIGUIENTE];

        if (comprueba(nodoActual[DATO],clave)) {
            return nodoActual[DATO];
        }

        nodoActual=siguiente;
    }
    return nullptr;
}
void insertarEnDupla(void *&dupla,void *&registro) {
    void **auxDupla=(void **)dupla;
    void **regNum=(void **)auxDupla[duplaArr];
    añadirEspacioExacto(regNum,registro);
    auxDupla[duplaArr]=regNum;

}
void añadirEspacioExacto(void **&regNum,void *registro) {
    int num=0;
    if (regNum!=nullptr) {
        while (regNum[num]) num++;
    }
    void **aux=new void*[num+2];
    for (int i=0;i<num;i++) {
        aux[i]=regNum[i];
    }
    aux[num]=registro;
    aux[num+1]=nullptr;
    delete []regNum;

    regNum=aux;
}
void muestralista(void *lista,void (*imp)(ofstream &,void *),const char* nombArch) {
    ofstream archRep;
    abrirOut(archRep,nombArch);
    const void **auxLista=(const void**)lista;
    void **nodoActual=(void **)auxLista[CABEZA];

    while (nodoActual!=nullptr) {
        void **siguiente=(void **)nodoActual[SIGUIENTE];

        imp(archRep,nodoActual[DATO]);
        nodoActual=siguiente;
    }
}
//aux
void abrirIn(ifstream &arch,const char *nombArch) {
    arch.open(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR AL ABIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
}
void abrirOut(ofstream &archRep,const char *nombArch) {
    archRep.open(nombArch,ios::out);
    if (not archRep.is_open()) {
        cout<<"ERROR AL ABIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
}

