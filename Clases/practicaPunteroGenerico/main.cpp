#include <cstring>
#include <iostream>

using namespace std;
void imprimirEntero(void *&punteroGenerico) {
    cout<<*(int *)punteroGenerico<<endl;
}
void imprimirDouble(void *&punteroGenerico) {
    cout<<*(double *)punteroGenerico<<endl;
}
int main() {

    void *punteroGenerico;

    int a=10;

    punteroGenerico=&a;

    imprimirEntero(punteroGenerico);

    double numero=40.2;

    punteroGenerico=&numero;

    imprimirDouble(punteroGenerico);

    char *nombre;

    nombre=new char[20];
    strcpy (nombre, "HOLA PAPUS");

    punteroGenerico=nombre;

    cout<<(char *)punteroGenerico<<endl;



    return 0;
}
