//
// Created by ANTONIO on 14/05/2026.
//
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

#include "Empresa.h"

//constructor por defecto
Empresa::Empresa() {
    dni=0;
    nombre=nullptr;
    for (int i=0;i<10;i++) {
        placas[i]=nullptr;
    }
    numPlacas=0;
    numMultas=0;
}
//destructor
Empresa::~Empresa() {
    delete [] nombre;
    for (int i=0;i<10;i++) {
        delete [] placas[i];
    }
}
//setters and getters
int Empresa::get_dni() const {
    return dni;
}
void Empresa::set_dni(int dni) {
    this->dni = dni;
}
void Empresa::get_nombre(char *nomb) const {
    if (nombre==nullptr) nomb[0]='\0';
    else strcpy(nomb,nombre);
}
void Empresa::set_nombre(char *nombre) {
    delete [] this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}
int Empresa::get_num_placas() const {
    return numPlacas;
}
void Empresa::set_num_placas(int num_placas) {
    numPlacas = num_placas;
}
int Empresa::get_num_multas() const {
    return numMultas;
}
void Empresa::set_num_multas(int num_multas) {
    numMultas = num_multas;
}

void  Empresa::setPlacaI(const char *placa,int i) {
    if (placas[i]) delete [] placas[i];
    placas[i]=new char[strlen(placa)+1];
    strcpy(placas[i],placa);

}
void Empresa::getPlacaI(char *placa,int i)const  {
    if (placas[i]==nullptr) placa[0]='\0';
    else strcpy(placa,placas[i]);
}
Empresa& Empresa::operator+= (Multa& multa) {
    multas[numMultas]=multa;
    numMultas++;
    return *this;
}
void Empresa::imprime(ofstream &arch) {
    arch<<dni<<" "<<left<<setw(60)<<nombre<<' ';
    for (int i=0;i<numPlacas;i++) {
        arch<<placas[i]<<' ';
    }
    arch<<endl;
    for (int i=0;i<numMultas;i++) {
        arch<<multas[i]<<endl;
    }
}
//sobrecarga
ifstream &operator>>(ifstream &arch,Empresa &empresa) {
    int dniEmpresa,n=0;
    char nombDueEmp[60],placa[9],c;

    arch>>dniEmpresa;
    if (arch.eof())return arch;
    arch>>c;
    arch.getline(nombDueEmp,60,',');
    empresa.set_dni(dniEmpresa);
    empresa.set_nombre(nombDueEmp);
    empresa.set_num_placas(0);

    while (true) {
        arch.get(placa,9);
        empresa.setPlacaI(placa,n);
        n++;
        if (arch.get()=='\n') break;
    }
    empresa.set_num_placas(n);

    return arch;
}
ofstream &operator<<(ofstream &arch,Empresa &empresa) {
    empresa.imprime(arch);
    return arch;
}
