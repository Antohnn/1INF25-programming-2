//
// Created by ANTONIO on 15/04/2026.
//

#ifndef LAB25_2_FUNCIONES_H
#define LAB25_2_FUNCIONES_H
//CargarCategorias
void cargarCategorias(const char* nombArch,char ***&categorias) ;
void incrementarCategoria(char ***&categorias,int numDat,int &capacidad);
bool leerCategorias(ifstream &archCate,char **&categoria);
char* leerCadenaExacta(ifstream &arch,char delim);
//cargarStreamers
void cargarStreamers(const char* nombArch,char ***&streamers,int **&fechasPromedios,long long **&tiemposRepSegidores) ;
void incrementarStreamer(char ***&streamers,int numDat,int capacidad);
void incrementarFechaPromedio(int **&fechasPromedios,int numDat,int capacidad) ;
void incrementarFechaPromedioSeg(long long **&tiemposRepSegidores,int numDat,int capacidad);
bool leerStreamers(ifstream &archStream,char **&streamer,int *&fechaPromedio,long long *&tiempoRepSegidor);
int leerFecha(ifstream &archStream);

#endif //LAB25_2_FUNCIONES_H
