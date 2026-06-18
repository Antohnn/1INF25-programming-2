//
// Created by ANTONIO on 15/06/2026.
//

#ifndef LAB25_2_METRICACALIDAD_H
#define LAB25_2_METRICACALIDAD_H
#include "Metrica.h"


class MetricaCalidad:public Metrica{
    int bitrate_promedio_kbps;
    double porcentaje_frames_perdidos;
    int fps_promedio;
public:
    MetricaCalidad();
    MetricaCalidad(const MetricaCalidad &);
    //
    int get_bitrate_promedio_kbps() const;
    void set_bitrate_promedio_kbps(int bitrate_promedio_kbps);

    double get_porcentaje_frames_perdidos() const;
    void set_porcentaje_frames_perdidos(double porcentaje_frames_perdidos);

    int get_fps_promedio() const;
    void set_fps_promedio(int fps_promedio);
    //
    ifstream& leer(ifstream &) override;
    ofstream& imprimir(ofstream &) const override;
    //
    MetricaCalidad& operator= (const MetricaCalidad &);
    //destructor
    ~MetricaCalidad() override;
};


#endif //LAB25_2_METRICACALIDAD_H
