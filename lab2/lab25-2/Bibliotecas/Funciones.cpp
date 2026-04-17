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
        streamers[numDat]=streamer;
        fechasPromedios[numDat]=fechaPromedio;
        tiemposRepSegidores[numDat]=tiempoRepSegidor;
        numDat++;
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
    char *codStreamer,*categoria,c;
    int fechaCreacion,fechaUlt,promedioSpec;
    long long tiempoTotal,seguidores;

    codStreamer=leerCadenaExacta(archStream,',');
    if (archStream.eof()) return false;
    fechaCreacion=leerFecha(archStream);
    archStream.ignore();
    fechaUlt=leerFecha(archStream);
    archStream.ignore();
    archStream>>tiempoTotal>>c>>promedioSpec>>c>>seguidores;
    categoria=leerCadenaExacta(archStream,'\n');

    streamer=new char*[2]{codStreamer,categoria};
    fechaPromedio=new int[3]{fechaCreacion,fechaUlt,promedioSpec};
    tiempoRepSegidor=new long long[2]{tiempoTotal,seguidores};
    return true;
}
int leerFecha(ifstream &archStream) {
    int dia,mes,anio,fecha;
    char c;

    archStream>>dia>>c>>mes>>c>>anio;
    fecha=anio+10000+mes*100+dia;
    return fecha;
}
//cargarComentarios
void cargarComentarios(const char *nombArch,char ***&comentarios,char ***&etiquetas) {
    ifstream archCom(nombArch,ios::in);
    char **comentario,**etiquetaComent;
    int capacidad=0,numDat=0;
    comentarios=nullptr;
    etiquetas=nullptr;
    while (leerComentarios(archCom,comentario,etiquetaComent)) {
        if (capacidad==numDat) {
            capacidad+=5;
            incrementarComentarios(comentarios,numDat,capacidad);
            incrementarEtiquetas(etiquetas,numDat,capacidad);
        }
        comentarios[numDat]=comentario;
        etiquetas[numDat]=etiquetaComent;
        numDat++;
    }
}
void incrementarComentarios(char ***&comentarios,int numDat,int capacidad) {
    char ***aux;
    if (capacidad==numDat) {
        comentarios=new char**[capacidad+1]{};
    }else {
        aux=new char**[capacidad+1]{};
        for (int i=0;i<numDat;i++) {
            aux[i]=comentarios[i];
        }
        delete[]comentarios;
        comentarios=aux;
    }
}
void incrementarEtiquetas(char ***&etiquetas,int numDat,int capacidad) {
    char ***aux;
    if (capacidad==numDat) {
        etiquetas=new char**[capacidad+1]{};
    }else {
        aux=new char**[capacidad+1]{};
        for (int i=0;i<numDat;i++) {
            aux[i]=etiquetas[i];
        }
        delete[]etiquetas;
        etiquetas=aux;
    }
}
bool leerComentarios(ifstream &archCom,char **&comentario,char **&etiquetaComent) {
    char *codUsuario,*texto,*textoParte2,*textoCompleto;

    codUsuario=leerCadenaExacta(archCom,',');
    if (archCom.eof())return false;
    texto=leerCadenaExacta(archCom,'[');
    cargarEtiquetas(archCom,etiquetaComent);
    if (archCom.peek() != '\n') {
        textoParte2=leerCadenaExacta(archCom,'\n');
        int sumaCar=strlen(textoParte2)+strlen(texto)+1;
        textoCompleto=new char[sumaCar];
        strcpy(textoCompleto,texto);
        strcat(textoCompleto,textoParte2);
        delete[]texto;
        delete[]textoParte2;

        texto=textoCompleto;
    }

    comentario=new char*[2]{codUsuario,texto};

    return true;
}
void cargarEtiquetas(ifstream &archCom,char **&etiquetaComent) {
    char *buffer[10];
    int num=0;
    char *etiqueta;
    while (leerEtiqueta(archCom,etiqueta)) {
        buffer[num]=etiqueta;
        num++;
    }
    etiquetaComent=new char*[num+1]{};
    for (int i=0;i<num;i++) {
        etiquetaComent[i]=buffer[i];
    }
}
bool leerEtiqueta(ifstream &archCom,char *&etiqueta) {
    char buffer[20];
    int num=0;
    if (archCom.peek()==']') {
        archCom.get(); //consumir
        return false;
    }
    while (archCom.peek()!=' ' and archCom.peek()!=']') {
        buffer[num]=archCom.get();
        num++;
    }
    buffer[num]='\0';

    etiqueta=new char[num+1];
    strcpy(etiqueta,buffer);

    if (archCom.peek()==' ') {
        archCom.get();
    }
    return true;
}
//imprimirReporte
void imprimirReporte(const char *nombArch,char ***categorias,char ***streamers,int **fechasPromedios,long long **tiemposRepSegidores,
    char ***comentarios,char ***etiquetas) {
    for (int i=0;categorias[i];i++) {
        char **nombStreamer=categorias[i];
    }
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
