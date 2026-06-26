//
// Created by ANTONIO on 24/06/2026.
//

#include "Infraccion.h"

Infraccion::Infraccion() {
    multa=0;
}
Infraccion::Infraccion(const Infraccion &origin):Infraccion() {
    *this=origin;
}

string Infraccion::get_codigo() const {
    return codigo;
}
void Infraccion::set_codigo(const string &codigo) {
    this->codigo = codigo;
}

double Infraccion::get_multa() const {
    return multa;
}
void Infraccion::set_multa(double multa) {
    this->multa = multa;
}

string Infraccion::get_gravedad() const {
    return gravedad;
}
void Infraccion::set_gravedad(const string &gravedad) {
    this->gravedad = gravedad;
}

string Infraccion::get_descripcion() const {
    return descripcion;
}
void Infraccion::set_descripcion(const string &descripcion) {
    this->descripcion = descripcion;
}
//
ifstream& Infraccion::leer(ifstream &arch) {
    string codigoInfra,gravedadInfra,descInfra;
    double multaInfra;
    char car;

    getline(arch,codigoInfra,',');
    arch>>multaInfra>>car;
    getline(arch,gravedadInfra,',');
    getline(arch,descInfra);

    this->set_codigo(codigoInfra);
    this->set_multa(multaInfra);
    this->set_gravedad(gravedadInfra);
    this->set_descripcion(descInfra);

    return arch;
}
ofstream& Infraccion::imprimir(ofstream &archRep) const {
    string codInfra=this->get_codigo();
    string numInfra=codInfra.substr(1,4);

    archRep<<" "<<numInfra<<" "<<this->get_multa()<<" ";
    return archRep;
}
//
Infraccion& Infraccion::operator=(const Infraccion &origin) {
    if (this!=&origin) {
        this->set_codigo(origin.get_codigo());
        this->set_multa(origin.get_multa());
        this->set_gravedad(origin.get_gravedad());
        this->set_descripcion(origin.get_descripcion());
    }
    return *this;
}
//
bool Infraccion::operator<(const Infraccion &origin) const {
    return this->get_codigo()<origin.get_codigo();
}

//destructor
Infraccion::~Infraccion() = default;

//
ifstream& operator>> (ifstream &arch, Infraccion &infraccion) {
    return infraccion.leer(arch);
}
ofstream& operator<< (ofstream &archRep, const Infraccion &infraccion) {
    return infraccion.imprimir(archRep);
}