#include <iostream>

using namespace std;

#include "Bibliotecas/BibliotecaGenerica.h"
#include "Bibliotecas/ListaconEnteros.h"
#include "Bibliotecas/ListaconRegistros.h"

int main() {
    void *lista;

    creaLista(lista,leenumeros,"ArchivosDeDatos/numeros1.txt");
    cargaLista(lista,compruebanumero,leeregnumeros,"ArchivosDeDatos/numeros2.txt");
    muestraLista(lista,imprimenumeros,"ArchivosDeReporte/repnum.txt");

    creaLista(lista,leeregistros,"ArchivosDeDatos/Repartidores.csv");
    cargaLista(lista,compruebaregistro,leeordenes,"ArchivosDeDatos/Ordenes.csv");
    muestraLista(lista,imprimeregistros,"ArchivosDeReporte/repregistros.txt");


    return 0;
}
