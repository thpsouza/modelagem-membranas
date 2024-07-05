cmake_minimum_required(VERSION 3.27)
project(modelagem_membranas)

set(CMAKE_CXX_STANDARD 17)

include_directories(Entrada)
include_directories(Saida)

add_executable(modelagem_membranas main.cpp
        Entrada/DadosEntradaModelo.cpp
        Entrada/DadosEntradaModelo.h
        Saida/DadosSaidaModelo.cpp
        Saida/DadosSaidaModelo.h
        Gerador/GeradorDadosSaida.h
        CalculadoraDadosSaida.h
        Gerador/GeradorDadosSaida.cpp
        CalculadoraDadosSaida.cpp
        CalculadoraCuboPerfeitoDadosSaida.h
        CalculadoraCuboPerfeitoDadosSaida.cpp)
