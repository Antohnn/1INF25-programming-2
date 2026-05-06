#include <iostream>

using namespace std;

#include "Bibliotecas/BibliotecaGenerica.h"
#include "Bibliotecas/BibliotecaConductores.h"
#include "Bibliotecas/BibliotecaInfracciones.h"

int main() {
    void *lista;

    generaLista(lista);
    creaLista(lista,leeconductores,cmpconductores,buscalistaconductores,
        "ArchivosDeDatos/conductores.csv");
    cargaUnidades(lista,"ArchivosDeDatos/unidades.csv");
    creaLista(lista,leeinfracciones,cmpinfracciones,buscalistainfraccion,
        "ArchivosDeDatos/faltas.csv");
    imprimeLista(lista,imprimeconductores,"ArchivosDeReporte/repconductores.txt");

    return 0;
}
