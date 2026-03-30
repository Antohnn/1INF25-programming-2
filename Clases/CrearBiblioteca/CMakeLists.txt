cmake_minimum_required(VERSION 4.2)
project(CrearBiblioteca)

set(CMAKE_CXX_STANDARD 20)

add_library(MisFunciones STATIC MisBibliotecas/funciones.cpp)

add_executable(CrearBiblioteca main.cpp)

target_link_libraries(CrearBiblioteca MisFunciones)
