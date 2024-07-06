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

    /// SEGFAULT NO GETTER E NO SETTER DOS DADOS DE SAIDA
    gerador.gerar();
    dados = *gerador.getDadosSaida();
    porosidade = dados.getPorosidade();

    // Output
    std::cout << "Porosidade: " << porosidade << std::endl;
}
