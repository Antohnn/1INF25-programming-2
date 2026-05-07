cmake_minimum_required(VERSION 4.2)
project(lab24_2_2ndtime)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab24_2_2ndtime main.cpp
        Bibliotecas/BibliotecaGenerica.cpp
        Bibliotecas/BibliotecaGenerica.h
        Bibliotecas/ListaconEnteros.cpp
        Bibliotecas/ListaconEnteros.h
        Bibliotecas/enums.h
        Bibliotecas/ListaconRegistros.cpp
        Bibliotecas/ListaconRegistros.h)
