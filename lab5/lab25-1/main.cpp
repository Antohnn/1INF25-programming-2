#include <iostream>

#include "Clases/MinisterioDeTransporte.h"

using namespace std;

int main() {
    MinisterioDeTransporte ministerio;

    ministerio<"ArchivosDeDatos/TablaDeInfracciones.csv";
    ministerio<="ArchivosDeDatos/EmpresasRegistradas.csv";
    ministerio<<="ArchivosDeDatos/InfraccionesCometidas.csv";
    ministerio>>"ArchivosDeReporte/ReporteParaElMinisterio.txt";

    return 0;
}
