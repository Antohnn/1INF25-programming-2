//
// Created by ANTONIO on 17/06/2026.
//

#include <iostream>

#include "Metrica/MetricaBasica.h"
#include "Metrica/MetricaCalidad.h"
#include "Metrica/MetricaEngagement.h"
using namespace std;
#include "AdministrarMetricas.h"

void AdministrarMetricas::cargarArchivo(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    int idStream;
    char car;
    string tipoMetrica;



    while (true) {
        Metrica *nuevo=nullptr;
        getline(arch,tipoMetrica,',');
        if (arch.eof()) break;
        arch>>idStream>>car;
        if (tipoMetrica=="BASIC") {
            nuevo=new MetricaBasica();
        }else if (tipoMetrica=="QUALITY") {
            nuevo=new MetricaCalidad();
        }else if (tipoMetrica=="ENGAGEMENT") {
            nuevo=new MetricaEngagement();
        }
        if (nuevo!=nullptr) {
            nuevo->leer(arch);
            listaDeMetricas.insertar(nuevo);
        }


    }
}
