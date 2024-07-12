//
// Created by LABCFD on 7/5/2024.
//

#include <iostream>
#include "Entrada/DadosEntradaModelo.h"
#include "Gerador/GeradorDadosSaida.h"
#include "Saida/DadosSaidaModelo.h"
#include "VolumeControle/CuboPerfeito.h"


void testeEntradaSaidaDados() {
    double porosidade;
    DadosEntradaModelo dadosEntrada {DadosEntradaModelo::CuboPerfeito, 0.8, 1};
    DadosSaidaModelo dadosSaida;
    GeradorDadosSaida gerador {&dadosEntrada};

    /**
     *
     * ERRO ENCONTRADO:
     *      SEGFAULT NO SETTER DOS DADOS DE SAIDA NA FUNÇÃO 'CALCULAR' DA CLASSE 'CalculadoraCuboPerfeitoDadosSaida'
     * SOLUÇÃO ENCONTRADA:
     *      Declarei uma variável da classe, para poder setar o valor, e então retornei um ponteiro que
     *      aponta para essa variável.
     * SOLUÇÃO ALTERNATIVA (feito na branch 'home'):
     *      Modificar a classe geradora para receber a referência de uma instância classe de saida, de forma a
     *      modificá-la "in-place" não necessitando do metodo getDadosSaida.
     */
    gerador.gerar();
    dadosSaida = *gerador.getDadosSaida();
    porosidade = dadosSaida.getPorosidade();

    // Output
    std::cout << "Porosidade: " << porosidade << std::endl;
}


void testeGeometria() {
    double aresta = 5.0;
    double vol;

    CuboPerfeito cubo {aresta};
    cubo.calcularAreaFace();
    cubo.calcularVolume();
    vol = cubo.getVolume();

    std::cout << "Volume cubo: " << vol << std::endl;
}


int main() {
    testeEntradaSaidaDados();
    testeGeometria();


    return 0;
}
