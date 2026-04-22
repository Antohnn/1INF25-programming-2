//
// Created by anton on 20/04/2026.
//

#ifndef LAB25_2_FUNCIONES_H
#define LAB25_2_FUNCIONES_H
//cargarPaciente
void cargarStreamers(void *&streamers);
bool leerStreamer(ifstream &archStreamer,void *&streamer);
void incrementarRegistro(void **&registros,int num,int &capacidad) ;
//cargarComentarios
void cargarComentarios(void *&comentarios) ;
bool leerComentario(ifstream &archComent,void *&comentario) ;
void cargarHablantes(ifstream &archComent,char *&emisorComent,char *&recepComent);
//reporte simple
void reporteSimple(void *&streamers,void *&comentarios);
void imprimirStreamer(ofstream &archReporteStreamer,const void *regStreamers);
void imprimirComentario(ofstream &archReporteComentario,const void*regComentarios);
//aux
void abrirArch(const char *nombArch,ifstream &arch);
void abrirOut(const char *nombArch,ofstream &archRep);
char *leerCadenaExacta(ifstream &arch,char delim);
#endif //LAB25_2_FUNCIONES_H
