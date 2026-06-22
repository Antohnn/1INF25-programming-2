//
// Created by anton on 22/06/2026.
//

#include "SistemaDeGestion.h"

void SistemaDeGestion::cargarCategorias(const char* nombArch) {
    ifstream arch(nombArch,ios::in);
    Categoria nuevo;
    while (arch>>nuevo) {
        categorias.push_back(nuevo);
    }
    categorias.sort();
}
void SistemaDeGestion::cargaComentarios(const char* nombArch) {
    ifstream arch(nombArch,ios::in);
    Comentario nuevo;
    while (arch>>nuevo) {
        comentarios.push_back(nuevo);
    }
    comentarios.sort();
}
void SistemaDeGestion::cargaEtiquetas(const char* nombArch) {
    ifstream arch(nombArch,ios::in);
    Etiqueta nuevo;
    while (arch>>nuevo) {
        etiquetas[nuevo.get_codigo()]=nuevo;
    }
}
void SistemaDeGestion::cargaStreamers(const char* nombArch) {
    ifstream arch(nombArch,ios::in);
    Streamer nuevo;
    while (arch>>nuevo) {
        streamers.push_back(nuevo);
    }
    streamers.sort();

}
void SistemaDeGestion::completarStreamers() {
    for (auto itSt=streamers.begin();itSt!=streamers.end();itSt++) {
        completarCategorias(*itSt);
        completarEtiquetas(*itSt);
        completarComentarios(*itSt);
    }
}
void SistemaDeGestion::completarCategorias(Streamer &streamer) {
    for (auto itCa=categorias.begin();itCa!=categorias.end();itCa++) {
        if (streamer.get_codCategoria()==itCa->get_codigo()) {
            streamer.set_Categoria(*itCa);
            break;
        }
    }
}
void SistemaDeGestion::completarEtiquetas(Streamer &streamer) {
    istringstream ss(streamer.get_etiquetas_str());
    string codEtiqueta;
    while (getline(ss,codEtiqueta,'-')) {
        auto itEt=etiquetas.find(codEtiqueta);
        if (itEt!=etiquetas.end()) {
            streamer.agregarEtiqueta(itEt->second);
        }
    }
}
void SistemaDeGestion::completarComentarios(Streamer &streamer) {
    for (auto itCo=comentarios.begin();itCo!=comentarios.end();itCo++) {
        if (streamer.get_canal()==itCo->get_canal()) {
            streamer.agregarComentario(itCo->get_comentario());
        }
    }
}
void SistemaDeGestion::reporteDeStreamers(const char *nombArch) {
    ofstream archRep(nombArch,ios::out);
    imprimirHeader(archRep);
    for (auto itSt=streamers.begin();itSt!=streamers.end();itSt++) {
        archRep<<string(120,'-')<<endl;
        archRep<<*itSt;
    }
}
void SistemaDeGestion::imprimirHeader(ofstream &archRep) {
    archRep<<setprecision(2)<<fixed;
    archRep<<string(120,'=')<<endl;
    archRep<<setw(80)<<"RELACION DE STREAMERS"<<endl;
}