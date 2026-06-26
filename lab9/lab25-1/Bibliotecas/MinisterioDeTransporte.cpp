//
// Created by ANTONIO on 25/06/2026.
//

#include "MinisterioDeTransporte.h"

void MinisterioDeTransporte::cargaDeInfracciones(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    Infraccion nuevo;

    while (arch>>nuevo) {
        tablaInfracciones.push_back(nuevo);
    }
    tablaInfracciones.sort();
}
void MinisterioDeTransporte::cargaEmpresas(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    Empresa nuevo;
    while (arch>>nuevo) {
        listaEmpresas.push_back(nuevo);
    }
    listaEmpresas.sort();
}
void MinisterioDeTransporte::cargaVehiculos(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    Vehiculo nuevo;
    int dni;
    Empresa *empresaEncontrada;
    while (true) {
        arch>>dni;
        if (arch.eof()) break;
        arch.get();
        arch>>nuevo;
        empresaEncontrada=buscarEmpresa(dni);
        if (empresaEncontrada!=nullptr) {
            empresaEncontrada->agregarVehiculo(nuevo);
        }
    }
}
Empresa *MinisterioDeTransporte::buscarEmpresa(int dni) {
    for (auto it=listaEmpresas.begin();it!=listaEmpresas.end();it++) {
        if (it->get_dni()==dni) return &(*it);
    }
    return nullptr;
}
void MinisterioDeTransporte::cargaInfraccionesCometidas(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    Multa nuevo;
    Empresa *empresaEncontrada;
    while (arch>>nuevo) {
        insetarEnMulta(nuevo);
        empresaEncontrada=insertarMultaEnEmpresa(nuevo);
        if (empresaEncontrada!=nullptr) {
            empresaEncontrada->agregarMulta(nuevo);
        }
    }
    ordenarEmpresaMultas();
}
void MinisterioDeTransporte::ordenarEmpresaMultas() {
    for (auto itEmp=listaEmpresas.begin();itEmp!=listaEmpresas.end();itEmp++) {
        itEmp->ordenarMultas();
    }
}
void MinisterioDeTransporte::insetarEnMulta(Multa &nuevo) {
    for (auto itInf=tablaInfracciones.begin();itInf!=tablaInfracciones.end();itInf++) {
        if (itInf->get_codigo()==nuevo.get_cod_multa()) {
            nuevo.set_multa(itInf->get_multa());
        }
    }
}
Empresa  *MinisterioDeTransporte::insertarMultaEnEmpresa(Multa &nuevo) {
    for (auto itEmp=listaEmpresas.begin();itEmp!=listaEmpresas.end();itEmp++) {
        if (itEmp->tieneVehiculo(nuevo.get_placa())) {
            return &(*itEmp);
        }
    }
    return nullptr;
}
void MinisterioDeTransporte::reporteDeEmpresasConInfracciones(const char *nombArch) {
    ofstream archRep(nombArch, ios::out);

    archRep<<string(120,'=')<<endl;
    archRep<<setw(70)<<"RELACION DE EMPRESAS CON INFRACCIONES DE TRANSITO"<<endl;
    archRep<<string(120,'-')<<endl;
    for (auto it=listaEmpresas.begin();it!=listaEmpresas.end();it++) {
        archRep<<*it;
        archRep<<string(120,'=')<<endl;
    }
}
void MinisterioDeTransporte::eliminaInfraccionesPagadas() {
    for (auto itEmp=listaEmpresas.begin();itEmp!=listaEmpresas.end();itEmp++) {
        itEmp->eliminaInfraccionesPagadas();
    }
}
