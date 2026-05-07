#include <iostream>

using namespace std;

#include "Bibliotecas/BibliotecaGenerica.h"
#include "Bibliotecas/BibliotecaConductores.h"

int main() {
    void *lista;

    generalista(lista);
    creaLista(lista,leeconductores,cmpcondcutores,buscalistaconductores,"ArchivosDeDatos/Conductores.csv");

    return 0;
}
