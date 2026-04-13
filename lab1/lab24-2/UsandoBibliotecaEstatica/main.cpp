#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#include "Bibliotecas/Estructuras.h"
#include "Bibliotecas/Funciones.h"
#include "Bibliotecas/FuncionesAuxiliares.h"

int main() {
    Plato arrPlato[150];
    Repartidor arrRepartidor[50];

    ifstream archPlato,archRepar,archPedido;
    ofstream archRepPlato,archRepRepart;

    abrirIn(archPlato,"Archivos/PlatosOfrecidos.csv");
    abrirIn(archRepar,"Archivos/RepartidoresContratados.csv");
    abrirIn(archPedido,"Archivos/OrdenesDeCompra.txt");

    abrirOut(archRepPlato,"Archivos/ReportePlato.txt");
    abrirOut(archRepRepart,"Archivos/ReporteRepartidor.txt");

    //añadir a arreglos
    cargarPlatos(archPlato,arrPlato);
    cargarRepartidores(archRepar,arrRepartidor);
    cargarPedidos(archPedido,arrPlato,arrRepartidor);
    //actualizacion
    actualizarOrdenes(arrRepartidor);
    //impresion
    imprimirPlatos(archRepPlato,arrPlato);
    imprimirRepartidores(archRepRepart,arrRepartidor);

    return 0;
}
