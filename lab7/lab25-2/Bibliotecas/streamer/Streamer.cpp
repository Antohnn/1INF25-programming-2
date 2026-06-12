//
// Created by ANTONIO on 11/06/2026.
//

#include <cstring>
#include <iostream>
using namespace std;
#include "Streamer.h"
#include "../Metrica.h"

Streamer::Streamer() {
    id=0;
    cuenta=nullptr;
    n_seguidores=0;
    categoria=nullptr;
}
Streamer::Streamer(const Streamer &origin) {
    *this=origin;
}
//setters and getters
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
ifstream& Streamer::leer(ifstream &arch) {
    int idStreamer,numSeguidores;
    char cuentaStreamer[100],categoriaStreamer[100];

    if (arch>>idStreamer) {
        arch.get();
        arch.getline(cuentaStreamer,100,',');
        arch.getline(categoriaStreamer,100,',');
        arch>>numSeguidores;
        arch.get();

        this->set_id(idStreamer);
        this->set_cuenta(cuentaStreamer);
        this->set_n_seguidores(numSeguidores);
        this->set_categoria(categoriaStreamer);
    }
    return arch;
}
ofstream& Streamer::imprimir(ofstream &archRep) {
    archRep<<this->get_cuenta()<<" "<<this->get_n_seguidores()<<" "<<this->get_categoria();

    return archRep;
}
//
void Streamer::copiarCadena(char *&destino,char*origen) {
    delete [] destino;
    destino = new char[strlen(origen)+1];
    strcpy(destino,origen);
}
//operador de asignacion
Streamer& Streamer::operator=(const Streamer &origin) {
    if (this != &origin) {
        this->set_id(origin.get_id());
        this->set_cuenta(origin.get_cuenta());
        this->set_n_seguidores(origin.get_n_seguidores());
        this->set_categoria(origin.get_categoria());
    }
    return *this;
}
//
Streamer::~Streamer() {
    delete [] cuenta;
    delete [] categoria;
}
//
ifstream& operator>> (ifstream &arch, Streamer &streamer) {
    return streamer.leer(arch);
}
ofstream& operator<< (ofstream &arch, Streamer &streamer) {
    return streamer.imprimir(arch);
}
