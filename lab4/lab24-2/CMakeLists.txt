cmake_minimum_required(VERSION 4.2)
project(lab24_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab24_2 main.cpp
        Bibliotecas/BibliotecaGenerica.cpp
        Bibliotecas/BibliotecaGenerica.h
        Bibliotecas/ListaConEnteros.cpp
        Bibliotecas/ListaConEnteros.h
        Bibliotecas/Lista.cpp
        Bibliotecas/Lista.h
        Bibliotecas/enums.h
        Bibliotecas/ListaconRegistros.cpp
        Bibliotecas/ListaconRegistros.h)
