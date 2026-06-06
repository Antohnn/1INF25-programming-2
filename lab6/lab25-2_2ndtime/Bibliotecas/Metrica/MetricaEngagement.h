//
// Created by ANTONIO on 4/06/2026.
//

#ifndef LAB25_2_2NDTIME_METRICAENGAGEMENT_H
#define LAB25_2_2NDTIME_METRICAENGAGEMENT_H
#include "Metrica.h"


class MetricaEngagement:public Metrica {
    int mensajes_chat;
    int usuarios_unicos_chat;
    int clips_generados;
public:
    //constructores
    MetricaEngagement();
    MetricaEngagement(const MetricaEngagement&);
    //setters and getters
    int get_mensajes_chat() const;
    void set_mensajes_chat(int mensajes_chat);

    int get_usuarios_unicos_chat() const;
    void set_usuarios_unicos_chat(int usuarios_unicos_chat);

    int get_clips_generados() const;
    void set_clips_generados(int clips_generados);
    //
    ifstream& leer(ifstream &);
    ofstream& imprimir(ofstream &);
    //operador de asignacion
    MetricaEngagement& operator=(const MetricaEngagement&);

    //destructor
    ~MetricaEngagement();
};
ifstream& operator>> (ifstream &, MetricaEngagement&);
ofstream& operator<< (ofstream &, MetricaEngagement&);


#endif //LAB25_2_2NDTIME_METRICAENGAGEMENT_H
