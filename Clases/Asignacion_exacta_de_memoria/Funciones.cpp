//
// Created by ANTONIO on 13/04/2026.
//
#include <iostream>
#include <cstring>
#include <fstream>

#include "Funciones.h"

using namespace std;

void leerNumeroExactos(int *&numeros,int &n,const char *nombArch) {
    ifstream archivo(nombArch,ios::in);
    if (not archivo.is_open()) {
        cout<<"ERROR AL ABRIR "<<nombArch<<endl;
        exit(1);
    }
    int buffer[300],num;

    n=0;

    while (true) {
        archivo>>num;
        buffer[n]=num;
        n++;
        if (archivo.eof()) break;
    }
    numeros=new int[n];

    for (int i=0;i<n;i++) {
        numeros[i]=buffer[i];
    }




}
