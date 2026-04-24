//
// Created by anton on 20/04/2026.
//

#ifndef LAB25_2_FUNCIONES_H
#define LAB25_2_FUNCIONES_H
#include <fstream>
//cargarStreamer
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
//actualiza comentarios
void actualizacomentarios(void *&streamers,void *&comentarios) ;
void cargarComentario(void *regStreamers,void **regComentarios);
void crearComentarioNuevo(void **datoComentarios,void *&unComentStreamer);
void copiarCadena(char *cad,void *&nuevo) ;
//reporteFinal
void imprimeStreamer(const void *streamers);
void imprimirCaracter(ofstream &archRep,char car,int tam) ;
void imprimirCuenta(const void *regStreamers,ofstream &archRep);
void imprimirComentarioStreamer(const void *regComentStreamer,ofstream &archRep);
bool tieneComentarios(const void *regStreamers);
//aux
void abrirArch(const char *nombArch,ifstream &arch);
void abrirOut(const char *nombArch,ofstream &archRep);
char *leerCadenaExacta(ifstream &arch,char delim);
#endif //LAB25_2_FUNCIONES_H
