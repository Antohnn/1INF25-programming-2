//
// Created by ANTONIO on 14/06/2026.
//

#ifndef LAB25_2_METRICABASICA_H
#define LAB25_2_METRICABASICA_H
#include "Metrica.h"


class MetricaBasica:public Metrica {
    double horas_transmitidas;
    int espectadores_promedio;
public:
    MetricaBasica();
    MetricaBasica(const MetricaBasica &);
    //setters and getters
    double get_horas_transmitidas() const;
    void set_horas_transmitidas(double horas_transmitidas);

    int get_espectadores_promedio() const;
    void set_espectadores_promedio(int espectadores_promedio);
    //
    ifstream& leer(ifstream &) override;
    ofstream& imprimir(ofstream &) const override;
    //
    MetricaBasica& operator=(const MetricaBasica &);
    //destrictor
    ~MetricaBasica() override;
};


#endif //LAB25_2_METRICABASICA_H
