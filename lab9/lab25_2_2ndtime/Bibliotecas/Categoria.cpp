//
// Created by ANTONIO on 26/06/2026.
//

#include "Categoria.h"

Categoria::Categoria() = default;

Categoria::Categoria(const Categoria &origin) {
    *this = origin;
}

string Categoria::get_codigo() const {
    return codigo;
}
void Categoria::set_codigo(const string &codigo) {
    this->codigo = codigo;
}

string Categoria::get_nombrea() const {
    return nombrea;
}
void Categoria::set_nombrea(const string &nombrea) {
    this->nombrea = nombrea;
}

string Categoria::get_descripcion() const {
    return descripcion;
}
void Categoria::set_descripcion(const string &descripcion) {
    this->descripcion = descripcion;
}
//
ifstream& Categoria::leer(ifstream &arch) {
    string codigoCate,nombreaCate,descCate;

    getline(arch,codigoCate,',');
    getline(arch,nombreaCate,',');
    getline(arch,descCate);

    this->set_codigo(codigoCate);
    this->set_nombrea(nombreaCate);
    this->set_descripcion(descCate);

    return arch;
}
ofstream& Categoria::imprimir(ofstream &archRep) const {

    archRep<<"CODIGO: "<<this->get_codigo()<<endl;
    archRep<<"NOMBRE: "<<this->get_nombrea()<<endl;
    archRep<<"DESCRIPCION: "<<this->get_descripcion()<<endl;

    return archRep;
}
//
bool Categoria::operator<(const Categoria &other) const {
    return this->get_codigo()<other.get_codigo();
}
//destructor
Categoria::~Categoria()= default;
//
ifstream& operator>> (ifstream &arch, Categoria &categoria) {
    return categoria.leer(arch);
}
ofstream& operator<< (ofstream &archRep, Categoria &categoria) {
    return categoria.imprimir(archRep);
}
