#include <iostream>

using namespace std;

#include "Bibliotecas/PilaConEnteros.h"
#include "Bibliotecas/FlotaGenerica.h"

int main() {
    int numcamiones;
    double pesomaximo;
    void *flota;

    numcamiones=5,pesomaximo=10;
    cargacamiones(flota, numcamiones, pesomaximo,leenumero,calculanumero,"ArchivosDeDatos/numeros.txt");
    qsort(flota,numcamiones,sizeof(void *),cmpnumero);

    return 0;
}
