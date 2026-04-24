#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#include "Bibliotecas/Funciones.h"
#include "Bibliotecas/enums.h"

int main() {
    void *inventario,*menu;

    cargarInventario("ArchivosDeDatos/inventario.csv",inventario);

    return 0;
}
