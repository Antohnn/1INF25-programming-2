//
// Created by ANTONIO on 16/04/2026.
//
#include <iostream>
#include <fstream>
#include <cstring>

#include "conductores.h"
#include "faltas.h"
#include "infracciones.h"

using namespace std;

#include "Funciones.h"

void operator +=(Conductores &conductores,const char *nombArch) {
    //conductores+="conductores.csv"
    ifstream archivo(nombArch,ios::in);;
    int numDat=0;
    int bufferDni[200],dni;
    char *bufferNombre[200],*nombre;

    while (leerConductores(archivo,dni,nombre)) {
        bufferDni[numDat]=dni;
        bufferNombre[numDat]=nombre;
        numDat++;
    }
    conductores.cantidad=numDat;
    conductores.dnis=new int[numDat+1]{};
    conductores.nombres=new char*[numDat+1]{};

    for (int i=0;i<numDat;i++) {
        conductores.dnis[i]=bufferDni[i];
        conductores.nombres[i]=bufferNombre[i];
    }
}
bool leerConductores(ifstream &archivo,int &dni,char *&nombre) {
    archivo>>dni;
    if (archivo.eof())return false;
    archivo.ignore();
    nombre=leerCadenaExacta(archivo,'\n');
    return true;
}
//cargar Infracciones
void operator +=(Infracciones &infracciones,const char *nombArch) {
    //infracciones+="infracciones.csv"
    ifstream archivo(nombArch,ios::in);
    int numDat=0;
    int buffCodigo[200];
    char *buffDesc[200],*buffTipo[200];
    double buffValor[200];

    int codInfra;
    char *descripcion,*tipo;
    double valor;
    while (leerInfraccion(archivo,codInfra,descripcion,tipo,valor)) {
        buffCodigo[numDat]=codInfra;
        buffDesc[numDat]=descripcion;
        buffTipo[numDat]=tipo;
        buffValor[numDat]=valor;
        numDat++;
    }
    infracciones.cantidad=numDat;
    infracciones.codigos=new int[numDat+1]{};
    infracciones.descripciones=new char*[numDat+1]{};
    infracciones.tipos=new char*[numDat+1]{};
    infracciones.valores=new double[numDat+1]{};

    for (int i=0;i<numDat;i++) {
        infracciones.codigos[i]=buffCodigo[i];
        infracciones.descripciones[i]=buffDesc[i];
        infracciones.tipos[i]=buffTipo[i];
        infracciones.valores[i]=buffValor[i];
    }
}
bool leerInfraccion(ifstream &archivo,int &codInfra,char *&descripcion,char *&tipo,double &valor) {
    archivo>>codInfra;
    if (archivo.eof())return false;
    archivo.get();
    descripcion=leerCadenaExacta(archivo,',');
    tipo=leerCadenaExacta(archivo,',');
    archivo>>valor;
    return true;
}
//cargarFaltas
void cargar_faltas_de_los_conductores(const char *nombArch,Faltas &faltas) {
    ifstream archivo(nombArch,ios::in);
    faltas.conductores+="Archivos/Conductores.csv";
    faltas.infracciones+="Archivos/Infracciones.csv";
    int dni,codInf,idConductor;
    char *placa;
    int n=faltas.conductores.cantidad;
    faltas.placas=new char**[n]{};
    faltas.capacidades=new int[n]{};

    while (leerFalta(archivo,dni,codInf,placa)) {
        idConductor=buscarConductor(faltas.conductores,dni);
        if (idConductor!=-1) {
            if(!placaRepetida(faltas.placas[idConductor],placa)){
                insertarPlaca(faltas.placas[idConductor],faltas.capacidades[idConductor],placa);
            }
            else delete[] placa;
        }else delete[] placa;
    }
}
int buscarConductor(Conductores &conductores,int dni) {
    for (int i=0;i<conductores.cantidad;i++) {
        if (conductores.dnis[i]==dni) return i;
    }
    return -1;
}
bool leerFalta(ifstream &archivo,int &dni,int &codInf,char *&placa) {
    int num;
    char c;
    archivo>>dni;
    if (archivo.eof())return false;
    archivo.get();

    placa=leerCadenaExacta(archivo,',');
    archivo>>num>>c>>num>>c>>num>>c;
    archivo>>codInf;
    return true;
}
bool placaRepetida(char **bloque,char *placa) {
    if (bloque==nullptr) return false;
    for (int i=0;bloque[i]!=nullptr;i++) {
        if (strcmp(bloque[i],placa)==0) return true;
    }
    return false;
}
void insertarPlaca(char **&bloque,int &capacidad,char *placa) {
    int usados=contarPlacas(bloque);

    if (usados+1>=capacidad) {
        incrementarBloque(bloque,capacidad,usados);
    }
    bloque[usados]=placa;
    bloque[usados+1]=nullptr;
}
int contarPlacas(char **bloque) {
    if (bloque==nullptr) return 0;
    int n=0;
    while (bloque[n]!=nullptr) n++;
    return n;
}
void incrementarBloque(char **&bloque,int &capacidad,int usados) {
    capacidad+=2;
    if (bloque==nullptr) {
        bloque=new char*[capacidad]{};
    }else {
        char **aux=new char*[capacidad]{};
        for (int i=0;i<usados;i++) {
            aux[i]=bloque[i];
        }
        delete []bloque;
        bloque=aux;
    }
}
//aux
char* leerCadenaExacta(ifstream &archivo,char delim) {
    char aux[300],*cad;
    archivo.getline(aux,300,delim);
    if (archivo.eof()) return nullptr;
    cad=new char[strlen(aux)+1];
    strcpy(cad,aux);
    return cad;
}
