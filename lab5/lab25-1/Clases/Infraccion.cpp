//
// Created by ANTONIO on 14/05/2026.
//
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

#include "Infraccion.h"

//constructor por defecto
Infraccion::Infraccion() {
    codigo=0;
    descripcion=nullptr;
    gravedad=nullptr;
    multa=0;
}
//constructor copia
Infraccion::Infraccion(const Infraccion &origin):Infraccion() {
    *this=origin;
}
//destructor
Infraccion::~Infraccion() {
    delete [] descripcion;
    delete [] gravedad;
}
//setters and getters
int Infraccion::get_codigo() const {
    return codigo;
}
void Infraccion::set_codigo(int codigo) {
    this->codigo = codigo;
}
void Infraccion::get_descripcion(char *desc) const {
    if (descripcion==nullptr) desc[0]='\0';
    else strcpy(desc,descripcion);
}
void Infraccion::set_descripcion(char *desc) {
    delete [] descripcion;
    descripcion=new char[strlen(desc)+1];
    strcpy(descripcion,desc);
}
void  Infraccion::get_gravedad(char *grav) const {
    if (gravedad==nullptr) grav[0]='\0';
    else strcpy(grav,gravedad);
}
void Infraccion::set_gravedad(char *gravedad) {
    delete [] this->gravedad;
    this->gravedad = new char[strlen(gravedad)+1];
    strcpy(this->gravedad,gravedad);
}
double Infraccion::get_multa() const {
    return multa;
}
void Infraccion::set_multa(double multa) {
    this->multa = multa;
}

//operador de asignacion
Infraccion &Infraccion::operator=(const Infraccion &origin) {
    if (this != &origin) {
        set_codigo(origin.codigo);
        set_descripcion(origin.descripcion);
        set_gravedad(origin.gravedad);
        set_multa(origin.multa);
    }
    return *this;
}
//sobrecargas
ifstream &operator>> (ifstream &arch, Infraccion &infraccion) {
    int codInfra;
    double multaInfra;
    char gravInfra[40],descrInfra[300],c;


    arch>>codInfra;
    if (arch.eof()) return arch;
    arch>>c>>multaInfra>>c;
    arch.getline(gravInfra,40,',');
    arch.getline(descrInfra,300);

    infraccion.set_codigo(codInfra);
    infraccion.set_descripcion(descrInfra);
    infraccion.set_gravedad(gravInfra);
    infraccion.set_multa(multaInfra);


    return arch;
}
ofstream &operator<< (ofstream &arch, Infraccion &infra) {
    char grav[30],descr[300];
    infra.get_gravedad(grav);
    infra.get_descripcion(descr);
    
    arch<<setprecision(2)<<fixed;
    arch<<infra.get_codigo()<<setw(10)<<infra.get_multa()<<left<<setw(20)<<grav<<setw(160)<<descr<<endl;
    return arch;
}

