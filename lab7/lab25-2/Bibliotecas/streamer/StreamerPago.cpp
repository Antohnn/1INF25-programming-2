//
// Created by ANTONIO on 11/06/2026.
//

#include <iostream>
using namespace std;
#include "StreamerPago.h"

StreamerPago::StreamerPago() {
    fecha_inicio_plan=0;
    metricas=nullptr;
    cantidad_metricas=0;
    capacidad_metricas=0;
}
StreamerPago::StreamerPago(const StreamerPago&origin) {
    *this=origin;
}

int StreamerPago::get_fecha_inicio_plan() const {
    return fecha_inicio_plan;
}
void StreamerPago::set_fecha_inicio_plan(int fecha_inicio_plan) {
    this->fecha_inicio_plan = fecha_inicio_plan;
}

int StreamerPago::get_cantidad_metricas() const {
    return cantidad_metricas;
}
void StreamerPago::set_cantidad_metricas(int cantidad_metricas) {
    this->cantidad_metricas = cantidad_metricas;
}

int StreamerPago::get_capacidad_metricas() const {
    return capacidad_metricas;
}
void StreamerPago::set_capacidad_metricas(int capacidad_metricas) {
    this->capacidad_metricas = capacidad_metricas;
}
//
ifstream& StreamerPago::leer(ifstream &arch) {
    if (!Streamer::leer(arch)) {
        return arch;
    }
    int fechaInicio,aa,mm,dd;
    char car;

    arch>>aa>>car>>mm>>car>>dd;
    fechaInicio=aa*10000+mm*100+dd;

    this->set_fecha_inicio_plan(fechaInicio);

    arch.ignore(100,'\n');
    return arch;
}
ofstream& StreamerPago::imprimir(ofstream &archRep) {
    Streamer::imprimir(archRep);
    archRep<<"StreamerPago"<<endl;
    archRep<<"BASICA"<<endl;
    for (int i=0;i<cantidad_metricas;i++) {
        if (metricas[i]->getTipo()==METRICA_BASICA) {
            archRep<<metricas[i];
        }
    }
    archRep<<"ENGAGE"<<endl;
    for (int i=0;i<cantidad_metricas;i++) {
        if (metricas[i]->getTipo()==METRICA_ENGAGE) {
            archRep<<metricas[i];
        }
    }
    archRep<<"CALIDAD"<<endl;
    for (int i=0;i<cantidad_metricas;i++) {
        if (metricas[i]->getTipo()==METRICA_CALIDAD) {
            archRep<<metricas[i];
        }
    }
    return archRep;
}
//
TipoStreamer StreamerPago::getTipoStreamer() const {
    return STREAMER_PAGO;
}
//
void StreamerPago::agregar_metrica(Metrica *metrica) {
    if (cantidad_metricas==capacidad_metricas) {
        incrementarMetricas();
    }
    metricas[cantidad_metricas++]=metrica;
}
void StreamerPago::incrementarMetricas() {
    capacidad_metricas+=5;
    Metrica **aux=new Metrica*[capacidad_metricas];
    for(int i=0;i<cantidad_metricas;i++) {
        aux[i]=metricas[i];
    }
    delete []metricas;
    metricas=aux;
}
//
StreamerPago::~StreamerPago() {
    delete [] metricas;
}
