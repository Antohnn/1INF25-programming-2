//
// Created by ANTONIO on 3/06/2026.
//

#include <iostream>

using namespace std;

#include "GestorStreamers.h"

GestorStreamers::GestorStreamers() {
    streamers_gratuitos=nullptr;
    streamers_pago=nullptr;
    cantidad_gratuitos=0;
    cantidad_pagados=0;
}
GestorStreamers::GestorStreamers(const GestorStreamers &origin):GestorStreamers() {
    *this=origin;
}

int GestorStreamers::get_cantidad_gratuitos() const {
    return cantidad_gratuitos;
}
void GestorStreamers::set_cantidad_gratuitos(int cantidad_gratuitos) {
    this->cantidad_gratuitos = cantidad_gratuitos;
}

int GestorStreamers::get_cantidad_pagados() const {
    return cantidad_pagados;
}
void GestorStreamers::set_cantidad_pagados(int cantidad_pagados) {
    this->cantidad_pagados = cantidad_pagados;
}

GestorStreamers& GestorStreamers::operator=(const GestorStreamers &origin) {
    if (this != &origin) {
        this->set_cantidad_gratuitos(origin.get_cantidad_gratuitos());
        this->set_cantidad_pagados(origin.get_cantidad_pagados());
        asignarStreamer(origin);
    }
    return *this;
}
void GestorStreamers::asignarStreamer(const GestorStreamers &origin) {
    delete [] streamers_gratuitos;
    delete [] streamers_pago;

    if (origin.get_cantidad_gratuitos() > 0) {
        streamers_gratuitos=new StreamerGratuito[cantidad_gratuitos];
        for (int i = 0; i < origin.get_cantidad_gratuitos(); i++) {
            streamers_gratuitos[i] = origin.streamers_gratuitos[i];
        }
    }else streamers_gratuitos=nullptr;

    if (origin.get_cantidad_pagados() > 0) {
        streamers_pago=new StreamerPago[cantidad_pagados];
        for (int i = 0; i < origin.get_cantidad_pagados(); i++) {
            streamers_pago[i] = origin.streamers_pago[i];
        }
    }else streamers_pago=nullptr;
}
void GestorStreamers::cargar_datos_streamers(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    char tipoStreamer[300];
    StreamerGratuito streamersGratuito[200];
    StreamerPago streamersPago[200];
    int cantGratuitos=0,cantPagos=0;
    while (true) {
        arch.getline(tipoStreamer,300,',');
        if (arch.eof()) break;
        if (strcmp(tipoStreamer,"Gratuito")==0) {
            arch>>streamersGratuito[cantGratuitos];
            cantGratuitos++;
        }else {
            arch>>streamersPago[cantPagos];
            cantPagos++;
        }
    }
    asignarStreamers(streamersGratuito,streamersPago,cantGratuitos,cantPagos);
}
void GestorStreamers::asignarStreamers(StreamerGratuito *streamersGratuito,StreamerPago *streamersPago,
        int cantGratuitos,int cantPagos) {
    delete [] streamers_gratuitos;
    delete [] streamers_pago;
    streamers_gratuitos=new StreamerGratuito[cantGratuitos];
    for (int i = 0; i < cantGratuitos; i++) {
        streamers_gratuitos[i] = streamersGratuito[i];
    }
    streamers_pago=new StreamerPago[cantPagos];
    for (int i = 0; i < cantPagos; i++) {
        streamers_pago[i] = streamersPago[i];
    }
    cantidad_gratuitos=cantGratuitos;
    cantidad_pagados=cantPagos;
}

void GestorStreamers::actualizar_datos_metricas(const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    int id_streamer,posStreamer;
    char tipoMetrica[200],car,tipoStreamer;
    MetricaBasica metricaBasica;
    MetricaEngagement metricaEngagement;
    MetricaCalidad metricaCalidad;

    while (true) {
        arch.getline(tipoMetrica,200,',');
        if (arch.eof()) break;
        arch>>id_streamer;
        arch.get();
        posStreamer=buscarStreamer(id_streamer,tipoStreamer);
        if (posStreamer!=-1) {
            if (strcmp(tipoMetrica,"BASIC")==0) {
                arch>>metricaBasica;
                if (tipoStreamer=='G') {
                    streamers_gratuitos[posStreamer].agregar_metricas_basicas(metricaBasica);
                }
                else {
                    streamers_pago[posStreamer].agregar_metricas_basicas(metricaBasica);
                }
            }else if (strcmp(tipoMetrica,"ENGAGEMENT")==0) {
                arch>>metricaEngagement;
                streamers_pago[posStreamer].agregar_metricas_engagement(metricaEngagement);
            }else {
                arch>>metricaCalidad;
                streamers_pago[posStreamer].agregar_metricas_calidad(metricaCalidad);
            }
        }else arch.ignore(200,'\n');

    }
}
int GestorStreamers::buscarStreamer(int id_streamer,char &tipoStreamer) {
    for (int i = 0; i < cantidad_gratuitos; i++) {
        if (streamers_gratuitos[i].get_id()==id_streamer) {
            tipoStreamer='G';
            return i;
        }
    }
    for (int i = 0; i < cantidad_pagados; i++) {
        if (streamers_pago[i].get_id()==id_streamer) {
            tipoStreamer='P';
            return i;
        }
    }
    return -1;
}
