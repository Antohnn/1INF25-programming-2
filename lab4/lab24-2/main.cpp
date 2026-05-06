#include <iostream>

using namespace std;

#include "Bibliotecas/BibliotecaGenerica.h"
#include "Bibliotecas/Lista.h"
#include "Bibliotecas/ListaConEnteros.h"
#include "Bibliotecas/ListaconRegistros.h"

int main() {
    void *lista;

    creaLista(lista,leenumeros,"ArchivosDeDatos/numeros1.txt");
    cargarlista(lista,compruebanumero,leeregnumeros,"ArchivosDeDatos/numeros2.txt");
    muestralista(lista,imprimenumeros,"ArchivosDeReporte/repnum.txt");

    creaLista(lista,leeregistros,"ArchivosDeDatos/Repartidores.csv");
    cargarlista(lista,compruebaregistro,leeordenes,"ArchivosDeDatos/Ordenes.csv");
    muestralista(lista,imprimeregistros,"ArchivosDeReporte/repregistros.txt");

    return 0;
}
