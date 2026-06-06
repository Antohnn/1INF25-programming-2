//
// Created by ANTONIO on 2/06/2026.
//

#include <iostream>

using namespace std;

#include "StreamerPago.h"

StreamerPago::StreamerPago() {
    fecha_inicio_plan=0;
    metricas_basicas=nullptr;
    cantidad_metricas_basicas=0;
    metricas_engagements=nullptr;
    cantidad_metricas_engagement=0;
    metricas_calidades=nullptr;
    cantidad_metricas_calidades=0;
}
StreamerPago::StreamerPago(const StreamerPago &origin):StreamerPago() {
    *this=origin;
}

int StreamerPago::get_fecha_inicio_plan() const {
    return fecha_inicio_plan;
}
void StreamerPago::set_fecha_inicio_plan(int fecha_inicio_plan) {
    this->fecha_inicio_plan = fecha_inicio_plan;
}

int StreamerPago::get_cantidad_metricas_basicas() const {
    return cantidad_metricas_basicas;
}
void StreamerPago::set_cantidad_metricas_basicas(int cantidad_metricas_basicas) {
    this->cantidad_metricas_basicas = cantidad_metricas_basicas;
}

int StreamerPago::get_cantidad_metricas_engagement() const {
    return cantidad_metricas_engagement;
}
void StreamerPago::set_cantidad_metricas_engagement(int cantidad_metricas_engagement) {
    this->cantidad_metricas_engagement = cantidad_metricas_engagement;
}

int StreamerPago::get_cantidad_metricas_calidades() const {
    return cantidad_metricas_calidades;
}
void StreamerPago::set_cantidad_metricas_calidades(int cantidad_metricas_calidades) {
    this->cantidad_metricas_calidades = cantidad_metricas_calidades;
}

ifstream& StreamerPago::leer(ifstream &arch) {
    if (!Streamer::leer(arch)) {
        return arch;
    }
    int aa,mm,dd,fechaInicio;
    char car;

    arch.get();
    arch>>aa>>car>>mm>>car>>dd;
    fechaInicio=aa*10000+mm*100+dd;

    this->set_fecha_inicio_plan(fechaInicio);
    arch.ignore(200,'\n');

    return arch;
}
ofstream& StreamerPago::imprimir(ofstream &archRep) {
    Streamer::imprimir(archRep);

    if (this->get_cantidad_metricas_basicas()>0) {
        for (int i=0;i<this->get_cantidad_metricas_basicas();i++) {
            metricas_basicas[i].imprimir(archRep);
        }
    }
    if (this->get_cantidad_metricas_engagement()>0) {
        for (int i=0;i<this->get_cantidad_metricas_engagement();i++) {
            metricas_engagements[i].imprimir(archRep);
        }
    }
    if (this->get_cantidad_metricas_calidades()>0) {
        for (int i=0;i<this->get_cantidad_metricas_calidades();i++) {
            metricas_calidades[i].imprimir(archRep);
        }
    }

    return archRep;
}
StreamerPago& StreamerPago::operator=(const StreamerPago &origin) {
    if (this!=&origin) {
        Streamer::operator=(origin);
        this->set_fecha_inicio_plan(origin.get_fecha_inicio_plan());
        asignarMetricas(origin);
        this->set_cantidad_metricas_basicas(origin.get_cantidad_metricas_basicas());
        this->set_cantidad_metricas_engagement(origin.get_cantidad_metricas_engagement());
        this->set_cantidad_metricas_calidades(origin.get_cantidad_metricas_calidades());
    }
    return *this;
}
void StreamerPago::asignarMetricas(const StreamerPago &origin) {
    delete [] metricas_basicas;
    delete [] metricas_engagements;
    delete [] metricas_calidades;

    if (origin.get_cantidad_metricas_basicas()>0) {
        metricas_basicas=new MetricaBasica[origin.get_cantidad_metricas_basicas()];
        for (int i=0;i<origin.get_cantidad_metricas_basicas();i++) {
            metricas_basicas[i]=origin.metricas_basicas[i];
        }
    }else metricas_basicas=nullptr;
    if (origin.get_cantidad_metricas_engagement()>0) {
        metricas_engagements=new MetricaEngagement[origin.get_cantidad_metricas_engagement()];
        for (int i=0;i<origin.get_cantidad_metricas_engagement();i++) {
            metricas_engagements[i]=origin.metricas_engagements[i];
        }
    }else metricas_engagements=nullptr;
    if (origin.get_cantidad_metricas_calidades()>0) {
        metricas_calidades=new MetricaCalidad[origin.get_cantidad_metricas_calidades()];
        for (int i=0;i<origin.get_cantidad_metricas_calidades();i++) {
            metricas_calidades[i]=origin.metricas_calidades[i];
        }
    }else metricas_calidades=nullptr;
}
void StreamerPago::agregar_metricas_basicas(MetricaBasica &metricaBasica) {
    MetricaBasica *aux=new MetricaBasica[cantidad_metricas_basicas+1];
    for (int i=0;i<cantidad_metricas_basicas;i++) {
        aux[i]=metricas_basicas[i];
    }
    aux[cantidad_metricas_basicas]=metricaBasica;
    delete [] metricas_basicas;
    metricas_basicas=aux;
    cantidad_metricas_basicas++;
}
void StreamerPago::agregar_metricas_engagement(MetricaEngagement &metricaEngagement) {
    MetricaEngagement *aux=new MetricaEngagement[cantidad_metricas_engagement+1];
    for (int i=0;i<cantidad_metricas_engagement;i++) {
        aux[i]=metricas_engagements[i];
    }
    aux[cantidad_metricas_engagement]=metricaEngagement;
    delete [] metricas_engagements;
    metricas_engagements=aux;
    cantidad_metricas_engagement++;
}
void StreamerPago::agregar_metricas_calidad(MetricaCalidad &metricaCalidad) {
    MetricaCalidad *aux=new MetricaCalidad[cantidad_metricas_calidades+1];
    for (int i=0;i<cantidad_metricas_calidades;i++) {
        aux[i]=metricas_calidades[i];
    }
    aux[cantidad_metricas_calidades]=metricaCalidad;
    delete [] metricas_calidades;
    metricas_calidades=aux;
    cantidad_metricas_calidades++;
}
StreamerPago::~StreamerPago() {
    delete [] metricas_basicas;
    delete [] metricas_engagements;
    delete [] metricas_calidades;
}

ifstream& operator>>(ifstream &arch, StreamerPago &streamerPago) {
    return streamerPago.leer(arch);
}
ofstream& operator<<(ofstream &archRep, StreamerPago &streamerPago) {
    return streamerPago.imprimir(archRep);
}
