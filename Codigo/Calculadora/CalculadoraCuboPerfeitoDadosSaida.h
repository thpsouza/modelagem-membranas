/**
 * @file CalculadoraCuboPerfeitoDadosSaida.h
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief Arquivo com a classe calculadora para um volume de controle com geometria de cubo perfeito.
 * @version 0.1
 * @date 2024-07-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef CALCULADORACUBOPERFEITODADOSSAIDA_H
#define CALCULADORACUBOPERFEITODADOSSAIDA_H

#include "CalculadoraDadosSaida.h"

/**
 * @brief Classe calculadora dos dados de saída do modelo, para uma geometria de cubo perfeito, com método 'calcular' 
 * da classe base reimplementado para essa geometria.
 */
class CalculadoraCuboPerfeitoDadosSaida : public CalculadoraDadosSaida {
public:
    explicit CalculadoraCuboPerfeitoDadosSaida(const DadosEntradaModelo* entrada);

    DadosSaidaModelo* calcular() override;
};


#endif //CALCULADORACUBOPERFEITODADOSSAIDA_H
