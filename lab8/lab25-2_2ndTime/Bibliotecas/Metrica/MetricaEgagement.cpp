//
// Created by ANTONIO on 18/06/2026.
//

#include <iostream>
using namespace std;
#include "MetricaEgagement.h"

MetricaEgagement::MetricaEgagement() {
    mensajes_chat=0;
    usuarios_unicos_chat=0;
    clips_generados=0;
}
MetricaEgagement::MetricaEgagement(const MetricaEgagement &origin):MetricaEgagement() {
    *this = origin;
}

int MetricaEgagement::get_mensajes_chat() const {
    return mensajes_chat;
}
void MetricaEgagement::set_mensajes_chat(int mensajes_chat) {
    this->mensajes_chat = mensajes_chat;
}

int MetricaEgagement::get_usuarios_unicos_chat() const {
    return usuarios_unicos_chat;
}
void MetricaEgagement::set_usuarios_unicos_chat(int usuarios_unicos_chat) {
    this->usuarios_unicos_chat = usuarios_unicos_chat;
}

int MetricaEgagement::get_clips_generados() const {
    return clips_generados;
}
void MetricaEgagement::set_clips_generados(int clips_generados) {
    this->clips_generados = clips_generados;
}
//
ifstream& MetricaEgagement::leer(ifstream &arch) {
    if (!Metrica::leer(arch)) {
        return arch;
    }
    int mensajesChat,usuariosUnicos,clipsGenerados;
    char car;
    arch>>mensajesChat>>car>>usuariosUnicos>>car>>clipsGenerados;

    this->set_mensajes_chat(mensajesChat);
    this->set_usuarios_unicos_chat(usuariosUnicos);
    this->set_clips_generados(clipsGenerados);
    arch.ignore(100,'\n');
    return arch;
}
ofstream& MetricaEgagement::imprimir(ofstream &archRep) {
    archRep<<"ME";
    Metrica::imprimir(archRep);
    archRep<<this->get_mensajes_chat()<<" "<<this->get_usuarios_unicos_chat()<<" "<<this->get_clips_generados()<<endl;
    return archRep;
}
//
TipoMetrica MetricaEgagement::get_tipo() const {
    return ENGAGEMENT;
}
//
MetricaEgagement& MetricaEgagement::operator= (const MetricaEgagement &origin) {
    if (this != &origin) {
        Metrica::operator=(origin);
        this->set_mensajes_chat(origin.get_mensajes_chat());
        this->set_usuarios_unicos_chat(origin.get_usuarios_unicos_chat());
        this->set_clips_generados(origin.get_clips_generados());
    }
    return *this;
}

//destructor
MetricaEgagement::~MetricaEgagement() =default;
