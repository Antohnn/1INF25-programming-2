#include <iostream>

#include "Bibliotecas/GestorStreamers.h"

using namespace std;

int main() {
    GestorStreamers streamers;

    streamers.cargar_datos_streamers("ArchivosDeDatos/streamers.csv");
    streamers.actualizar_datos_metricas("ArchivosDeDatos/metricas.csv");

    return 0;
}
