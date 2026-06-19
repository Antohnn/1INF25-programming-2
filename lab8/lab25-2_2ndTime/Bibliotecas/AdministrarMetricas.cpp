//
// Created by ANTONIO on 19/06/2026.
//

#include <iostream>

#include "Metrica/MetricaBasica.h"
#include "Metrica/MetricaCalidad.h"
#include "Metrica/MetricaEgagement.h"
using namespace std;
#include "AdministrarMetricas.h"

void AdministrarMetricas::cargarArchivo(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    string tipoMetrica;
    int idStreamer;
    char car;
    while (true) {
        Metrica *nuevo=nullptr;
        getline(arch,tipoMetrica,',');
        if (arch.eof()) break;
        arch>>idStreamer>>car;
        if (tipoMetrica=="BASIC") {
            nuevo=new MetricaBasica();
        }else if (tipoMetrica=="QUALITY") {
            nuevo=new MetricaCalidad();
        }else if (tipoMetrica=="ENGAGEMENT") {
            nuevo=new MetricaEgagement();
        }
        if (nuevo!=nullptr) {
            nuevo->leer(arch);
            listaDeMetricas.insertarOrdenado(nuevo);
        }
    }
}
void AdministrarMetricas::generarReporte(const char *nombArch) {
    ofstream arch(nombArch,ios::out);

    listaDeMetricas.imprimir(arch);
}
void AdministrarMetricas::eliminarNodos() {
    listaDeMetricas.eliminarExpiradas();
}
