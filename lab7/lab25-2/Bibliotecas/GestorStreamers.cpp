//
// Created by ANTONIO on 11/06/2026.
//

#include <cstring>
#include <iostream>

#include "MetricaCalidad.h"
#include "MetricaEngagement.h"
#include "streamer/StreamerGratuito.h"
#include "streamer/StreamerPago.h"
#include "streamer/Streamer.h"
using namespace std;
#include "GestorStreamers.h"

GestorStreamers::GestorStreamers() {
    streamers=nullptr;
    cantidad_streamers=0;
    capacidad_streamers=0;
}
GestorStreamers::GestorStreamers(const GestorStreamers &origin) {
    *this=origin;
}

int GestorStreamers::get_cantidad_streamers() const {
    return cantidad_streamers;
}
void GestorStreamers::set_cantidad_streamers(int cantidad_streamers) {
    this->cantidad_streamers = cantidad_streamers;
}

int GestorStreamers::get_capacidad_streamers() const {
    return capacidad_streamers;
}
void GestorStreamers::set_capacidad_streamers(int capacidad_streamers) {
    this->capacidad_streamers = capacidad_streamers;
}

void GestorStreamers::cargar_datos_streamers(const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    char cateStreamer[100];
    while(true) {
        Streamer *nuevo=nullptr;
        arch.getline(cateStreamer,100,',');
        if (arch.eof()) break;
        if (strcmp(cateStreamer,"Gratuito")==0) nuevo=new StreamerGratuito();
        else if (strcmp(cateStreamer,"Pagado")==0) nuevo=new StreamerPago();
        if (nuevo and arch>>*nuevo) {
            if (cantidad_streamers==capacidad_streamers) {
                incrementarCapacidad();
            }
            streamers[cantidad_streamers++]=nuevo;
        }else delete nuevo;
    }
}
//
void GestorStreamers::incrementarCapacidad() {
    capacidad_streamers+=5;
    Streamer **aux=new Streamer*[capacidad_streamers];
    for (int i=0;i<cantidad_streamers;i++) {
        aux[i]=streamers[i];
    }
    delete [] streamers;
    streamers=aux;
}
void GestorStreamers::actualizar_datos_metricas(const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    int idStreamer,posStreamer;
    char cateMetrica[100],car;
    while (true) {
        Metrica *nuevo=nullptr;
        arch.getline(cateMetrica,100,',');
        if (arch.eof()) break;
        arch>>idStreamer>>car;
        if (strcmp(cateMetrica,"ENGAGEMENT")==0) nuevo= new MetricaEngagement();
        else if (strcmp(cateMetrica,"BASIC")==0) nuevo= new MetricaBasica();
        else if (strcmp(cateMetrica,"QUALITY")==0) nuevo= new MetricaCalidad();
        if (nuevo and arch>>*nuevo) {
            posStreamer=buscarStreamer(idStreamer);
            if (posStreamer!=-1) {
                streamers[posStreamer]->agregar_metrica(nuevo);
            }else delete nuevo;
        }else delete nuevo;
    }
}
int GestorStreamers::buscarStreamer(int idStreamer) {
    for (int i=0;i<cantidad_streamers;i++) {
        if (streamers[i]->get_id()==idStreamer) {
            return i;
        }
    }
    return -1;
}