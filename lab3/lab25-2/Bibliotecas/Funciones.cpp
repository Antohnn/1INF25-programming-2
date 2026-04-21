//
// Created by anton on 20/04/2026.
//
#include <chrono>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

#include "Funciones.h"
#include "enums.h"
// cuenta tiempoTot promSpec seguidores categoria
// Gaules,5644590915,10976,1767635,CY1025
//cargarStreamers
void cargarStreamers(void *&streamers) {
    ifstream archStreamer;
    abrirArch("ArchivosDeDatos/streamers.csv",archStreamer);
    void **registros=nullptr; //se define el void** que representa a los registros guardados en void *streamers
    int num=0,capacidad=0;
    void *streamer; // como sabemos el puntero void** va a "guardar" una serie de void*
    while (leerStreamer(archStreamer,streamer)) {
        if (num==capacidad) {
            incrementarRegistro(registros,num,capacidad);
        }
        registros[num++]=streamer;
    }
    if (registros==nullptr)registros =new void*[1]{};
    else registros[num]=nullptr;
    streamers=registros;
}
//lectura del paciente
bool leerStreamer(ifstream &archStreamer,void *&streamer) {
    char *nombStreamer,*categoria,c;
    long long tiempoTot;
    int promSpec,segStreamer;

    nombStreamer=leerCadenaExacta(archStreamer,',');
    if (archStreamer.eof())return false;
    archStreamer>>tiempoTot>>c>>promSpec>>c>>segStreamer>>c;
    categoria=leerCadenaExacta(archStreamer,'\n');
    if (archStreamer.peek()=='\n') archStreamer.get();

    void **reg=new void*[streamerNumDatos]{};
    reg[streamerCuenta]=nombStreamer;
    reg[streamerSeg]=new int(segStreamer);
    reg[streamerCate]=categoria;
    reg[streamerComent]=nullptr;

    streamer=reg;
    return true;
}
//cargarComentarios
void cargarComentarios(void *&comentarios) {
    ifstream archComent;
    abrirArch("ArchivosDeDatos/comentarios.csv",archComent);
    void **registros=nullptr;
    int num=0,capacidad=0;
    void *comentario;
    while (leerComentario(archComent,comentario)) {
        if (num==capacidad) {
            incrementarRegistro(registros,num,capacidad);
        }
        registros[num++]=comentario;
    }
    if (registros==nullptr) registros=new void*[1]{};
    else registros[num]=nullptr;
    comentarios=registros;
}
bool leerComentario(ifstream &archComent,void *&comentario) {
    char *codComent,*emisorComent,*recepComent,*textComent;
    codComent=leerCadenaExacta(archComent,',');
    if (archComent.eof())return false;
    textComent=leerCadenaExacta(archComent,'[');
    cargarHablantes(archComent,emisorComent,recepComent);
    archComent.get();

    void **reg=new void*[comentNumDatos]{};
    reg[comentCod]=codComent;
    reg[comentEmi]=emisorComent;
    reg[comentRecep]=recepComent;
    reg[comentText]=textComent;

    comentario=reg;
    return true;
}
void cargarHablantes(ifstream &archComent,char *&emisorComent,char *&recepComent) {
    int i=0,j=0;
    char auxEmi[60],auxRecep[60];
    bool primero=true;
    while (true) {
        if (archComent.peek()==']') {
            archComent.get();
            break;
        }
        if (archComent.peek()==' ') {
            archComent.get();
            primero=false;
        }
        while (archComent.peek()!=' ' and archComent.peek()!=']') {
            if (primero) {
                auxEmi[i++]=archComent.get();
            }else {
                auxRecep[j++]=archComent.get();
            }
        }
    }
    auxEmi[i]='\0',auxRecep[j]='\0';
    emisorComent=new char[strlen(auxEmi)+1];
    recepComent=new char[strlen(auxRecep)+1];
    strcpy(emisorComent,auxEmi),strcpy(recepComent,auxRecep);
}
void reporteSimple(void *&streamers,void *&comentarios) {
    ofstream archReporteStreamer;
    abrirOut("ArchivosDeReporte/RepStreamer.txt",archReporteStreamer);
    const void **regStreamers = (const void **) streamers;
    const void **regComentarios= (const void**) comentarios;

    for (int i=0;regStreamers[i]!=nullptr; i++) {
        imprimirStreamer(archReporteStreamer,regStreamers[i]);
    }
}
void imprimirStreamer(ofstream &archReporteStreamer,const void *regStreamers) {
    void **datoStreamer=(void **)regStreamers;
    const char *nombStreamer=(const char*)datoStreamer[streamerCuenta];
    long long segundos=*(long long*)datoStreamer[streamerSeg];
    const char* cateStreamer=(const char*)datoStreamer[streamerCate];

    archReporteStreamer<<nombStreamer<<setw(20)<<segundos<<setw(10)<<left<<setw(20)<<cateStreamer<<right<<endl;
}
//aux
void abrirArch(const char *nombArch,ifstream &arch) {
    arch.open(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR AL ABRIR EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
}
void abrirOut(const char *nombArch,ofstream &archRep) {
    archRep.open(nombArch,ios::out);
    if (not archRep.is_open()) {
        cout<<"ERROR AL ABRIR "<<nombArch<<endl;
        exit(1);
    }
}
char *leerCadenaExacta(ifstream &arch,char delim) {
    char aux[300],*cad;
    arch.getline(aux,300,delim);
    if (arch.eof())return nullptr;
    cad=new char[strlen(aux)+1];
    strcpy(cad,aux);
    return cad;
}
//metodo de aumento de memoria por incrementos
void incrementarRegistro(void **&registros,int num,int &capacidad) {
    capacidad+=5;
    if (registros==nullptr) {
        registros=new void *[capacidad+1]{};
    }else {
        void **aux=new void *[capacidad+1]{};
        for (int i=0;i<num;i++) {
            aux[i]=registros[i];
        }
        delete []registros;
        registros=aux;
    }
}