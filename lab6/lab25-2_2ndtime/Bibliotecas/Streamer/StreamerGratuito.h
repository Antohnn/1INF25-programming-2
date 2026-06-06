//
// Created by ANTONIO on 4/06/2026.
//

#ifndef LAB25_2_2NDTIME_STREAMERGRATUITO_H
#define LAB25_2_2NDTIME_STREAMERGRATUITO_H
#include "Streamer.h"

#include "../Metrica/MetricaBasica.h"

class StreamerGratuito:public Streamer {
    int fecha_fin_trial;
    MetricaBasica *metricas_basicas;
    int cantidad_metricas_basicas;
public:
    StreamerGratuito();
    StreamerGratuito(const StreamerGratuito &);
    //setters and getters
    int get_fecha_fin_trial() const;
    void set_fecha_fin_trial(int fecha_fin_trial);

    int get_cantidad_metricas_basicas() const;
    void set_cantidad_metricas_basicas(int cantidad_metricas_basicas);
    //
    ifstream& leer(ifstream &);
    ofstream& imprimir(ofstream &);
    //
    void imprimirMetricaBasica(ofstream &);
    void imprimirStatsMetricaBasica(ofstream &);
    //destructor
    ~StreamerGratuito();
};


#endif //LAB25_2_2NDTIME_STREAMERGRATUITO_H
