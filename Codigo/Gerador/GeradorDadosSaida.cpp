/**
 * @file GeradorDadosSaida.cpp
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief
 * @version 0.1
 * @date 2024-07-05
 *
 * @copyright Copyright (c) 2024
 * 
 */

#include <memory>
#include "GeradorDadosSaida.h"
#include "../Entrada/DadosEntradaModelo.h"
#include "../Saida/DadosSaidaModelo.h"
#include "../Calculadora/CalculadoraDadosSaida.h"
#include "../Calculadora/CalculadoraCuboPerfeitoDadosSaida.h"

/**
 * @brief Construtor da classe GeradorDadosSaida.
 * 
 * @param entrada : Ponteiro para um objeto da classe de entrada de dados.
 */
GeradorDadosSaida::GeradorDadosSaida(const DadosEntradaModelo *entrada) :
    entrada(entrada)
{
}

/**
 * @brief Função geradora dos dados de saída. Alterna o método de cálculo com base nas propriedades do volume de controle,
 * passadas nos dados de entrada.
 */
void GeradorDadosSaida::gerar() {
    std::unique_ptr<CalculadoraDadosSaida> calculadora;
    // TODO: Criar novos modelos para as demais geometrias
    switch (entrada->getDadosVC().geometria) {
        case DadosEntradaModelo::TipoGeometria::CuboPerfeito:
            calculadora = std::make_unique<CalculadoraCuboPerfeitoDadosSaida>(entrada);
            break;
        case DadosEntradaModelo::TipoGeometria::Cilindro:
//            calculadora = std::make_unique<CalculadoraCilindroDadosSaida>(entrada);
            break;
        case DadosEntradaModelo::TipoGeometria::Esfera:
//            calculadora = std::make_unique<CalculadoraEsferaDadosSaida>(entrada);
            break;
        default:
            ;
    }
    saida = calculadora->calcular();
}

void GeradorDadosSaida::gerarCuboPerfeito() {
    switch (entrada->getDadosVC().geometria) {
        case DadosEntradaModelo::TipoGeometria::CuboPerfeito:
            calculadora = std::make_unique<CalculadoraCuboPerfeitoDadosSaida>(entrada);
            break;
        case DadosEntradaModelo::TipoGeometria::Cilindro:
//            calculadora = std::make_unique<CalculadoraCilindroDadosSaida>(entrada);
            break;
        case DadosEntradaModelo::TipoGeometria::Esfera:
//            calculadora = std::make_unique<CalculadoraEsferaDadosSaida>(entrada);
            break;
        default:
            ;
    }
}

void GeradorDadosSaida::gerarCilindroPerfeito() {
    switch (entrada->getDadosVC().geometria){}
}

void GeradorDadosSaida::gerarEsferaPerfeita() {

}

/**
 * @brief Retorna um ponteiro para os dados de saída gerados.
 * @return DadosSaidaModelo*
 */
DadosSaidaModelo *GeradorDadosSaida::getDadosSaida() {
    return saida;
}

