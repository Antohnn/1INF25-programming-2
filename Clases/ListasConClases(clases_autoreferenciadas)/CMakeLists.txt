cmake_minimum_required(VERSION 4.2)
project(ListasConClases_clases_autoreferenciadas_)

set(CMAKE_CXX_STANDARD 20)

add_executable(ListasConClases_clases_autoreferenciadas_ main.cpp
        Bibliotecas/Nodo.cpp
        Bibliotecas/Nodo.h
        Lista.cpp
        Lista.h)
