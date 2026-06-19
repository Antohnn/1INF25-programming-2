//
// Created by ANTONIO on 14/06/2026.
//

#include <iostream>
using namespace std;
#include "MetricaBasica.h"

MetricaBasica::MetricaBasica() {
    horas_transmitidas=0;
    espectadores_promedio=0;
}
MetricaBasica::MetricaBasica(const MetricaBasica &origin):MetricaBasica() {
    *this=origin;
}

double MetricaBasica::get_horas_transmitidas() const {
    return horas_transmitidas;
}
void MetricaBasica::set_horas_transmitidas(double horas_transmitidas) {
    this->horas_transmitidas = horas_transmitidas;
}

int MetricaBasica::get_espectadores_promedio() const {
    return espectadores_promedio;
}
void MetricaBasica::set_espectadores_promedio(int espectadores_promedio) {
    this->espectadores_promedio = espectadores_promedio;
}
//
TipoMetrica MetricaBasica::getTipo() const {
    return BASICA;
}
//
ifstream& MetricaBasica::leer(ifstream &arch) {
    if (!Metrica::leer(arch)) {
        return arch;
    }
    double horasTransmitidas;
    int espectadoresPromedio;

    arch>>horasTransmitidas;
    arch.get();
    arch>>espectadoresPromedio;

    this->set_horas_transmitidas(horasTransmitidas);
    this->set_espectadores_promedio(espectadoresPromedio);

    arch.ignore(100,'\n');
    return arch;
}
ofstream& MetricaBasica::imprimir(ofstream &archRep) const {
    Metrica::imprimir(archRep);
    archRep<<this->get_horas_transmitidas()<<" "<<this->get_espectadores_promedio()<<"m"<<endl;
    return archRep;
}
//
MetricaBasica& MetricaBasica::operator=(const MetricaBasica &origin) {
    if (this != &origin) {
        Metrica::operator=(origin);
        this->set_horas_transmitidas(origin.get_horas_transmitidas());
        this->set_espectadores_promedio(origin.get_espectadores_promedio());
    }
    return *this;
}

//destructor
MetricaBasica::~MetricaBasica() = default;