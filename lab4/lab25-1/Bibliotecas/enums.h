//
// Created by ANTONIO on 5/05/2026.
//

#ifndef LAB25_1_ENUMS_H
#define LAB25_1_ENUMS_H
enum Lista {
    CABEZA=0,
};
enum Conductor {
    conducLic=0,
    conducNomb=1,
    conducRegPlaca=2,
    conducListFalta=3,

    cantNumConduc=4
};
enum Nodo {
    DATO=0,
    SIGUIENTE=1
};
enum Infraccion {
    infracLic=0,
    infracPlaca=1,
    infracFecha=2,
    infracTipoFalta=3,

    cantNumInfrac=4
};
#endif //LAB25_1_ENUMS_H
