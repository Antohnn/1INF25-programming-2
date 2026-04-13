cmake_minimum_required(VERSION 4.2)
project(Prueba_Biblioteca_2023_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Prueba_Biblioteca_2023_2 main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/MisBibliotecas")

target_link_libraries(Prueba_Biblioteca_2023_2 PRIVATE MisFunciones)
