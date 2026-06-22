//
// Created by ANTONIO on 21/06/2026.
//

#include "Etiqueta.h"
Etiqueta::Etiqueta() {
    codigo="";
    nombre="";
}
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
    getline(arch,codEtiqueta,',');
    getline(arch,nombEtiqueta);
    return arch;
}
ofstream& Etiqueta::imprimir(ofstream &archRep) {
    archRep<<left<<setw(20)<<"CODIGO: "<<this->get_codigo()<<setw(20)<<"NOMBRE: "<<this->get_nombre()<<endl;
    return archRep;
}
//
Etiqueta &Etiqueta::operator=(const Etiqueta &origin) {
    if (this!=&origin) {
        this->set_codigo(origin.get_codigo());
        this->set_nombre(origin.get_nombre());
    }
    return *this;
}
//destructor
Etiqueta::~Etiqueta() =default;
//
ifstream& operator>>(ifstream &arch, Etiqueta &etiqueta) {
    return etiqueta.leer(arch);
}
ofstream& operator<<(ofstream &archRep, Etiqueta &etiqueta) {
    return etiqueta.imprimir(archRep);
}
