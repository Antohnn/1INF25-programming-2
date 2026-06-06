//
// Created by ANTONIO on 4/06/2026.
//

#include <iostream>
using namespace std;
#include "MetricaCalidad.h"

MetricaCalidad::MetricaCalidad() {
    bitrate_promedio_kbps=0;
    porcentaje_frames_perdidos=0;
    fps_promedio=0;
}
MetricaCalidad::MetricaCalidad(const MetricaCalidad &origin):MetricaCalidad() {
    *this=origin;
}
//setters and getters
int MetricaCalidad::get_bitrate_promedio_kbps() const {
    return bitrate_promedio_kbps;
}
void MetricaCalidad::set_bitrate_promedio_kbps(int bitrate_promedio_kbps) {
    this->bitrate_promedio_kbps = bitrate_promedio_kbps;
}

double MetricaCalidad::get_porcentaje_frames_perdidos() const {
    return porcentaje_frames_perdidos;
}
void MetricaCalidad::set_porcentaje_frames_perdidos(double porcentaje_frames_perdidos) {
    this->porcentaje_frames_perdidos = porcentaje_frames_perdidos;
}

int MetricaCalidad::get_fps_promedio() const {
    return fps_promedio;
}
void MetricaCalidad::set_fps_promedio(int fps_promedio) {
    this->fps_promedio = fps_promedio;
}
//
ifstream& MetricaCalidad::leer(ifstream &arch) {
    if (!Metrica::leer(arch)) {
        return arch;
    }
    int bitrateProm,fpsProm;
    double porcentajeFrame;
    char car;
    arch>>bitrateProm>>car>>porcentajeFrame>>car>>fpsProm;

    this->set_bitrate_promedio_kbps(bitrateProm);
    this->set_porcentaje_frames_perdidos(porcentajeFrame);
    this->set_fps_promedio(fpsProm);
    arch.ignore(200,'\n');

    return arch;
}
ofstream& MetricaCalidad::imprimir(ofstream &archRep) {
    archRep<<"MC-";
    Metrica::imprimir(archRep);
    archRep<<this->get_bitrate_promedio_kbps()<<" "<<this->get_porcentaje_frames_perdidos()<<" "
        <<this->get_fps_promedio();
    imprimirDescripcion(archRep);
    return archRep;
}
//operador asignacion
MetricaCalidad& MetricaCalidad::operator= (const MetricaCalidad &origin) {
    if (this!=&origin) {
        Metrica::operator=(origin);
        this->set_bitrate_promedio_kbps(origin.get_bitrate_promedio_kbps());
        this->set_porcentaje_frames_perdidos(origin.get_porcentaje_frames_perdidos());
        this->set_fps_promedio(origin.get_fps_promedio());
    }
    return *this;
}

//destructor
MetricaCalidad::~MetricaCalidad()=default;
//
ifstream& operator>> (ifstream &arch, MetricaCalidad &metricaCalidad) {
    return metricaCalidad.leer(arch);
}
ofstream& operator<< (ofstream &archRep, MetricaCalidad &metricaCalidad) {
    return metricaCalidad.imprimir(archRep);
}