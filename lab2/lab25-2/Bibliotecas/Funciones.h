//
// Created by ANTONIO on 15/04/2026.
//

#ifndef LAB25_2_FUNCIONES_H
#define LAB25_2_FUNCIONES_H
//CargarCategorias
void cargarCategorias(const char* nombArch,char ***&categorias) ;
void incrementarCategoria(char ***&categorias,int numDat,int &capacidad);
bool leerCategorias(ifstream &archCate,char **&categoria);
//cargarStreamers
void cargarStreamers(const char* nombArch,char ***&streamers,int **&fechasPromedios,long long **&tiemposRepSegidores) ;
void incrementarStreamer(char ***&streamers,int numDat,int capacidad);
void incrementarFechaPromedio(int **&fechasPromedios,int numDat,int capacidad) ;
void incrementarFechaPromedioSeg(long long **&tiemposRepSegidores,int numDat,int capacidad);
bool leerStreamers(ifstream &archStream,char **&streamer,int *&fechaPromedio,long long *&tiempoRepSegidor);
int leerFecha(ifstream &archStream);
//cargarComentarios
void cargarComentarios(const char *nombArch,char ***&comentarios,char ***&etiquetas);
void incrementarComentarios(char ***&comentarios,int numDat,int capacidad);
void incrementarEtiquetas(char ***&etiquetas,int numDat,int capacidad) ;
bool leerComentarios(ifstream &archCom,char **&comentario,char **&etiquetaComent);
void cargarEtiquetas(ifstream &archCom,char **&etiquetaComent) ;
bool leerEtiqueta(ifstream &archCom,char *&etiqueta);
//aux
char* leerCadenaExacta(ifstream &arch,char delim);

#endif //LAB25_2_FUNCIONES_H
