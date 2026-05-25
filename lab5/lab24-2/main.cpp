#include <iostream>

using namespace std;


#include "Clases/Restaurante.h"
#include "Clases/Cliente.h"
#include "Clases/Plato.h"
#include "Clases/Funciones.h"

int main() {
    Restaurante restaurante;

    restaurante<"ArchivosDeDatos/Clientes.csv";
    restaurante<="ArchivosDeDatos/PlatosOfrecidos.csv";
    restaurante<<="ArchivosDeDatos/Pedidos.csv";
    restaurante>>"ArchivosDeReporte/ReporteDeVentasDelDia.txt";

    return 0;
}
