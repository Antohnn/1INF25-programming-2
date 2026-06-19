//
// Created by ANTONIO on 18/06/2026.
//

#include <iomanip>
#include <iostream>
using namespace std;
#include "Metrica.h"

Metrica::Metrica() {
    id=0;
    descripcion="";
    fecha_calculo=0;
    fecha_expiracion=0;
    estado=true;
}
Metrica::Metrica(const Metrica &origin):Metrica() {
    *this=origin;
}

int Metrica::get_id() const {
    return id;
}
void Metrica::set_id(int id) {
    this->id = id;
}

string Metrica::get_descripcion() const {
    return descripcion;
}
void Metrica::set_descripcion(const string &descripcion) {
    this->descripcion = descripcion;
}

int Metrica::get_fecha_calculo() const {
    return fecha_calculo;
}
void Metrica::set_fecha_calculo(int fecha_calculo) {
    this->fecha_calculo = fecha_calculo;
}

int Metrica::get_fecha_expiracion() const {
    return fecha_expiracion;
}
void Metrica::set_fecha_expiracion(int fecha_expiracion) {
    this->fecha_expiracion = fecha_expiracion;
}

bool Metrica::get_estado() const {
    return estado;
}
void Metrica::set_estado(bool estado) {
    this->estado = estado;
}
//
ifstream& Metrica::leer(ifstream &arch) {
    int idMetrica,aa,mm,dd,aaE,mmE,ddE,fechaCalculo,fechaExpiracion;
    char car;
    string descripcionMetrica;

    if (arch>>idMetrica) {
        arch.get();
        getline(arch,descripcionMetrica,',');
        arch>>aa>>car>>mm>>car>>dd>>car>>aaE>>car>>mmE>>car>>ddE>>car;
        fechaCalculo=aa*10000+mm*100+dd;
        fechaExpiracion=aaE*10000+mmE*100+ddE;

        this->set_id(idMetrica);
        this->set_descripcion(descripcionMetrica);
        this->set_fecha_calculo(fechaCalculo);
        this->set_fecha_expiracion(fechaExpiracion);
        if (fechaExpiracion<20251130) {
            this->set_estado(false);
        }
    }
    return arch;
}
ofstream& Metrica::imprimir(ofstream &archRep) {
    archRep<<"-"<<setfill('0')<<setw(4)<<this->get_id()<<setfill(' ')<<" "<<this->get_descripcion()
        <<" "<<this->get_fecha_calculo()<<" "<<this->get_fecha_expiracion();
    if (this->get_estado()) {
        archRep<<"ACTIVA";
    }else archRep<<"EXPIRADA";
    archRep<<" ";
    return archRep;
}
//
Metrica &Metrica::operator=(const Metrica &origin) {
    if (this != &origin) {
        this->set_id(origin.get_id());
        this->set_descripcion(origin.get_descripcion());
        this->set_fecha_calculo(origin.get_fecha_calculo());
        this->set_fecha_expiracion(origin.get_fecha_expiracion());
        this->set_estado(origin.get_estado());
    }
    return *this;
}

Metrica::~Metrica() =default;

