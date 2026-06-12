//
// Created by ANTONIO on 11/06/2026.
//

#ifndef LAB25_2_STREAMERPAGO_H
#define LAB25_2_STREAMERPAGO_H

#include "Streamer.h"
#include "../Metrica.h"
class StreamerPago:public Streamer {
    int fecha_inicio_plan;
    Metrica **metricas;
    int cantidad_metricas;
    int capacidad_metricas;

    void incrementarMetricas();
public:
    StreamerPago();
    StreamerPago(const StreamerPago&);
    //setters and getters
    int get_fecha_inicio_plan() const;
    void set_fecha_inicio_plan(int fecha_inicio_plan);

    int get_cantidad_metricas() const;
    void set_cantidad_metricas(int cantidad_metricas);

    int get_capacidad_metricas() const;
    void set_capacidad_metricas(int capacidad_metricas);
    //
    ifstream& leer(ifstream &) override;
    ofstream& imprimir(ofstream &) override;
    //
    TipoStreamer getTipoStreamer() const override;
    void agregar_metrica(Metrica *) override;
    //destructor
    ~StreamerPago() override;
};


#endif //LAB25_2_STREAMERPAGO_H
