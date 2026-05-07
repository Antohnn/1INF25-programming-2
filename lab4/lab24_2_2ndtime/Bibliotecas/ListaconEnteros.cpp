//
// Created by ANTONIO on 6/05/2026.
//
#include <iostream>
#include <fstream>

using namespace std;

#include "ListaconEnteros.h"
#include "enums.h"

bool leenumeros(ifstream &arch,void *&dato) {
    int num;

    arch>>num;
    if (arch.eof()) return false;

    void **reg=new void*[2];
    reg[duplaDato]=new int(num);
    reg[duplaArrDato]=nullptr;

    dato=reg;
    return true;
}

bool leeregnumeros(ifstream &arch,void *&dato,void *&clave){
    int num,numArr;

    arch>>num;
    if (arch.eof()) return false;
    arch>>numArr;

    void **reg=new void*[1];

    reg[0]=new int(numArr);
    clave=new int(num);

    dato=reg;
    return true;
}
bool compruebanumero(void *nodoActual,void *clave) {
    void **datoNodo=(void **)nodoActual;

    int numNodo=*(int*)datoNodo[duplaDato];
    int numAct=*(int*)clave;

    return numNodo==numAct;
}
void imprimenumeros(ofstream &archRep,void *nodoActual) {
    void **datoNodo=(void **)nodoActual;

    int numero=*(int*)datoNodo[duplaDato];
    void **regArr=(void **)datoNodo[duplaArrDato];

    archRep<<numero<<endl;
    for(int i=0;regArr[i];i++) {
        void **dato=(void **)regArr[i];
        int numArr=*(int*)dato[0];

        archRep<<" "<<numArr;
    }
    archRep<<endl;
}
