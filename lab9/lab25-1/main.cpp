#include <iostream>

#include "Bibliotecas/MinisterioDeTransporte.h"

using namespace std;

int main() {
    MinisterioDeTransporte mi;
    mi.cargaDeInfracciones("ArchivosDeDatos/TablaDeInfracciones.csv");
    mi.cargaEmpresas("ArchivosDeDatos/EmpresasRegistradas.csv");
    mi.cargaVehiculos("ArchivosDeDatos/VehiculosRegistrados.csv");
    mi.cargaInfraccionesCometidas("ArchivosDeDatos/InfraccionesCometidas.csv");
    mi.reporteDeEmpresasConInfracciones("ArchivosDeReporte/Reporte.txt");
    mi.eliminaInfraccionesPagadas();
    mi.reporteDeEmpresasConInfracciones("ArchivosDeReporte/ReporteSinPagadas.txt");

    return 0;
}
