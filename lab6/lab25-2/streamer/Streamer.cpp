//
// Created by ANTONIO on 2/06/2026.
//
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Streamer.h"


Streamer::Streamer() {
    id=0;
    cuenta=nullptr;
    n_seguidores=0;
    categoria=nullptr;
}
Streamer::Streamer(const Streamer &origin):Streamer() {
    *this=origin;
}

int Streamer::get_id() const {
    return id;
}
void Streamer::set_id(int id) {
    this->id = id;
}

char * Streamer::get_cuenta() const {
    return cuenta;
}
void Streamer::set_cuenta(char *cuenta) {
    copiarCadena(this->cuenta,cuenta);
}

int Streamer::get_n_seguidores() const {
    return n_seguidores;
}
void Streamer::set_n_seguidores(int n_seguidores) {
    this->n_seguidores = n_seguidores;
}

char * Streamer::get_categoria() const {
    return categoria;
}
void Streamer::set_categoria(char *categoria) {
    copiarCadena(this->categoria,categoria);
}


void Streamer::copiarCadena(char *&destino,char *origen) {
    delete [] destino;
    if (origen) {
        destino = new char[strlen(origen)+1];
        strcpy(destino,origen);
    }else {
        destino=nullptr;
    }
}
char * Streamer::leerCadena(ifstream &arch,char delim) {
    char aux[300],*cad;
    arch.getline(aux,300,delim);
    cad=new char[strlen(aux)+1];
    strcpy(cad,aux);
    return cad;
}

ifstream &Streamer::leer(ifstream &arch) {
    int idStreamer,nSeguidores;
    char *cuentaStreamer,*categoriaStreamer;

    if (arch>>idStreamer) {
        arch.get();
        cuentaStreamer=leerCadena(arch,',');
        categoriaStreamer=leerCadena(arch,',');
        arch>>nSeguidores;

        this->set_id(idStreamer);
        this->set_cuenta(cuentaStreamer);
        this->set_n_seguidores(nSeguidores);
        this->set_categoria(categoriaStreamer);


        delete [] cuentaStreamer;
        delete [] categoriaStreamer;
    }
    return arch;
}

ofstream &Streamer::imprimir(ofstream &archRep) {
    archRep<<"[ST] CUENTA: "<<left<<setw(30)<<this->get_cuenta()<<setw(15)<<"|SEGUIDORES: "<<this->get_n_seguidores()
    <<"|CATEGORIA: "<<this->get_categoria();

    return archRep;
}



Streamer& Streamer::operator=(const Streamer &origin) {
    if (this != &origin) {
        this->set_id(origin.get_id());
        this->set_cuenta(origin.get_cuenta());
        this->set_n_seguidores(origin.get_n_seguidores());
        this->set_categoria(origin.get_categoria());
    }
    return *this;
}

Streamer::~Streamer() {
    delete [] cuenta;
    delete [] categoria;
}

ifstream &operator>> (ifstream &arch,Streamer &streamer) {
    return streamer.leer(arch);
}
ofstream &operator<< (ofstream &archRep,Streamer &streamer) {
    return streamer.imprimir(archRep);
}
