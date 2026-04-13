cmake_minimum_required(VERSION 4.2)
project(Fuentes_Biblioteca_2023_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Fuentes_Biblioteca_2023_2 main.cpp)

add_library(MisFunciones STATIC MisBibliotecas/Funciones.cpp)

target_link_libraries(Fuentes_Biblioteca_2023_2 MisFunciones)


