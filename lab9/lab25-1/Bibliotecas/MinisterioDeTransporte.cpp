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
    while (true) {
        arch>>dni;
        if (arch.eof()) break;
        arch.get();
        arch>>nuevo;
        insertarVehiculo(dni,nuevo);
    }
}
void MinisterioDeTransporte::insertarVehiculo(int dni,Vehiculo &vehiculo) {
    for (auto itEmp=listaEmpresas.begin();itEmp!=listaEmpresas.end();itEmp++) {
        if (itEmp->get_dni()==dni) {
            itEmp->agregarVehiculo(vehiculo);
            return;
        }
    }
}
void MinisterioDeTransporte::cargaInfraccionesCometidas(const char *nombArch) {
    ifstream arch(nombArch, ios::in);
    Multa nuevo;
    while (arch>>nuevo) {
        insertarMontoEnMulta(nuevo);
        insertarMulta(nuevo);
    }
    ordenarEmpresaMultas();
}
void MinisterioDeTransporte::insertarMontoEnMulta(Multa &multa) {
    for (auto itInfra=tablaInfracciones.begin();itInfra!=tablaInfracciones.end();itInfra++) {
        if (itInfra->get_codigo()==multa.get_cod_multa()) {
            multa.set_multa(itInfra->get_multa());
            return;
        }
    }
}
void MinisterioDeTransporte::insertarMulta(Multa &multa) {
    for (auto itEmp=listaEmpresas.begin();itEmp!=listaEmpresas.end();itEmp++) {
        if (itEmp->tieneVehiculo(multa.get_placa())) {
            itEmp->agregarMulta(multa);
            return;
        }
    }
}
void MinisterioDeTransporte::ordenarEmpresaMultas() {
    for (auto itEmp=listaEmpresas.begin();itEmp!=listaEmpresas.end();itEmp++) {
        itEmp->ordenarMultas();
    }
}
void MinisterioDeTransporte::reporteDeEmpresasConInfracciones(const char *nombArch) {
    ofstream archRep(nombArch, ios::out);
    archRep<<fixed<<setprecision(2);
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
