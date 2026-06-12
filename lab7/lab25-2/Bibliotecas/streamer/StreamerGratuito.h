//
// Created by ANTONIO on 11/06/2026.
//

#ifndef LAB25_2_STREAMERGRATUITO_H
#define LAB25_2_STREAMERGRATUITO_H
#include "Streamer.h"


#include "../MetricaBasica.h"

class StreamerGratuito: public Streamer {
    int fecha_fin_trial;
    Metrica **metricas_basicas;
    int cantidad_metricas_basicas;
    int capacidad_metricas_basicas;

    void incremetarMetricas();
public:
    StreamerGratuito();
    StreamerGratuito(const StreamerGratuito &);
    //setters and getters
    int get_fecha_fin_trial() const;
    void set_fecha_fin_trial(int fecha_fin_trial);

    int get_cantidad_metricas_basicas() const;
    void set_cantidad_metricas_basicas(int cantidad_metricas_basicas);

    int get_capacidad_metricas_basicas() const;
    void set_capacidad_metricas_basicas(int capacidad_metricas_basicas);
    //
    TipoStreamer getTipoStreamer() const override;
    void agregar_metrica(Metrica *metrica) override;
    //
    ifstream& leer(ifstream &) override;
    ofstream& imprimir(ofstream &) override;
    //destructor
    ~StreamerGratuito() override;
};


#endif //LAB25_2_STREAMERGRATUITO_H
