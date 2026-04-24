//
// Created by ANTONIO on 22/04/2026.
//

#ifndef LAB24_2_FUNCIONES_H
#define LAB24_2_FUNCIONES_H
//cargarInventario
void cargarInventario(const char*nombArch,void *&inventario);
bool leerInventario(ifstream &arch,void *&producto);
//probarCargaInventario
void probarCargarInventario(const char *nombArch,const void *inventario) ;
void imprimirArticulo(const void *regInventario,ofstream &arch);
//cargarMenu
void cargarMenu(const char *nombArch,void *&menu);
bool leerMenu(ifstream &arch,void *&articuloMenu) ;
//probarCargarMenu
void probarCargaMenu(const char *nombArch,const void *menu);
//actualizarMenu
void actualizarMenu(const char *nombArch,void *&inventario,void *&menu);
void imprimirBebida(const void *regBebidas,ofstream &archRep);
bool leerInsumoBebida(ifstream &arch,void *&insumoMenu,void *&inventario,char *&codBebida) ;
void *buscarInsumo(void **regInventario,char *codInsumo);
void *buscarBebida(void *menu,char *codBebida);
void cargarInsumoBebida(void *&bebida,void *&insumoMenu);
void añadirEspacio(void **&regInsumoBebida,void *insumoMenu);
void verificarInventario(void *menu);
bool existeCantRequerida(void *regInsumo,int cantVendida);
//reporteMenu
void reporteMenu(const char *nombArch,const void *menu);
//aux
char *leerCadenaExacta(ifstream &arch,char delim);
void incrementarRegistro(void **&registroInventario,int num,int &capacidad);
void abrirIn(const char *nombArch,ifstream &arch);
void abrirOut(const char *nombArch,ofstream &arch);
#endif //LAB24_2_FUNCIONES_H
