cmake_minimum_required(VERSION 4.2)
project(lab24_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab24_2 main.cpp
        Clases/Cliente.cpp
        Clases/Cliente.h
        Clases/Plato.cpp
        Clases/Plato.h
        Clases/Restaurante.cpp
        Clases/Restaurante.h
        Clases/Funciones.cpp
        Clases/Funciones.h
        Clases/Funciones.cpp)
