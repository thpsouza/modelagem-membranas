//
// Created by LABCFD on 7/5/2024.
//

#include <iostream>
#include "Entrada/DadosEntradaModelo.h"
#include "Gerador/GeradorDadosSaida.h"
#include "Saida/DadosSaidaModelo.h"

int main() {
    double porosidade;
    DadosEntradaModelo dadosEntrada {DadosEntradaModelo::CuboPerfeito, 0.8, 1};
    DadosSaidaModelo dados;
    GeradorDadosSaida gerador {&dadosEntrada};

    /**
     * ERRO ENCONTRADO:
     *     SEGFAULT NO SETTER DOS DADOS DE SAIDA NA FUNÇÃO 'CALCULAR' DA CLASSE 'CalculadoraCuboPerfeitoDadosSaida'
     * SOLUÇÃO ENCONTRADA:
     *     Declarei uma variável da classe, para poder setar o valor, e então retornei um ponteiro que
     *     aponta para essa variável.
     */
    gerador.gerar();
    dados = *gerador.getDadosSaida();
    porosidade = dados.getPorosidade();

    // Output
    std::cout << "Porosidade: " << porosidade << std::endl;

    return 0;
}
