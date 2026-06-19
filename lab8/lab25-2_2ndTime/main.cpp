#include <iostream>

#include "Bibliotecas/AdministrarMetricas.h"

using namespace std;

int main() {
    AdministrarMetricas lista;

    lista.cargarArchivo("ArchivosDeDatos/metricas.csv");
    lista.generarReporte("ArchivosDeReporte/prueba.txt");
    lista.eliminarNodos();
    lista.generarReporte("ArchivosDeReporte/SinExpirado.txt");

    return 0;
}
