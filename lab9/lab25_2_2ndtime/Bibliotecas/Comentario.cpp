//
// Created by ANTONIO on 26/06/2026.
//

#include "Comentario.h"

Comentario::Comentario() =default;
Comentario::Comentario(const string &origin) {
    *this=origin;
}

string Comentario::get_canal() const {
    return canal;
}
void Comentario::set_canal(const string &canal) {
    this->canal = canal;
}

string Comentario::get_descripcion() const {
    return descripcion;
}
void Comentario::set_descripcion(const string &descripcion) {
    this->descripcion = descripcion;
}
//
ifstream& Comentario::leer(ifstream &arch) {
    string canalComent,descComent;

    getline(arch,canalComent,',');
    getline(arch,descComent);

    this->set_canal(canalComent);
    this->set_descripcion(descComent);

    return arch;
}
ofstream& Comentario::imprimir(ofstream &archRep) {
    archRep<<this->get_descripcion()<<endl;
    return archRep;
}
//
bool Comentario::operator<(const Comentario &other)const {
    return this->get_canal() < other.get_canal();
}
//destructor
Comentario::~Comentario() = default;

ifstream& operator>> (ifstream &arch, Comentario &comentario) {
    return comentario.leer(arch);
}
ofstream& operator<< (ofstream &archRep, Comentario &comentario) {
    return comentario.imprimir(archRep);
}