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

    // Pesquisar para entender pq não estava funcionando:
    // std::unique_ptr<CalculadoraDadosSaida> calculadora;
    std::unique_ptr<CalculadoraCuboPerfeitoDadosSaida> calculadora;

    // TODO: Criar novos modelos para as demais geometrias
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
