/**
 * @file CalculadoraDadosSaida.h
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief Arquivo com a classe calculadora base
 * @version 0.1
 * @date 2024-07-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef CALCULADORADADOSSAIDA_H
#define CALCULADORADADOSSAIDA_H

#include <memory>

class DadosSaidaModelo;
class DadosEntradaModelo;

/**
 * @brief Classe base para calcular os dados de saída do modelo.
 */
class CalculadoraDadosSaida {
protected:
    const DadosEntradaModelo* entrada;
    std::unique_ptr<DadosSaidaModelo> dadosPtr;

public:
    explicit CalculadoraDadosSaida(const DadosEntradaModelo* entrada);
    virtual DadosSaidaModelo* calcular();
};


#endif //CALCULADORADADOSSAIDA_H
