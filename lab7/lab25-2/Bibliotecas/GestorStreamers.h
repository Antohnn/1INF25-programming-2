//
// Created by ANTONIO on 11/06/2026.
//

#ifndef LAB25_2_GESTORSTREAMERS_H
#define LAB25_2_GESTORSTREAMERS_H

#include "streamer/Streamer.h"
class GestorStreamers {
    Streamer **streamers;
    int cantidad_streamers;
    int capacidad_streamers;

    void incrementarCapacidad();
    int buscarStreamer(int );
public:
    GestorStreamers();
    GestorStreamers(const GestorStreamers &);

    int get_cantidad_streamers() const;
    void set_cantidad_streamers(int cantidad_streamers);

    int get_capacidad_streamers() const;
    void set_capacidad_streamers(int capacidad_streamers);
    //
    void cargar_datos_streamers(const char*);
    void actualizar_datos_metricas(const char*);
    //

};


#endif //LAB25_2_GESTORSTREAMERS_H
