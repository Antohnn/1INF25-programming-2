//
// Created by ANTONIO on 6/05/2026.
//
#include <iostream>
#include <fstream>

#include "BibliotecaConductores.h"
#include "enums.h"

using namespace std;

#include "BibliotecaInfracciones.h"

bool leeinfracciones(ifstream &arch,void *&dato) {
    int licInfraccion,numInfraccion,dd,mm,aa,fecha;
    char *placaInfraccion,c;

    arch>>licInfraccion;
    if (arch.eof())return false;
    arch.get();
    placaInfraccion=leerCadenaExacta(arch,',');
    arch>>dd>>c>>mm>>c>>aa>>c>>numInfraccion;
    fecha=aa*10000+mm*100+dd;

    void **reg=new void*[cantNumInfrac];
    reg[infracLic]=new int(licInfraccion);
    reg[infracPlaca]=placaInfraccion;
    reg[infracFecha]=new int(fecha);
    reg[infracTipoFalta]=new int(numInfraccion);

    dato=reg;
    return true;
}
int cmpinfracciones(void *nodoAct,void* dato) {
    void **datoNodo=(void **)nodoAct;
    void **datoActual=(void **)dato;

    int fechaNodo=*(int *)datoNodo[infracFecha];
    int fechaActual=*(int *)datoActual[infracFecha];

    return fechaNodo-fechaActual;
}
void *buscalistainfraccion(void *lista,void *dato) {
    void **auxLista=(void **)lista;
    void **nodoActual=(void **)auxLista[CABEZA];

    while (nodoActual!=nullptr) {
        void **siguiente=(void **)nodoActual[SIGUIENTE];
        void **datoNodo=(void **)nodoActual[DATO];
        void **datoInfra=(void **)dato;

        int licNodo=*(int *)datoNodo[conducLic];
        int licInfra=*(int *)datoInfra[infracLic];
        void **listaInfra=(void **)datoNodo[conducListFalta];

        if (licNodo==licInfra) {
            return listaInfra;
        }
        nodoActual=siguiente;
    }
    return nullptr;
}
