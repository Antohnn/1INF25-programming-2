#include <iostream>

using namespace std;

#include "Bibliotecas/Funciones.h"

int main() {
    void *streamers,*comentarios;

    cargarStreamers(streamers);
    cargarComentarios(comentarios);
    reporteSimple(streamers,comentarios);

    return 0;
}
