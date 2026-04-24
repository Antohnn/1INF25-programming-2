//
// Created by ANTONIO on 22/04/2026.
//
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Funciones.h"
#include "enums.h"
//cargarInventario
void cargarInventario(const char*nombArch,void *&inventario) {
    ifstream arch;
    abrirIn(nombArch,arch);
    void **registro=nullptr;
    void *producto;
    int num=0,capacidad=0;
    while (leerInventario(arch,producto)) {
        if (num==capacidad) {
            incrementarRegistro(registro,num,capacidad);
        }
        registro[num++]=producto;
    }
    if (registro==nullptr) registro=new void*[1]{};
    else registro[num]=nullptr;
    inventario=registro;
}
bool leerInventario(ifstream &arch,void *&producto) {
    char *codInsumo,*nombInsumo,*unidadInsumo,c;
    double cantInsumo;

    codInsumo=leerCadenaExacta(arch,',');
    if (arch.eof())return false;
    nombInsumo=leerCadenaExacta(arch,',');
    arch>>cantInsumo>>c;
    unidadInsumo=leerCadenaExacta(arch,'\n');

    void **reg=new void*[invNumCampos]{};
    reg[invCodigo]=codInsumo;
    reg[invNombre]=nombInsumo;
    reg[invCantDisponible]=new double(cantInsumo);
    reg[invCantRequerida]=new double(0.0);
    reg[invUnidadMedida]=unidadInsumo;

    producto=reg;
    return true;
}
//probarCargaInventario
void probarCargarInventario(const char *nombArch,const void *inventario) {
    ofstream arch;
    abrirOut(nombArch,arch);
    const void **regInventario=(const void **)inventario;
    for (int i=0;regInventario[i];i++) {
        imprimirArticulo(regInventario[i],arch);
    }
}
void imprimirArticulo(const void *regInventario,ofstream &arch) {
    const void **datoArticulo=(const void **)regInventario;

    const char *codInsumo=(char *)datoArticulo[invCodigo];
    const char *nombInsumo=(char *)datoArticulo[invNombre];
    const double cantDisponible=*(double *)datoArticulo[invCantDisponible];
    const double cantRequerida=*(double *)datoArticulo[invCantRequerida];
    const char *unidadInsumo=(char *)datoArticulo[invUnidadMedida];

    arch<<setprecision(2)<<fixed;
    arch<<left<<setw(8)<<codInsumo<<setw(28)<<nombInsumo<<right<<setw(10)<<' '<<cantDisponible
    <<setw(10)<<cantRequerida<<" "<<left<<setw(10)<<unidadInsumo<<endl;
}
//cargarMenu
void cargarMenu(const char *nombArch,void *&menu) {
    ifstream arch;
    abrirIn(nombArch,arch);
    void **regMenu=nullptr;
    int num=0,capacidad=0;
    void *articuloMenu;
    while (leerMenu(arch,articuloMenu)) {
        if (num==capacidad) {
            incrementarRegistro(regMenu,num,capacidad);
        }
        regMenu[num++]=articuloMenu;
    }
    if (regMenu==nullptr)regMenu=new void*[1]{};
    else regMenu[num]=nullptr;
    menu=regMenu;
}
bool leerMenu(ifstream &arch,void *&articuloMenu) {
    char *codMenu,*nombMenu,*descMenu,tipoMenu,c;
    bool disponible=true;
    int cantVentasEstim;
    double precio;

    codMenu=leerCadenaExacta(arch,',');
    if (arch.eof()) return false;
    nombMenu=leerCadenaExacta(arch,',');
    descMenu=leerCadenaExacta(arch,',');
    arch>>tipoMenu>>c>>precio>>c>>cantVentasEstim;
    arch.get();

    void **reg=new void*[bebNumCampos]{};
    reg[bebCodigo]=codMenu;
    reg[bebNombre]=nombMenu;
    reg[bebDescripcion]=descMenu;
    reg[bebTipo]=new char(tipoMenu);
    reg[bebDisponible]=new bool(disponible);
    reg[bebPrecio]=new double(precio);
    reg[bebCantVent]=new int(cantVentasEstim);
    reg[bebInsumoInv]=nullptr;

    articuloMenu=reg;
    return true;
}
//probarCargarMenu
void probarCargaMenu(const char *nombArch,const void *menu) {
    ofstream archRep;
    abrirOut(nombArch,archRep);
    const void **regBebidas=(const void **)menu;
    for (int i=0;regBebidas[i];i++) {
        imprimirBebida(regBebidas[i],archRep);
    }
}
void imprimirBebida(const void *regBebidas,ofstream &archRep) {
    const void **datoBebida=(const void **)regBebidas;

    const char *codBebida=(const char *)datoBebida[bebCodigo];
    const char *nombBebida=(const char *)datoBebida[bebNombre];
    const char *descBebida=(const char *)datoBebida[bebDescripcion];
    const char tipoBebida=*(const char *)datoBebida[bebTipo];
    const bool disponible=*(const bool*)datoBebida[bebDisponible];
    const double precio=*(const double*)datoBebida[bebPrecio];
    const int cantEstimada=*(const int*)datoBebida[bebCantVent];

    archRep<<left<<setw(6)<<codBebida<<setw(30)<<nombBebida<<setw(80)<<descBebida<<setw(5)<<tipoBebida<<right
        <<setw(10)<<disponible<<setw(10)<<precio<<setw(10)<<cantEstimada<<endl;
}
//actualizarMenu
void actualizarMenu(const char *nombArch,void *&inventario,void *&menu) {
    ifstream arch;
    abrirIn(nombArch,arch);
    void *insumoMenu;
    char *codBebida;
    while (leerInsumoBebida(arch,insumoMenu,inventario,codBebida)) {
        void *bebida=buscarBebida(menu,codBebida);
        cargarInsumoBebida(bebida,insumoMenu);
    }
    verificarInventario(menu);
}
bool leerInsumoBebida(ifstream &arch,void *&insumoMenu,void *&inventario,char *&codBebida) {
    char *codInsumo,*unidadMedida,c;
    double cantidad;

    codBebida=leerCadenaExacta(arch,',');
    if (arch.eof()) return false;
    codInsumo=leerCadenaExacta(arch,',');
    arch>>cantidad>>c;
    unidadMedida=leerCadenaExacta(arch,'\n');


    void **regInventario=(void **)inventario;
    void *insumoInventario=buscarInsumo(regInventario,codInsumo);
    void **reg=new void*[insNumCapos]{};
    reg[insCodigoInv]=insumoInventario;
    reg[insCant]=new double(cantidad);
    reg[insUnidadMedida]=unidadMedida;

    insumoMenu=reg;
    return true;
}
void *buscarInsumo(void **regInventario,char *codInsumo) {
    for (int i=0;regInventario[i];i++) {
        void **datoInventario=(void **)regInventario[i];
        char *codInsumoInventario=(char *)datoInventario[invCodigo];
        if (strcmp(codInsumo,codInsumoInventario)==0) {
            return datoInventario;
        }
    }
    return nullptr;
}
void *buscarBebida(void *menu,char *codBebida) {
    void **regMenu=(void **)menu;
    for (int i=0;regMenu[i];i++) {
        void **datoMenu=(void **)regMenu[i];
        char *codBebidaMenu=(char *)datoMenu[bebCodigo];
        if (strcmp(codBebidaMenu,codBebida)==0) {
            return datoMenu;
        }
    }
    return nullptr;
}
void cargarInsumoBebida(void *&bebida,void *&insumoMenu) {
    void **datoBebida=(void **)bebida;
    void **regInsumoBebida=(void **)datoBebida[bebInsumoInv];
    añadirEspacio(regInsumoBebida,insumoMenu);
    datoBebida[bebInsumoInv]=regInsumoBebida;
}
void añadirEspacio(void **&regInsumoBebida,void *insumoMenu) {
    int num=0;
    if (regInsumoBebida!=nullptr) {
        while (regInsumoBebida[num])num++;
    }
    void **aux=new void*[num+2]{};
    for (int i=0;i<num;i++) {
        aux[i]=regInsumoBebida[i];
    }
    aux[num]=insumoMenu;
    aux[num+1]=nullptr;
    delete []regInsumoBebida;

    regInsumoBebida=aux;
}
void verificarInventario(void *menu) {
    void **regMenu=(void **)menu;
    for (int i=0;regMenu[i];i++) {
        void **datoMenu=(void **)regMenu[i];
        void *insumos=(void **)datoMenu[bebInsumoInv];

        int cantVendida=*(int *)datoMenu[bebCantVent];
        if (!existeCantRequerida(insumos,cantVendida)) {
            *(bool *)datoMenu[bebDisponible]=false;
        }
    }
}
bool existeCantRequerida(void *insumos,int cantVendida) {
    void **regInsumo=(void **)insumos;
    bool suficiente=true;
    for (int i=0;regInsumo[i];i++) {
        void **datoInsumo=(void **)regInsumo[i];

        void **datoInsumoInventario=(void **)datoInsumo[insCodigoInv];
        double *cantidadDisponible=(double *)datoInsumoInventario[invCantDisponible];
        double *cantRequerida=(double *)datoInsumoInventario[invCantRequerida];
        double *insumoCant=(double *)datoInsumo[insCant];

        double nuevaCantidadRequerida=*cantRequerida+((*insumoCant/1000.0)*cantVendida);
        if (*cantidadDisponible<nuevaCantidadRequerida) {
            suficiente=false;
        }
        *cantRequerida=nuevaCantidadRequerida;
        datoInsumoInventario[invCantRequerida]=cantRequerida;
    }
    return suficiente;
}
//reporteMenu
void reporteMenu(const char *nombArch,const void *menu) {
    ofstream archRep;
    abrirOut(nombArch,archRep);
    archRep<<"===================================== Menu del dia ====================================="<<endl;
    const void **regMenu=(const void **)menu;
    for (int i=0;regMenu[i];i++) {
        const void **datoMenu=(const void **)regMenu[i];
        const char *nombre=(const char*)datoMenu[bebNombre];
        const char *descripcion=(const char*)datoMenu[bebDescripcion];
        const char *tipo=(const char *)datoMenu[bebTipo];
        const bool disponible=*(bool *)datoMenu[bebDisponible];
        const double precio=*(double *)datoMenu[bebPrecio];

        archRep << tipo << ": " << nombre << endl;
        archRep << descripcion << endl;
        archRep << "Precio: S/ " << fixed << setprecision(2) << precio << endl;
        archRep << "Disponible: " << (disponible ? "Si" : "No") << endl;
        archRep<<"====================================================================================="<<endl;
    }
}
//aux
void abrirIn(const char *nombArch,ifstream &arch) {
    arch.open(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        exit(1);
    }
}
void abrirOut(const char *nombArch,ofstream &arch) {
    arch.open(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        exit(1);
    }
}
char *leerCadenaExacta(ifstream &arch,char delim) {
    char aux[300],*cad;
    arch.getline(aux,300,delim);
    if (arch.eof()) return nullptr;
    cad=new char[strlen(aux)+1];
    strcpy(cad,aux);
    return cad;
}
void incrementarRegistro(void **&registroInventario,int num,int &capacidad) {
    capacidad+=5;
    if (registroInventario==nullptr) {
        registroInventario=new void*[capacidad+1]{};
    }else {
        void **aux=new void*[capacidad+1]{};
        for (int i=0;i<num;i++) {
            aux[i]=registroInventario[i];
        }
        delete []registroInventario;
        registroInventario=aux;
    }
}
