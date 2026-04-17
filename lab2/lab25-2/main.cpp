#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Bibliotecas/Funciones.h"

int main() {
    char *** categorias;
    cargarCategorias("Archivos/categorias.csv",categorias);

    char ***streamers;
    int **fechasPromedios;
    long long **tiemposRepSegidores;
    cargarStreamers("Archivos/streamers.csv",streamers,fechasPromedios,tiemposRepSegidores);

    char*** comentarios;
    char*** etiquetas;
    //cargarComentarios
    cargarComentarios("Archivos/comentarios.csv",comentarios,etiquetas);


    imprimirReporte("Archivos/reporte.txt",categorias,streamers,fechasPromedios,tiemposRepSegidores,comentarios,etiquetas);



    return 0;
}
