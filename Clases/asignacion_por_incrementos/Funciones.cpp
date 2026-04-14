//
// Created by ANTONIO on 13/04/2026.
//

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

#include "Funciones.h"
#define INCREMENTO 5

void guardarDatosPorIncremento(int *&numeros,int &cantDatos,const char *nombArch) {
    ifstream archivo(nombArch,ios::in);
    if (not archivo.is_open()) {
        cout<<"ERROR AL ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    int capacidad=0,datoEntrada;
    cantDatos=0;
    numeros=nullptr;
    while (true) {
        archivo>>datoEntrada;
        if (archivo.eof()) break;
        if (capacidad==cantDatos) {
            incrementarEspacios(numeros,cantDatos,capacidad);
        }
        numeros[cantDatos]=datoEntrada;
        cantDatos++;
    }
}
void incrementarEspacios(int *&numeros,int cantDatos,int &capacidad) {
    int *aux;
    capacidad+=INCREMENTO;
    if (numeros==nullptr) {
        numeros=new int [capacidad]{};
    }else {
        aux=new int [capacidad]{};
        for (int i=0;i<cantDatos;i++) {
            aux[i]=numeros[i];
        }
        delete [] numeros;
        numeros=aux;
    }
}
