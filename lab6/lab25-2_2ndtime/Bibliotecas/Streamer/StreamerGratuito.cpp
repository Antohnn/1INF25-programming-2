//
// Created by ANTONIO on 4/06/2026.
//
#include <iomanip>
#include <iostream>
using namespace std;
#include "StreamerGratuito.h"

StreamerGratuito::StreamerGratuito() {
    fecha_fin_trial=0,
    metricas_basicas=nullptr;
    cantidad_metricas_basicas=0;
}
StreamerGratuito::StreamerGratuito(const StreamerGratuito &origin):StreamerGratuito() {
    *this=origin;
}

//setters and getters
int StreamerGratuito::get_fecha_fin_trial() const {
    return fecha_fin_trial;
}
void StreamerGratuito::set_fecha_fin_trial(int fecha_fin_trial) {
    this->fecha_fin_trial = fecha_fin_trial;
}

int StreamerGratuito::get_cantidad_metricas_basicas() const {
    return cantidad_metricas_basicas;
}
void StreamerGratuito::set_cantidad_metricas_basicas(int cantidad_metricas_basicas) {
    this->cantidad_metricas_basicas = cantidad_metricas_basicas;
}
//
ifstream& StreamerGratuito::leer(ifstream &arch) {
    if (!Streamer::leer(arch)) {
        return arch;
    }
    int aa,mm,dd,fechaFin;
    char car;
    arch>>aa>>car>>mm>>car>>dd;
    fechaFin=aa*10000+mm*100+dd;

    this->set_fecha_fin_trial(fechaFin);
    arch.ignore(200,'\n');

    return arch;
}
ofstream& StreamerGratuito::imprimir(ofstream &archRep) {
    Streamer::imprimir(archRep);
    archRep<<" |TIPO: StreamerGratuito"<<endl;
    imprimirCaracter(archRep,160,'-');
    imprimirStatsMetricaBasica(archRep);
    imprimirMetricaBasica(archRep);

    return archRep;
}
//
void StreamerGratuito::imprimirMetricaBasica(ofstream &archRep) {
    for (int i=0;i<cantidad_metricas_basicas;i++) {
        archRep<<metricas_basicas[i];
    }
}
void StreamerGratuito::imprimirStatsMetricaBasica(ofstream &archRep) {
    int cantActivas=0,cantExpiradas=0,cant=0;
    double horasTotales=0,viewersPromTotal=0,viewersTotal=0;
    for (int i=0;i<cantidad_metricas_basicas;i++) {
        horasTotales+=metricas_basicas[i].get_horas_transmitidas();
        viewersTotal+=metricas_basicas[i].get_espectadores_promedio();
        if (!metricas_basicas[i].get_estado()) {
            cantExpiradas++;
        }else cantActivas++;
        cant++;
    }
    viewersPromTotal=viewersTotal/cant;
    archRep<<"[BASIC]HORAS_TOT: "<<horasTotales<<"|VIEWERS_PROM_GLOBAL: "<<viewersPromTotal
        <<"|ACTIVAS: "<<cantActivas<<"|EXPIRADAS: "<<cantExpiradas<<endl;
    archRep<<setw(20)<<"Codigo"<<setw(20)<<"Fecha Calc."<<setw(20)<<"Expira"<<setw(20)
        <<"Estado"<<setw(20)<<"Horas"<<setw(20)<<"Viewers"<<setw(20)<<"Descripcion"<<endl;
}
//destructor
StreamerGratuito::~StreamerGratuito() {
    delete [] metricas_basicas;
}
