//
// Created by ANTONIO on 18/06/2026.
//

#ifndef LAB25_2_2NDTIME_METRICAEGAGEMENT_H
#define LAB25_2_2NDTIME_METRICAEGAGEMENT_H
#include "Metrica.h"


class MetricaEgagement:public Metrica {
    int mensajes_chat;
    int usuarios_unicos_chat;
    int clips_generados;
public:
    MetricaEgagement();
    MetricaEgagement(const MetricaEgagement &);
    //setters and getters
    int get_mensajes_chat() const;
    void set_mensajes_chat(int mensajes_chat);

    int get_usuarios_unicos_chat() const;
    void set_usuarios_unicos_chat(int usuarios_unicos_chat);

    int get_clips_generados() const;
    void set_clips_generados(int clips_generados);
    //
    ifstream& leer(ifstream &) override;
    ofstream& imprimir(ofstream &) override;
    //
    TipoMetrica get_tipo() const override;
    //
    MetricaEgagement& operator= (const MetricaEgagement &);
    //destructor
    ~MetricaEgagement() override;
};


#endif //LAB25_2_2NDTIME_METRICAEGAGEMENT_H
