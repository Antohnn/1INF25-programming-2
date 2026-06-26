//
// Created by ANTONIO on 25/06/2026.
//

#include "Empresa.h"

#include <algorithm>

Empresa::Empresa() {
    dni=0;
}
Empresa::Empresa(const Empresa &origin):Empresa() {
    *this = origin;
}

int Empresa::get_dni() const {
    return dni;
}
void Empresa::set_dni(int dni) {
    this->dni = dni;
}

string Empresa::get_nombre() const {
    return nombre;
}
void Empresa::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

string Empresa::get_distrito() const {
    return distrito;
}
void Empresa::set_distrito(const string &distrito) {
    this->distrito = distrito;
}

void Empresa::agregarVehiculo(Vehiculo &vehiculo) {
    vehiculos[vehiculo.get_placa()]= vehiculo;
}
void Empresa::agregarMulta(Multa &multa) {
    multasRecibidas.push_back(multa);
}
//
ifstream& Empresa::leer(ifstream &arch) {
    int dniEmpresa;
    char car;
    string nombreEmpresa,distritoEmpresa;

    arch>>dniEmpresa>>car;
    getline(arch,nombreEmpresa,',');
    getline(arch,distritoEmpresa);

    this->set_dni(dniEmpresa);
    this->set_nombre(nombreEmpresa);
    this->set_distrito(distritoEmpresa);

    return arch;
}
ofstream& Empresa::imprimir(ofstream &archRep) {
    archRep<<this->get_dni()<<" "<<this->get_nombre()<<" "<<this->get_distrito()<<endl;

    archRep<<"VEHICULOS DE LA EMPRESA:"<<endl;
    for (auto itVeh=vehiculos.begin();itVeh!=vehiculos.end();itVeh++) {
        archRep<<itVeh->second;
    }
    archRep<<string(120,'-')<<endl;
    archRep<<"MULTAS IMPUESTAS "<<endl;
    for (auto itMul=multasRecibidas.begin();itMul!=multasRecibidas.end();itMul++) {
        archRep<<*itMul;
    }
    return archRep;
}
//
bool Empresa::operator<(const Empresa &other) {
    return this->get_dni() < other.get_dni();
}
bool Empresa::tieneVehiculo(const string &placa) {
    map<string,Vehiculo>::iterator itVeh;
    itVeh=vehiculos.find(placa);
    if (itVeh!=vehiculos.end()) {
        return true;
    }
    return false;
}
void Empresa::ordenarMultas() {
    sort(multasRecibidas.begin(),multasRecibidas.end());
}
void Empresa::eliminaInfraccionesPagadas() {
    vector<Multa>::iterator itMulta;
    itMulta=multasRecibidas.begin();
    while (itMulta!=multasRecibidas.end()) {
        if (itMulta->is_pagado()) {
            multasRecibidas.erase(itMulta);
        }else {
            itMulta++;
        }
    }
}
//destructor
Empresa::~Empresa() =default;
//
ifstream& operator>>(ifstream &arch, Empresa &empresa) {
    return empresa.leer(arch);
}
ofstream& operator<<(ofstream &archRep, Empresa &empresa) {
    return empresa.imprimir(archRep);
}
