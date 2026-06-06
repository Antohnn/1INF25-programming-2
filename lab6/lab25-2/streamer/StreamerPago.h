//
// Created by ANTONIO on 2/06/2026.
//

#ifndef LAB25_2_STREAMERPAGO_H
#define LAB25_2_STREAMERPAGO_H

#include "Streamer.h"
#include "../metrica/MetricaBasica.h"
#include "../metrica/MetricaEngagement.h"
#include "../metrica/MetricaCalidad.h"

class StreamerPago:public Streamer {
    int fecha_inicio_plan;
    MetricaBasica *metricas_basicas;
    int cantidad_metricas_basicas;
    MetricaEngagement *metricas_engagements;
    int cantidad_metricas_engagement;
    MetricaCalidad *metricas_calidades;
    int cantidad_metricas_calidades;

    void asignarMetricas(const StreamerPago &);
public:
    StreamerPago();
    StreamerPago(const StreamerPago &);

    //setters and getters

    int get_fecha_inicio_plan() const;
    void set_fecha_inicio_plan(int fecha_inicio_plan);

    int get_cantidad_metricas_basicas() const;
    void set_cantidad_metricas_basicas(int cantidad_metricas_basicas);

    int get_cantidad_metricas_engagement() const;
    void set_cantidad_metricas_engagement(int cantidad_metricas_engagement);

    int get_cantidad_metricas_calidades() const;
    void set_cantidad_metricas_calidades(int cantidad_metricas_calidades);

    StreamerPago& operator= (const StreamerPago &);

    ifstream& leer(ifstream &);
    ofstream& imprimir(ofstream &);

    void agregar_metricas_basicas(MetricaBasica &);
    void agregar_metricas_engagement(MetricaEngagement &);
    void agregar_metricas_calidad(MetricaCalidad &);

    ~StreamerPago();
};
ifstream& operator>>(ifstream &, StreamerPago &);
ofstream& operator<<(ofstream &, StreamerPago &);


#endif //LAB25_2_STREAMERPAGO_H
