//
// Created by ANTONIO on 21/06/2026.
//

#include "Categoria.h"
Categoria::Categoria() {
    codigo="";
    nombrea="";
    descripcion="";
}
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
    string codCate,nombCate,descrCate;
    getline(arch,codCate,',');
    getline(arch,nombCate,',');
    getline(arch,descrCate);

    this->set_codigo(codCate);
    this->set_nombrea(nombCate);
    this->set_descripcion(descrCate);

    return arch;
}
ofstream& Categoria::imprimir(ofstream &archRep) {
    archRep<<"CODIGO: "<<this->get_codigo()<<endl;
    archRep<<"NOMBRE: "<<this->get_nombrea()<<endl;
    archRep<<"DESCRIPCION: "<<this->get_descripcion()<<endl;

    return archRep;
}

//
bool Categoria::operator<(const Categoria &cate) const {
    return this->get_codigo()<cate.get_codigo();
}
//
Categoria &Categoria::operator=(const Categoria &origin) {
    if (this!=&origin) {
        this->set_codigo(origin.get_codigo());
        this->set_nombrea(origin.get_nombrea());
        this->set_descripcion(origin.get_descripcion());
    }
    return *this;
}
//destructor
Categoria::~Categoria() =default;
//
ifstream& operator>> (ifstream &arch, Categoria &categoria) {
    return categoria.leer(arch);
}
ofstream& operator<< (ofstream &archRep, Categoria &categoria) {
    return categoria.imprimir(archRep);
}
