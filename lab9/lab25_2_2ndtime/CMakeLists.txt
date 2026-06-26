cmake_minimum_required(VERSION 4.2)
project(lab25_2_2ndtime)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab25_2_2ndtime main.cpp
        Bibliotecas/Etiqueta.cpp
        Bibliotecas/Etiqueta.h
        Bibliotecas/Categoria.cpp
        Bibliotecas/Categoria.h
        Bibliotecas/Comentario.cpp
        Bibliotecas/Comentario.h
        Bibliotecas/Streamer.cpp
        Bibliotecas/Streamer.h
        Bibliotecas/SistemaDeGestion.cpp
        Bibliotecas/SistemaDeGestion.h)
