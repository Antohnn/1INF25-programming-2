//
// Created by ANTONIO on 25/06/2026.
//

#include "Etiqueta.h"

Etiqueta::Etiqueta() = default;

Etiqueta::Etiqueta(const Etiqueta &origin) {
    *this = origin;
}

string Etiqueta::get_codigo() const {
    return codigo;
}
void Etiqueta::set_codigo(const string &codigo) {
    this->codigo = codigo;
}

string Etiqueta::get_nombre() const {
    return nombre;
}
void Etiqueta::set_nombre(const string &nombre) {
    this->nombre = nombre;
}
//
ifstream& Etiqueta::leer(ifstream &arch) {
    string codEtiqueta,nombEtiqueta;

    getline(arch, codEtiqueta,',');
    getline(arch, nombEtiqueta);

    this->set_codigo(codEtiqueta);
    this->set_nombre(nombEtiqueta);

    return arch;
}
ofstream& Etiqueta::imprimir(ofstream &archRep) const {
    archRep<<"CODIGO: "<<this->get_codigo()<<" "<<"NOMBRE: "<<this->get_nombre()<<endl;
    return archRep;
}
//destructor
Etiqueta::~Etiqueta() = default;
//
ifstream& operator>> (ifstream &arch, Etiqueta &etiqueta) {
    return etiqueta.leer(arch);
}
ofstream& operator<< (ofstream &archRep, Etiqueta &etiqueta) {
    return etiqueta.imprimir(archRep);
}