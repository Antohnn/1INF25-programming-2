#include <iostream>
#include "Bibliotecas/GestorStreamers.h"
using namespace std;

int main() {
    GestorStreamers gestor;
    gestor.cargar_datos_streamers("ArchivosDeDatos/streamers.csv");
    gestor.actualizar_datos_metricas("ArchivosDeDatos/metricas.csv");

    return 0;
}
