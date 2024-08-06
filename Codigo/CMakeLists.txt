cmake_minimum_required(VERSION 3.27)
project(modelagem_membranas)

set(CMAKE_CXX_STANDARD 17)

include_directories(Entrada)
include_directories(Saida)
include_directories(Gerador)
include_directories(Calculadora)
include_directories(VolumeControle)
include_directories(Mistura)

add_executable(modelagem_membranas main.cpp
        Entrada/DadosEntradaModelo.h
        Entrada/DadosEntradaModelo.cpp
        Saida/DadosSaidaModelo.h
        Saida/DadosSaidaModelo.cpp
        Gerador/GeradorDadosSaida.h
        Gerador/GeradorDadosSaida.cpp
        Calculadora/CalculadoraDadosSaida.h
        Calculadora/CalculadoraDadosSaida.cpp
        Calculadora/CalculadoraCuboPerfeitoDadosSaida.h
        Calculadora/CalculadoraCuboPerfeitoDadosSaida.cpp
        VolumeControle/VolumeControle.h
        VolumeControle/VolumeControle.cpp
        VolumeControle/Geometrias/GeometriaBase.h
        VolumeControle/Geometrias/GeometriaBase.cpp
        VolumeControle/Geometrias/CuboPerfeito.h
        VolumeControle/Geometrias/CuboPerfeito.cpp
        VolumeControle/Fibras/FibraBase.h
        VolumeControle/Fibras/FibraBase.cpp
        VolumeControle/Fibras/FibraCilindrica.h
        VolumeControle/Fibras/FibraCilindrica.cpp
        VolumeControle/Distribuicoes/DistribuicaoBase.h
        VolumeControle/Distribuicoes/DistribuicaoBase.cpp
        VolumeControle/Distribuicoes/DistribuicaoUniforme.h
        VolumeControle/Distribuicoes/DistribuicaoUniforme.cpp
        AnaliseGrafica/gerais.h
        AnaliseGrafica/gerais.cpp
)