//
// Created by ANTONIO on 25/06/2026.
//

#ifndef LAB25_1_MINISTERIODETRANSPORTE_H
#define LAB25_1_MINISTERIODETRANSPORTE_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>

#include "Empresa.h"
#include "Infraccion.h"
using namespace std;

class MinisterioDeTransporte {
    list<Infraccion> tablaInfracciones;
    list<Empresa> listaEmpresas;

    Empresa *buscarEmpresa(int );
    void insetarEnMulta(Multa &);
    Empresa  *insertarMultaEnEmpresa(Multa &nuevo);
    void ordenarEmpresaMultas();
public:
    void cargaDeInfracciones(const char *);
    void cargaEmpresas(const char *);
    void cargaVehiculos(const char *);
    void cargaInfraccionesCometidas(const char *);
    void reporteDeEmpresasConInfracciones(const char *);
    void eliminaInfraccionesPagadas();
};


#endif //LAB25_1_MINISTERIODETRANSPORTE_H
