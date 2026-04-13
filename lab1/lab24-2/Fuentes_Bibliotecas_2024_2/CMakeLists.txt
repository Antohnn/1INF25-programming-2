cmake_minimum_required(VERSION 4.2)
project(Fuentes_Bibliotecas_2024_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Fuentes_Bibliotecas_2024_2 main.cpp)

add_library(Sobrecarga STATIC Bibliotecas/Funciones.cpp)

target_link_libraries(Fuentes_Bibliotecas_2024_2 Sobrecarga)
