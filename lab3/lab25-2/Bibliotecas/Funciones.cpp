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
//lectura del streamer
bool leerStreamer(ifstream &archStreamer,void *&streamer) {
    char *nombStreamer,*categoria,c;
    long long tiempoTot,segStreamer;
    int promSpec;

    nombStreamer=leerCadenaExacta(archStreamer,',');
    if (archStreamer.eof())return false;
    archStreamer>>tiempoTot>>c>>promSpec>>c>>segStreamer>>c;
    categoria=leerCadenaExacta(archStreamer,'\n');
    if (archStreamer.peek()=='\n') archStreamer.get();

    void **reg=new void*[streamerNumDatos]{};
    reg[streamerCuenta]=nombStreamer;
    reg[streamerSeg]=new long long(segStreamer);
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
//reporte simple
void reporteSimple(void *&streamers,void *&comentarios) {
    ofstream archReporteStreamer,archReporteComentario;
    abrirOut("ArchivosDeReporte/RepStreamer.txt",archReporteStreamer);
    abrirOut("ArchivosDeReporte/RepComentario.txt",archReporteComentario);
    const void **regStreamers = (const void **) streamers;
    const void **regComentarios= (const void**) comentarios;

    for (int i=0;regStreamers[i]!=nullptr; i++) {
        imprimirStreamer(archReporteStreamer,regStreamers[i]);
    }
    for (int i=0;regComentarios[i]!=nullptr; i++) {
        imprimirComentario(archReporteComentario,regComentarios[i]);
    }
}
void imprimirStreamer(ofstream &archReporteStreamer,const void *regStreamers) {
    void **datoStreamer=(void **)regStreamers;

    const char *nombStreamer=(const char*)datoStreamer[streamerCuenta];
    long long segundos=*(long long*)datoStreamer[streamerSeg];
    const char* cateStreamer=(const char*)datoStreamer[streamerCate];

    archReporteStreamer<<left<<setw(15)<<nombStreamer<<right<<setw(20)<<segundos<<' '<<left<<setw(20)<<cateStreamer<<right<<endl;
}
void imprimirComentario(ofstream &archReporteComentario,const void*regComentarios) {
    void** datoComent=(void**)regComentarios;

    const char* codComentario=(const char *)datoComent[comentCod];
    const char* emisor=(const char *)datoComent[comentEmi];
    const char* receptor=(const char *)datoComent[comentRecep];
    const char* texto=(const char *)datoComent[comentText];

    archReporteComentario<<left<<setw(20)<<codComentario<<setw(20)<<emisor<<setw(20)<<receptor<<setw(20)<<texto<<right<<endl;
}
//actualiza comentarios
void actualizacomentarios(void *&streamers,void *&comentarios) {
    void **regStreamers=(void **)streamers;
    void **regComentarios=(void **)comentarios;

    for (int i=0;regStreamers[i]!=nullptr; i++) {
        cargarComentario(regStreamers[i],regComentarios);
    }


}
void cargarComentario(void *regStreamers,void **regComentarios) {
    void **datoStreamer=(void **)regStreamers;
    char *nombStreamer=(char *)datoStreamer[streamerCuenta];
    int num=0,capacidad=0;
    void **listaComentarios=nullptr;

    for (int i=0;regComentarios[i]!=nullptr; i++) {
        void **datoComentarios=(void **)regComentarios[i];
        char *datoEmisor=(char *)datoComentarios[comentEmi];
        void *unComentStreamer;
        if (strcmp(datoEmisor,nombStreamer)==0) {
            if (num==capacidad) {
                incrementarRegistro(listaComentarios,num,capacidad);
            }
            crearComentarioNuevo(datoComentarios,unComentStreamer);
            listaComentarios[num++]=unComentStreamer;
        }
    }
    if (listaComentarios==nullptr) listaComentarios=new void*[1]{};
    else listaComentarios[num]=nullptr;
    datoStreamer[streamerComent]=listaComentarios;
}
void crearComentarioNuevo(void **datoComentarios,void *&unComentStreamer) {
    void **nuevo=new void*[2]{};

    copiarCadena((char *)datoComentarios[comentRecep],nuevo[0]);
    copiarCadena((char *)datoComentarios[comentText],nuevo[1]);

    unComentStreamer=nuevo;
}
void copiarCadena(char *cad,void *&nuevo) {
    char *cadena;
    cadena=new char[strlen(cad)+1];
    strcpy(cadena,cad);
    nuevo=cadena;
}
//reporteFinal
void imprimeStreamer(const void *streamers) {
    ofstream archRep;
    abrirOut("ArchivosDeReporte/Reporte.txt",archRep);
    const void **regStreamers=(const void**)streamers;
    for (int i=0;regStreamers[i];i++) {
        if (tieneComentarios(regStreamers[i])) {
            imprimirCaracter(archRep,'=',160);
            imprimirCuenta(regStreamers[i],archRep);
        }

    }
}
void imprimirCaracter(ofstream &archRep,char car,int tam) {
    for (int i=0;i<tam;i++) {
        archRep<<car;
    }
    archRep<<endl;
}
void imprimirCuenta(const void *regStreamers,ofstream &archRep) {
    const void **datoStreamer=(const void **)regStreamers;
    const char* nombStreamer=(const char *)datoStreamer[streamerCuenta];
    const long long seguidores=*(const long long*)datoStreamer[streamerSeg];
    archRep<<"Cuenta"<<setw(30)<<"Seguidores"<<endl;
    archRep<<left<<setw(20)<<nombStreamer<<setw(15)<<right<<seguidores<<endl;
    imprimirCaracter(archRep,'-',160);
    archRep<<"Comentarios emitidos: "<<endl;
    imprimirCaracter(archRep,'-',160);
    archRep<<"Receptor"<<setw(30)<<"Texto"<<endl;
    imprimirCaracter(archRep,'-',160);
    const void** regComentStreamer=(const void**)datoStreamer[streamerComent];
    for (int i=0;regComentStreamer[i];i++) {
        imprimirComentarioStreamer(regComentStreamer[i],archRep);
    }

}
void imprimirComentarioStreamer(const void *regComentStreamer,ofstream &archRep) {
    const void **datoComentStreamer=(const void**)regComentStreamer;
    const char *receptor=(const char *)datoComentStreamer[0];
    const char *texto=(const char *)datoComentStreamer[1];

    archRep<<left<<setw(30)<<receptor<<setw(60)<<texto<<endl;
}
bool tieneComentarios(const void *regStreamers) {
    const void **datoStreamer=(const void**)regStreamers;
    const void **regComentStreamer=(const void**)datoStreamer[streamerComent];
    if (regComentStreamer[0]==nullptr) return false;
    return true;
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
        cout<<"ERROR AL ABRIR ARCHIVO"<<nombArch<<endl;
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