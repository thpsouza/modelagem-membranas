//
// Created by LABCFD on 7/5/2024.
//

#include <memory>
#include "GeradorDadosSaida.h"
#include "../Entrada/DadosEntradaModelo.h"
#include "../Saida/DadosSaidaModelo.h"
#include "../Modelos/CalculadoraDadosSaida.h"
#include "../Modelos/CalculadoraCuboPerfeitoDadosSaida.h"

GeradorDadosSaida::GeradorDadosSaida(const DadosEntradaModelo *entrada) :
    entrada(entrada)
{
}

void GeradorDadosSaida::gerador() {

    std::unique_ptr<CalculadoraDadosSaida> calculadora;

    // TODO Definir novos calculos
    switch (entrada->getGeometria()) {
        case DadosEntradaModelo::TipoGeometria::CuboPerfeito:
            calculadora = std::make_unique<CalculadoraCuboPerfeitoDadosSaida>();
            break;
        case DadosEntradaModelo::TipoGeometria::Cilindro:
            break;
        case DadosEntradaModelo::TipoGeometria::Esfera:
            break;
        default:
            ;
    }

    saida = calculadora->calcular();
}

DadosSaidaModelo *GeradorDadosSaida::getDadosSaida() {
    return saida;
}
