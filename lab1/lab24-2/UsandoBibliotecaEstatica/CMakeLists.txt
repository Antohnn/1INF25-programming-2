cmake_minimum_required(VERSION 4.2)
project(UsandoBibliotecaEstatica)

set(CMAKE_CXX_STANDARD 20)

add_executable(UsandoBibliotecaEstatica main.cpp
        Bibliotecas/FuncionesAuxiliares.cpp
        Bibliotecas/FuncionesAuxiliares.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Bibliotecas")

target_link_libraries(UsandoBibliotecaEstatica PRIVATE Sobrecarga)
