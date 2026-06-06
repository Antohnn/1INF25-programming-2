//
// Created by ANTONIO on 2/06/2026.
//

#include <iostream>

using namespace std;

#include "StreamerGratuito.h"

StreamerGratuito::StreamerGratuito() {
    fecha_fin_trial=0;
    metricas_basicas=nullptr;
    cantidad_metricas_basicas=0;
}
StreamerGratuito::StreamerGratuito(const StreamerGratuito &origin):StreamerGratuito() {
    *this=origin;
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

StreamerGratuito& StreamerGratuito::operator=(const StreamerGratuito &origin) {
    if (this != &origin) {
        Streamer::operator=(origin);
        this->set_fecha_fin_trial(origin.get_fecha_fin_trial());
        delete [] metricas_basicas;
        if (origin.get_cantidad_metricas_basicas()>0) {
            metricas_basicas=new MetricaBasica[origin.get_cantidad_metricas_basicas()];

            for (int i=0;i<origin.get_cantidad_metricas_basicas();i++) {
                metricas_basicas[i]=origin.metricas_basicas[i];
            }
        }else {
            metricas_basicas=nullptr;
        }
        this->set_cantidad_metricas_basicas(origin.get_cantidad_metricas_basicas());
    }
    return *this;
}

ifstream& StreamerGratuito::leer(ifstream &arch) {
    if (!Streamer::leer(arch)) {
        return arch;
    }

    int fechaFin,aa,mm,dd;
    char car;

    arch.get();
    arch>>aa>>car>>mm>>car>>dd;
    fechaFin=aa*10000+mm*100+dd;

    this->set_fecha_fin_trial(fechaFin);
    arch.ignore(200,'\n');

    return arch;
}
ofstream& StreamerGratuito::imprimir(ofstream &archRep) {
    Streamer::imprimir(archRep);

    if (this->get_cantidad_metricas_basicas()>0) {
        for (int i=0;i<this->get_cantidad_metricas_basicas();i++) {
            metricas_basicas[i].imprimir(archRep);
        }
    }
    return archRep;
}
void StreamerGratuito::agregar_metricas_basicas(MetricaBasica &metricaBasica) {
    MetricaBasica *aux=new MetricaBasica[cantidad_metricas_basicas+1];
    for (int i=0;i<cantidad_metricas_basicas;i++) {
        aux[i]=metricas_basicas[i];
    }
    aux[cantidad_metricas_basicas]=metricaBasica;

    delete [] metricas_basicas;
    metricas_basicas=aux;
    cantidad_metricas_basicas++;
}
StreamerGratuito::~StreamerGratuito() {
    delete [] metricas_basicas;
}
ifstream& operator>> (ifstream &arch, StreamerGratuito &streamerGratuito) {
    return streamerGratuito.leer(arch);
}
ofstream& operator<< (ofstream &archRep, StreamerGratuito &streamerGratuito) {
    return streamerGratuito.imprimir(archRep);
}


