//
// Created by ANTONIO on 15/06/2026.
//

#ifndef LAB25_2_METRICAENGAGEMENT_H
#define LAB25_2_METRICAENGAGEMENT_H
#include "Metrica.h"


class MetricaEngagement:public Metrica {
    int mensajes_chat;
    int usuarios_unicos_chat;
    int clips_generados;
public:
    MetricaEngagement();
    MetricaEngagement(const MetricaEngagement &);
    //setters and getters
    int get_mensajes_chat() const;
    void set_mensajes_chat(int mensajes_chat);

    int get_usuarios_unicos_chat() const;
    void set_usuarios_unicos_chat(int usuarios_unicos_chat);

    int get_clips_generados() const;
    void set_clips_generados(int clips_generados);
    //
    TipoMetrica getTipo() const override;
    //
    ifstream& leer(ifstream &) override;
    ofstream& imprimir(ofstream &) const override;
    //
    MetricaEngagement& operator=(const MetricaEngagement &);
    //destructor
    ~MetricaEngagement() override;

};


#endif //LAB25_2_METRICAENGAGEMENT_H
