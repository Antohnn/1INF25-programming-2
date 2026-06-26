//
// Created by anton on 26/06/2026.
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
void SistemaDeGestion::cargaEtiquetas(const char *nombArch) {
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
    for (auto itSt=streamers.begin(); itSt!=streamers.end(); itSt++) {
        completarCategoria(*itSt);
        completarComentarios(*itSt);
        completarEtiquetas(*itSt);
    }
}
void SistemaDeGestion::completarCategoria(Streamer &streamer) {
    for (auto itCat=categorias.begin(); itCat!=categorias.end(); itCat++) {
        if (itCat->get_codigo()==streamer.getCodCategoria()) {
            streamer.setCategoria(*itCat);
            return;
        }
    }
}
void SistemaDeGestion::completarComentarios(Streamer &streamer) {
    for (auto itCom=comentarios.begin(); itCom!=comentarios.end(); itCom++) {
        if (itCom->get_canal()==streamer.get_canal()) {
            streamer.agregarComentario(*itCom);
        }
    }
}
void SistemaDeGestion::completarEtiquetas(Streamer &streamer) {
    map<string,Etiqueta>::iterator itEt;
    istringstream ss(streamer.get_etiquetas_str());
    string codEtiqueta;

    while (getline(ss,codEtiqueta,'-')) {
        itEt=etiquetas.find(codEtiqueta);
        if (itEt!=etiquetas.end()) {
            streamer.agregarEtiqueta(itEt->second);
        }
    }
}
void SistemaDeGestion::reporteDeStreamers(const char* nombArch) {
    ofstream archRep(nombArch,ios::out);
    archRep<<string(120,'=')<<endl;
    archRep<<setw(60)<<"RELACION DE STREAMERS"<<endl;
    for (auto itSt=streamers.begin(); itSt!=streamers.end(); itSt++) {
        archRep<<string(120,'-')<<endl;
        archRep<<*itSt;
    }
}
void SistemaDeGestion::eliminarStreamers(const string &idioma) {
    list<Streamer>::iterator itSt;
    itSt=streamers.begin();

    while (itSt!=streamers.end()) {
        if (itSt->get_idioma()==idioma) {
            itSt=streamers.erase(itSt);
        }else {
            itSt++;
        }
    }

}


