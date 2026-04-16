//
// Created by ANTONIO on 15/04/2026.
//
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Funciones.h"


//CargarCategorias
void cargarCategorias(const char* nombArch,char ***&categorias) {
    ifstream archCate(nombArch,ios::in);
    int capacidad=0,numDat=0;
    char **categoria;
    categorias=nullptr;

    while (leerCategorias(archCate,categoria)) {
        if (capacidad==numDat) {
            incrementarCategoria(categorias,numDat,capacidad);
        }
        categorias[numDat]=categoria;
        numDat++;
    }
}
void incrementarCategoria(char ***&categorias,int numDat,int &capacidad) {
    capacidad+=5;
    if (categorias==nullptr) {
        categorias=new char**[capacidad+1]{};
    }else {
        char*** aux=new char**[capacidad+1]{};
        for (int i=0;i<numDat;i++) {
            aux[i]=categorias[i];
        }
        delete[] categorias;
        categorias=aux;
    }
}
bool leerCategorias(ifstream &archCate,char **&categoria) {
    char *codigo,*nombCate,*descripcion;
    codigo=leerCadenaExacta(archCate,',');
    if (archCate.eof())return false;
    nombCate=leerCadenaExacta(archCate,',');
    descripcion=leerCadenaExacta(archCate,'\n');

    categoria=new char*[3]{codigo,nombCate,descripcion};
    return true;
}

//cargarStreamers
void cargarStreamers(const char* nombArch,char ***&streamers,int **&fechasPromedios,long long **&tiemposRepSegidores) {
    ifstream archStream(nombArch,ios::in);
    char **streamer;
    int *fechaPromedio;
    long long *tiempoRepSegidor;
    int capacidad=0,numDat=0;
    streamers=nullptr;
    fechasPromedios=nullptr;
    tiemposRepSegidores=nullptr;
    while (leerStreamers(archStream,streamer,fechaPromedio,tiempoRepSegidor)) {
        if (capacidad==numDat) {
            capacidad+=5;
            incrementarStreamer(streamers,numDat,capacidad);
            incrementarFechaPromedio(fechasPromedios,numDat,capacidad);
            incrementarFechaPromedioSeg(tiemposRepSegidores,numDat,capacidad);
        }
    }
}
void incrementarStreamer(char ***&streamers,int numDat,int capacidad) {
    char ***aux;
    if (streamers==nullptr) {
        streamers=new char**[capacidad+1]{};
    }else {
        aux=new char**[capacidad+1]{};
        for (int i=0;i<numDat;i++) {
            aux[i]=streamers[i];
        }
        delete[]streamers;
        streamers=aux;
    }
}
void incrementarFechaPromedio(int **&fechasPromedios,int numDat,int capacidad) {
    int **aux;
    if (fechasPromedios==nullptr) {
        fechasPromedios=new int*[capacidad+1]{};
    }else {
        aux=new int*[capacidad+1]{};
        for (int i=0;i<numDat;i++) {
            aux[i]=fechasPromedios[i];
        }
        delete[]fechasPromedios;
        fechasPromedios=aux;
    }
}
void incrementarFechaPromedioSeg(long long **&tiemposRepSegidores,int numDat,int capacidad) {
    long long **aux;
    if (tiemposRepSegidores==nullptr) {
        tiemposRepSegidores=new long long*[capacidad+1]{};
    }else {
        aux=new long long*[capacidad+1]{};
        for (int i=0;i<numDat;i++) {
            aux[i]=tiemposRepSegidores[i];
        }
        delete[]tiemposRepSegidores;
        tiemposRepSegidores=aux;
    }
}
bool leerStreamers(ifstream &archStream,char **&streamer,int *&fechaPromedio,long long *&tiempoRepSegidor) {
    char *codStreamer,*categoria;
    int fechaCreacion,fechaUlt,promedioSpec,seguidores;
    long long tiempoTotal;

    codStreamer=leerCadenaExacta(archStream,',');
    if (archStream.eof()) return false;
    fechaCreacion=leerFecha(archStream);
    archStream.ignore();
    fec
}
int leerFecha(ifstream &archStream) {
    int dia,mes,anio,fecha;
    char c;

    archStream>>dia>>c>>mes>>c>>anio;
    fecha=anio+10000+mes*100+dia;

    return fecha;
}
//aux
char* leerCadenaExacta(ifstream &arch,char delim) {
    char aux[300],*cad;
    arch.getline(aux,300,delim);
    if (arch.eof()) return nullptr;
    cad= new char[strlen(aux)+1];
    strcpy(cad,aux);
    return cad;
}
