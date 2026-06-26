//Antonio Rios
//20233537

#include "Bibliotecas/SistemaDeGestion.h"
int main() {
    SistemaDeGestion si;

    si.cargarCategorias("ArchivosDeDatos/Categorias.csv");
    si.cargaComentarios("ArchivosDeDatos/Comentarios.csv");
    si.cargaEtiquetas("ArchivosDeDatos/Etiquetas.csv");
    si.cargaStreamers("ArchivosDeDatos/Streamers.csv");
    si.completarStreamers();
    si.reporteDeStreamers("ArchivosDeReporte/Reporte.txt");
    si.eliminarStreamers("French");
    si.reporteDeStreamers("ArchivosDeReporte/Reporte2.txt");

    return 0;
}
