//
// Created by ANTONIO on 25/06/2026.
//

#include "Vehiculo.h"

Vehiculo::Vehiculo() = default;

Vehiculo::Vehiculo(const Vehiculo &origin) {
    *this = origin;
}

string Vehiculo::get_placa() const {
    return placa;
}
void Vehiculo::set_placa(const string &placa) {
    this->placa = placa;
}

string Vehiculo::get_marca() const {
    return marca;
}
void Vehiculo::set_marca(const string &marca) {
    this->marca = marca;
}

string Vehiculo::get_modelo() const {
    return modelo;
}
void Vehiculo::set_modelo(const string &modelo) {
    this->modelo = modelo;
}
//
ifstream& Vehiculo::leer(ifstream &arch) {
    string placaVehiculo,marcaVehiculo,modelVehiculo;

    getline(arch,placaVehiculo,',');
    getline(arch,marcaVehiculo,',');
    getline(arch,modelVehiculo);

    this->set_placa(placaVehiculo);
    this->set_marca(marcaVehiculo);
    this->set_modelo(modelVehiculo);

    return arch;
}
ofstream& Vehiculo::imprimir(ofstream &archRep) const {
    archRep<<this->get_placa()<<" "<<this->get_marca()<<" "<<this->get_modelo()<<endl;
    return archRep;
}
//
Vehiculo& Vehiculo::operator= (const Vehiculo &origin) {
    if (this!=&origin) {
        this->set_placa(origin.get_placa());
        this->set_marca(origin.get_marca());
        this->set_modelo(origin.get_modelo());
    }
    return *this;
}

//destructor
Vehiculo::~Vehiculo() = default;
//
ifstream& operator>> (ifstream &arch, Vehiculo &vehiculo) {
    return vehiculo.leer(arch);
}
ofstream& operator<< (ofstream &archRep, const Vehiculo &vehiculo) {
    return vehiculo.imprimir(archRep);
}