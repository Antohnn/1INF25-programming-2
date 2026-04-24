#include <iostream>
#include <fstream>

using namespace std;

#include "Bibliotecas/Funciones.h"

int main() {
    void *inventario,*menu;
    //cargarInventario
    cargarInventario("ArchivosDeDatos/inventario.csv",inventario);
    //probarCargaInventario
    probarCargarInventario("ArchivosDeReporte/prueba-inventario.txt",inventario);

    //cargarMenu
    cargarMenu("ArchivosDeDatos/menu.csv",menu);
    //probarCargarMenu
    probarCargaMenu("ArchivosDeReporte/menu-inicial.txt",menu);
    //actualizarMenu
    actualizarMenu("ArchivosDeDatos/insumos-bebidas.csv",inventario,menu);
    //reporteMenu
    reporteMenu("ArchivosDeReporte/menu.txt",menu);

    return 0;
}
