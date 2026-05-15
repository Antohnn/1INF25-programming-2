//
// Created by ANTONIO on 14/05/2026.
//
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "Infraccion.h"

using namespace std;

#include "MinisterioDeTransporte.h"

#define TAM_LINEA 180

MinisterioDeTransporte::MinisterioDeTransporte() {
    infracciones=nullptr;
    numInf=0;
    numEmp=0;
}
MinisterioDeTransporte::~MinisterioDeTransporte() {
    delete[] infracciones;
}
double MinisterioDeTransporte::buscarMultaEnInfra(int condInfra) {
    for (int i=0;i<numInf;i++) {
        if (infracciones[i].get_codigo()==condInfra) {
            return infracciones[i].get_multa();
        }
    }
    return -1;
}
int MinisterioDeTransporte::buscarEmpresaPorPlaca(char *pl) {
    char placa[9];
    for (int i=0;i<numEmp;i++) {
        for (int j=0;j<empresas[i].get_num_placas();j++) {
            empresas[i].getPlacaI(placa,j);
            if (strcmp(pl,placa)==0) return i;
        }
    }
    return -1;
}
MinisterioDeTransporte& MinisterioDeTransporte::operator<(const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR AL ABRIR"<<nombArch<<endl;
        exit(1);
    }
    Infraccion infraccion[150];
    numInf=0;

    while (true) {
        arch>>infraccion[numInf];
        if (arch.eof()) break;
        numInf++;
    }
    infracciones=new Infraccion[numInf];
    for (int i=0;i<numInf;i++) {
        infracciones[i]=infraccion[i];
    }
    return *this;
}
MinisterioDeTransporte& MinisterioDeTransporte::operator<=(const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR AL ABRIR"<<nombArch<<endl;
        exit(1);
    }

    Empresa emp;
    while (true) {
        arch>>empresas[numEmp];
        if (arch.eof()) break;
        numEmp++;
    }

    return *this;
}

MinisterioDeTransporte& MinisterioDeTransporte::operator<<=(const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR AL ABRIR"<<nombArch<<endl;
        exit(1);
    }
   Multa multa;
    int idEmpresa;
    char pl[9];
    while (true) {
        arch>>multa;
        if (arch.eof()) break;
        multa.set_multa(buscarMultaEnInfra(multa.get_codigo_infraccion()));
        multa.get_placa(pl);
        idEmpresa=buscarEmpresaPorPlaca(pl);
        empresas[idEmpresa]+=multa;
    }
    return *this;
}
MinisterioDeTransporte& MinisterioDeTransporte::operator>>(const char*nombArch) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR AL ABRIR"<<nombArch<<endl;
        exit(1);
    }
    imprimeHeader(arch);
    for (int i=0;i<numInf;i++) {
        arch<<infracciones[i];
    }
    imprimirHeaderEmp(arch);
    for (int i=0;i<numEmp;i++) {
        arch<<empresas[i];
    }
    return *this;
}
void MinisterioDeTransporte::imprimeHeader(ofstream &arch) {
    arch<<setw(60)<<"MINISTERIO DE TRANSPORTE"<<endl;
    imprimirCaracter(arch,TAM_LINEA,'=');
    arch<<setw(60)<<"TABLA DE INFRACCIONES"<<endl;
    imprimirCaracter(arch,TAM_LINEA,'-');
    arch<<setw(20)<<"CODIGO"<<setw(20)<<"MULTA"<<setw(20)<<"GRAVEDAD"<<setw(20)<<"DESCRIPCION"<<endl;
    imprimirCaracter(arch,TAM_LINEA,'-');
}
void MinisterioDeTransporte::imprimirCaracter(ofstream &arch,int n,char car) {
    for (int i=0;i<n;i++) {
        arch<<car;
    }
    arch<<endl;
}
void MinisterioDeTransporte::imprimirHeaderEmp(ofstream &arch) {
    imprimirCaracter(arch,TAM_LINEA,'=');
    arch<<setw(80)<<"RELACION DE EMPRESAS CON INFRACCIONES DE TRANSITO"<<endl;
    imprimirCaracter(arch,TAM_LINEA,'-');
    arch<<setw(15)<<"DNI"<<setw(30)<<"NOMBRE"<<setw(50)<<"PLACAS DE SUS VEHICULOS"<<endl;
    imprimirCaracter(arch,TAM_LINEA,'-');

}
