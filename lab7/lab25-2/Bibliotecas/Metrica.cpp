//
// Created by ANTONIO on 10/06/2026.
//

#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;
#include "Metrica.h"

Metrica::Metrica() {
    id=0;
    descripcion=nullptr;
    fecha_calculo=0;
    fecha_expiracion=0;
    estado=false;
}
Metrica::Metrica(const Metrica& origin):Metrica() {
    *this=origin;
}
// setters and getters
int Metrica::get_id() const {
    return id;
}
void Metrica::set_id(int id) {
    this->id = id;
}

char * Metrica::get_descripcion() const {
    return descripcion;
}
void Metrica::set_descripcion(char *descripcion) {
    copiarCadena(this->descripcion,descripcion);
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
    int metricaId,aa,mm,dd,aaE,mmE,ddE,fechaCalculo,fechaExpiracion;
    char descripcionMetrica[100],c;

    if (arch>>metricaId) {
        arch.get();
        arch.getline(descripcionMetrica,100,',');
        arch>>aa>>c>>mm>>c>>dd>>c>>aaE>>c>>mmE>>c>>ddE;
        fechaCalculo=aa*10000+mm*100+dd;
        fechaExpiracion=aaE*10000+mmE*100+ddE;
        arch.get();

        this->set_id(metricaId);
        this->set_descripcion(descripcionMetrica);
        this->set_fecha_calculo(fechaCalculo);
        this->set_fecha_expiracion(fechaExpiracion);
        if (fechaExpiracion<20251112) {
            this->set_estado(true);
        }
    }
    return arch;
}
ofstream& Metrica::imprimir(ofstream &archRep) {
    archRep<<"-"<<setfill('0')<<setw(4)<<this->get_id()<<setfill(' ')<<' '
        <<this->get_fecha_calculo()<<' '<<this->get_fecha_expiracion()<<' ';
    if (this->get_estado()) {
        archRep<<"ACTIVA";
    }else archRep<<"EXPIRADA";
    archRep<<' ';

    return archRep;
}
void Metrica::imprimirDescripcion(ofstream &archRep) {
    archRep<<" "<<this->get_descripcion()<<endl;
}
//
void Metrica::copiarCadena(char *&destino,char *origen) {
    delete [] destino;
    destino = new char[strlen(origen)+1];
    strcpy(destino,origen);
}
//
Metrica& Metrica::operator = (const Metrica &origin) {
    if (this != &origin) {
        this->set_id(origin.get_id());
        this->set_descripcion(origin.get_descripcion());
        this->set_fecha_calculo(origin.get_fecha_calculo());
        this->set_fecha_expiracion(origin.get_fecha_expiracion());
        this->set_estado(origin.get_estado());
    }
    return *this;
}
//destructor
Metrica::~Metrica() {
    delete [] descripcion;
}
//
ifstream& operator >> (ifstream &arch, Metrica &metrica) {
    return metrica.leer(arch);
}
ofstream& operator << (ofstream &archRep, Metrica &metrica) {
    return metrica.imprimir(archRep);
}
