//
// Created by ANTONIO on 11/06/2026.
//

#include <iostream>
using namespace std;
#include "StreamerGratuito.h"

StreamerGratuito::StreamerGratuito() {
    fecha_fin_trial=0;
    metricas_basicas=nullptr;
    cantidad_metricas_basicas=0;
    capacidad_metricas_basicas=0;
}
StreamerGratuito::StreamerGratuito(const StreamerGratuito &origin) {
    *this = origin;
}

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

int StreamerGratuito::get_capacidad_metricas_basicas() const {
    return capacidad_metricas_basicas;
}
void StreamerGratuito::set_capacidad_metricas_basicas(int capacidad_metricas_basicas) {
    this->capacidad_metricas_basicas = capacidad_metricas_basicas;
}
//
ifstream& StreamerGratuito::leer(ifstream &arch) {
    if (!Streamer::leer(arch)) {
        return arch;
    }
    int fechaFinTrial,aa,mm,dd;
    char c;
    arch>>aa>>c>>mm>>c>>dd;
    fechaFinTrial=aa*10000+mm*100+dd;

    this->set_fecha_fin_trial(fechaFinTrial);

    arch.ignore(100,'\n');
    return arch;
}
ofstream& StreamerGratuito::imprimir(ofstream &archRep) {
    Streamer::imprimir(archRep);
    archRep<<"StreamerGratuito"<<endl;
    for (int i=0;i<cantidad_metricas_basicas;i++) {
        archRep<<*metricas_basicas[i]<<endl;
    }
    return archRep;
}
//
TipoStreamer StreamerGratuito::getTipoStreamer() const  {
    return STREAMER_GRATIS;
}
//
void StreamerGratuito::agregar_metrica(Metrica *metrica) {
    if (metrica->getTipo()!=METRICA_BASICA) {
        return;
    }
    if (cantidad_metricas_basicas==capacidad_metricas_basicas) {
        incremetarMetricas();
    }
    metricas_basicas[cantidad_metricas_basicas++]=metrica;
}
//
void StreamerGratuito::incremetarMetricas() {
    capacidad_metricas_basicas+=5;
    Metrica **aux=new Metrica*[capacidad_metricas_basicas];
    for (int i=0;i<cantidad_metricas_basicas;i++) {
        aux[i]=metricas_basicas[i];
    }
    delete [] metricas_basicas;
    metricas_basicas=aux;
}

StreamerGratuito::~StreamerGratuito() {
    delete [] metricas_basicas;
}
