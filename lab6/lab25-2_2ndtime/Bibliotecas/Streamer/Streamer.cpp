//
// Created by ANTONIO on 4/06/2026.
//

#include <cstring>
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
//
void Streamer::copiarCadena(char *&destino,char *origin) {
    delete [] destino;
    destino=new char[strlen(origin)+1];
    strcpy(destino,origin);
}
void Streamer::imprimirCaracter(ofstream &archRep,int n,char car) {
    for(int i=0;i<n;i++) {
        archRep<<car;
    }
    archRep<<endl;
}
//
ifstream& Streamer::leer(ifstream &arch) {
    int idStreamer,numSeguidores;
    char cuentaStreamer[100],cateStreamer[100];

    if (arch>>idStreamer) {
        arch.get();
        arch.getline(cuentaStreamer,100,',');
        arch.getline(cateStreamer,100,',');
        arch>>numSeguidores;
        arch.get();

        this->set_id(idStreamer);
        this->set_cuenta(cuentaStreamer);
        this->set_n_seguidores(numSeguidores);
        this->set_categoria(cateStreamer);
    }
    return arch;
}
ofstream& Streamer::imprimir(ofstream &archRep) {
    archRep<<"[ST]CUENTA: "<<this->get_cuenta()<<"|SEGUIDORES: "<<this->get_n_seguidores()
        <<"|CATEGORIA: "<<this->get_categoria();

    return archRep;
}
//operador asignacion
Streamer& Streamer::operator=(const Streamer &origin) {
    if (this != &origin) {
        this->set_id(origin.get_id());
        this->set_cuenta(origin.get_cuenta());
        this->set_n_seguidores(origin.get_n_seguidores());
        this->set_categoria(origin.get_categoria());
    }
    return *this;
}
//destructor
Streamer::~Streamer() {
    delete [] cuenta;
    delete [] categoria;
}
//
ifstream& operator>> (ifstream &arch,Streamer &streamer) {
    return streamer.leer(arch);
}
ofstream& operator<< (ofstream &archRep,Streamer &streamer) {
    return streamer.imprimir(archRep);
}