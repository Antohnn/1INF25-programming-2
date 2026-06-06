//
// Created by ANTONIO on 3/06/2026.
//

#ifndef LAB25_2_GESTORSTREAMERS_H
#define LAB25_2_GESTORSTREAMERS_H

#include "../streamer/StreamerGratuito.h"
#include "../streamer/StreamerPago.h"

class GestorStreamers {
    StreamerGratuito *streamers_gratuitos;
    StreamerPago *streamers_pago;
    int cantidad_gratuitos;
    int cantidad_pagados;

    void asignarStreamer(const GestorStreamers &origin);
    void asignarStreamers(StreamerGratuito *,StreamerPago *,int ,int );
    int buscarStreamer(int ,char &);

public:
    GestorStreamers();
    GestorStreamers(const GestorStreamers &);

    //setters and getters
    int get_cantidad_gratuitos() const;
    void set_cantidad_gratuitos(int cantidad_gratuitos);

    int get_cantidad_pagados() const;
    void set_cantidad_pagados(int cantidad_pagados);

    GestorStreamers& operator=(const GestorStreamers &);

    void cargar_datos_streamers(const char*);
    void actualizar_datos_metricas(const char*);
};


#endif //LAB25_2_GESTORSTREAMERS_H
