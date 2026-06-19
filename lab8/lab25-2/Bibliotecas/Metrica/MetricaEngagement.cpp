//
// Created by ANTONIO on 15/06/2026.
//

#include <iostream>
using namespace std;
#include "MetricaEngagement.h"

MetricaEngagement::MetricaEngagement() {
    mensajes_chat=0;
    usuarios_unicos_chat=0;
    clips_generados=0;
}
MetricaEngagement::MetricaEngagement(const MetricaEngagement &origin) {
    *this=origin;
}

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
//
TipoMetrica MetricaEngagement::getTipo() const {
    return ENGAGEMENT;
}
//
ifstream& MetricaEngagement::leer(ifstream &arch) {
    if (!Metrica::leer(arch)) {
        return arch;
    }
    int mensajesChat,usuariosChat,clipsChat;
    char car;

    arch>>mensajesChat>>car>>usuariosChat>>car>>clipsChat;

    this->set_mensajes_chat(mensajesChat);
    this->set_usuarios_unicos_chat(usuariosChat);
    this->set_clips_generados(clipsChat);

    arch.ignore(100,'\n');
    return arch;
}
ofstream& MetricaEngagement::imprimir(ofstream &archRep) const {
    Metrica::imprimir(archRep);
    archRep<<this->get_mensajes_chat()<<" "<<this->get_mensajes_chat()<<" "<<this->get_clips_generados()<<endl;
    return archRep;
}
//
MetricaEngagement& MetricaEngagement::operator=(const MetricaEngagement &origin) {
    if (this!=&origin) {
        Metrica::operator=(origin);
        this->set_mensajes_chat(origin.get_mensajes_chat());
        this->set_usuarios_unicos_chat(origin.get_usuarios_unicos_chat());
        this->set_clips_generados(origin.get_clips_generados());
    }
    return *this;
}

//destructor
MetricaEngagement::~MetricaEngagement() = default;
