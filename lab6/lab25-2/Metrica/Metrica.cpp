//
// Created by ANTONIO on 28/05/2026.
//
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "../Metrica/Metrica.h"

Metrica::Metrica() {
    id=0;
    descripcion=nullptr;
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

char * Metrica::get_descripcion() const {
    return descripcion;
}
void Metrica::set_descripcion(char *descripcion) {
    copiarCadena(this->descripcion, descripcion);
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


ifstream& Metrica::leer(ifstream &arch) {
    int idMet;
    char *descMet,car;
    int fechaCalculoMet,dd,mm,aa;
    int fechaExpiracionMet,ddE,mmE,aaE;

    if (arch>>idMet) {
        arch.get();
        descMet=leerCadena(arch,',');
        arch>>aa>>car>>mm>>car>>dd>>car>>aaE>>car>>mmE>>car>>ddE;
        fechaCalculoMet=aa*10000+mm*100+dd;
        fechaExpiracionMet=aaE*10000+mmE*100+ddE;

        this->set_id(idMet);
        this->set_descripcion(descMet);
        this->set_fecha_calculo(fechaCalculoMet);
        this->set_fecha_expiracion(fechaExpiracionMet);
        if (20251105 > fechaExpiracionMet) {
            this->set_estado(false);
        }

        delete [] descMet;
    }

    return arch;
}
ofstream& Metrica::imprimir(ofstream &archRep) {
    archRep<<this->get_fecha_calculo()<<setw(11)<<this->get_fecha_expiracion()<<" ";
    if (this->get_estado()) {
        archRep<<"ACTIVADA";
    }else {
        archRep<<"EXPIRADA";
    }

    return archRep;
}
void Metrica::imprimirDescripcion(ofstream &archRep) {
    archRep<<this->get_descripcion()<<endl;
}

//metedos utiles
void Metrica::copiarCadena(char *&destino,char *origen) {
    delete [] destino;
    if (origen) {
        destino=new char[strlen(origen)+1];
        strcpy(destino,origen);
    }else {
        destino=nullptr;
    }
}
char *Metrica::leerCadena(ifstream &arch,char delim) {
    char aux[300],*cad;
    arch.getline(aux,300,delim);
    cad=new char[strlen(aux)+1];
    strcpy(cad,aux);
    return cad;
}
//operador de asignacion
Metrica& Metrica::operator=(const Metrica &origin) {
    if(this!=&origin) {
        this->set_id(origin.get_id());
        this->set_descripcion(origin.get_descripcion());
        this->set_fecha_calculo(origin.get_fecha_calculo());
        this->set_fecha_expiracion(origin.get_fecha_expiracion());
        this->set_estado(origin.get_estado());
    }
    return *this;
}

Metrica::~Metrica() {
    delete [] descripcion;

    cout<<"se utilizo el operador de destruccion"<<endl;
}

//sobrecargas de operadores

ifstream& operator>> (ifstream &arch, Metrica &metrica) {
    return metrica.leer(arch);
}
ofstream& operator<< (ofstream &archRep, Metrica &metrica) {
    return metrica.imprimir(archRep);
}

