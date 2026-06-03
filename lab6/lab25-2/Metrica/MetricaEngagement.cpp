//
// Created by ANTONIO on 2/06/2026.
//

#include <iostream>

using namespace std;

#include "MetricaEngagement.h"

MetricaEngagement::MetricaEngagement() {
    mensajes_chat=0;
    usuarios_unicos_chat=0;
    clips_generados=0;
}
MetricaEngagement::MetricaEngagement(const MetricaEngagement&origin) {
    *this=origin;
}

//setters and getters
int MetricaEngagement::get_mensajes_chat() const {
    return mensajes_chat;
}
void MetricaEngagement::set_mensajes_chat(int mensajes_chat) {
    this->mensajes_chat = mensajes_chat;
}

int MetricaEngagement::get_usuarios_unicos_chat() const {
    return usuarios_unicos_chat;
}
void MetricaEngagement::set_usuarios_unicos_chat(int usuarios_unicos_chat) {
    this->usuarios_unicos_chat = usuarios_unicos_chat;
}

int MetricaEngagement::get_clips_generados() const {
    return clips_generados;
}
void MetricaEngagement::set_clips_generados(int clips_generados) {
    this->clips_generados = clips_generados;
}

ifstream& MetricaEngagement::leer(ifstream &arch) {
    if (!Metrica::leer(arch)) {
        return arch;
    }
    int msjChat,usuarioUnico,clipGenerado;
    char car;
    arch.get();
    arch>>msjChat>>car>>usuarioUnico>>car>>clipGenerado;

    this->set_mensajes_chat(msjChat);
    this->set_usuarios_unicos_chat(usuarioUnico);
    this->set_clips_generados(clipGenerado);

    return arch;
}
ofstream& MetricaEngagement::imprimir(ofstream &archRep) {
    Metrica::imprimir(archRep);
    archRep<<this->get_mensajes_chat()<<" "<<this->get_usuarios_unicos_chat()<<" "<<this->get_clips_generados();
    imprimirDescripcion(archRep);

    return archRep;
}

MetricaEngagement& MetricaEngagement::operator=(const MetricaEngagement &origin) {
    if (this!=&origin) {
        Metrica::operator=(origin);
        this->set_mensajes_chat(origin.get_mensajes_chat());
        this->set_usuarios_unicos_chat(origin.get_usuarios_unicos_chat());
        this->set_clips_generados(origin.get_clips_generados());
    }
    return *this;
}

ifstream& operator>>(ifstream &arch,MetricaEngagement& metricaEngagement) {
    return metricaEngagement.leer(arch);
}
ofstream& operator<<(ofstream &archRep,MetricaEngagement& metricaEngagement) {
    return metricaEngagement.imprimir(archRep);
}