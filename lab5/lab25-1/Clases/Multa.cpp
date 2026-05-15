//
// Created by ANTONIO on 14/05/2026.
//
#include <chrono>
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

#include "Multa.h"

//constructor por defecto
Multa::Multa() {
    placa=nullptr;
    fechaDeInfraccion=0;
    fechaDePago=0;
    codigoInfraccion=0;
    multa=0;
}
//constructor copia
Multa::Multa(const Multa &origin):Multa() {
    *this=origin;
}
//destructor
Multa::~Multa() {
    delete [] placa;
}

//setters and getters
void Multa::get_placa(char *plac) const {
    if (placa==nullptr) plac[0]=0;
    else strcpy(plac,placa);
}
void Multa::set_placa(char *placa) {
    delete [] this->placa;
    this->placa = new char[strlen(placa)+1];
    strcpy(this->placa,placa);
}
int Multa::get_fecha_de_infraccion() const {
    return fechaDeInfraccion;
}
void Multa::set_fecha_de_infraccion(int fecha_de_infraccion) {
    fechaDeInfraccion = fecha_de_infraccion;
}
int Multa::get_fecha_de_pago() const {
    return fechaDePago;
}
void Multa::set_fecha_de_pago(int fecha_de_pago) {
    fechaDePago = fecha_de_pago;
}
int Multa::get_codigo_infraccion() const {
    return codigoInfraccion;
}
void Multa::set_codigo_infraccion(int codigo_infraccion) {
    codigoInfraccion = codigo_infraccion;
}
double Multa::get_multa() const {
    return multa;
}
void Multa::set_multa(double multa) {
    this->multa = multa;
}
//operador de asignacion
Multa &Multa::operator=(const Multa &origin) {
    if (this != &origin) {
        set_placa(origin.placa);
        set_fecha_de_infraccion(origin.fechaDeInfraccion);
        set_fecha_de_pago(origin.fechaDePago);
        set_codigo_infraccion(origin.codigoInfraccion);
        set_multa(origin.multa);
    }
    return *this;
}
//sobrecarga
ifstream &operator>> (ifstream &arch, Multa &multa) {
    int dd,mm,aa,ddP,mmP,aaP,codInfra,fechaInfra,fechaPago;
    char placa[9],hayPago,c;

    arch>>dd;
    if (arch.eof())return arch;
    arch>>c>>mm>>c>>aa>>c;
    arch.getline(placa,9,',');
    arch>>codInfra;
    if (arch.get()!='\n') {
        arch>>hayPago>>c>>ddP>>c>>mmP>>c>>aaP;
        fechaPago=aaP*10000+mmP*100+ddP;
    }fechaPago=0;
    fechaInfra=aa*10000+mm*100+dd;

    multa.set_placa(placa);
    multa.set_fecha_de_infraccion(fechaInfra);
    multa.set_fecha_de_pago(fechaPago);
    multa.set_codigo_infraccion(codInfra);
    multa.set_multa(multa);



    return arch;
}
