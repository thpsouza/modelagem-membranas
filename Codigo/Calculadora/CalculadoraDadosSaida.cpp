/**
 * @file CalculadoraDadosSaida.cpp
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief
 * @version 0.1
 * @date 2024-07-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "CalculadoraDadosSaida.h"
#include "../Entrada/DadosEntradaModelo.h"
#include "../Saida/DadosSaidaModelo.h"

/**
 * @brief Construtor da classe base da calculadora de dados de saída. Gera um unique_ptr da classe 'DadosSaidaModelo'.
 * @param entrada : Ponteiro para um objeto da classe de dados de entrada.
 */
CalculadoraDadosSaida::CalculadoraDadosSaida(const DadosEntradaModelo* entrada) :
    dadosPtr(std::make_unique<DadosSaidaModelo>()),
    entrada(entrada)
{
}

/**
 * @brief Método base para calcular os dados de saída. Reimplemetado para cada caso.
 * 
 * @return DadosSaidaModelo* 
 */
DadosSaidaModelo *CalculadoraDadosSaida::calcular() {
    return nullptr;
}

