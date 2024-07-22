//
// Created by LABCFD on 7/5/2024.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "AnaliseGrafica/gerais.h"
#include "Entrada/DadosEntradaModelo.h"
#include "Gerador/GeradorDadosSaida.h"
#include "Saida/DadosSaidaModelo.h"
#include "VolumeControle/Geometrias/CuboPerfeito.h"


void testeEntradaSaidaDados() {
    double porosidade;
    int numFibras;
    double areaTotalTransferencia;
    DadosEntradaModelo dadosEntrada {DadosEntradaModelo::CuboPerfeito,
                                     DadosEntradaModelo::UniformeUmaDirecao,
                                     0.8, 1};
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
    numFibras = dadosSaida.getNumFibras();
    areaTotalTransferencia = dadosSaida.getAreaTotalTransferencia();

    // Output
    std::cout << "Porosidade: " << porosidade << std::endl;
    std::cout << "Num Fibras: " << numFibras << std::endl;
    std::cout << "Area Total de Transferencia: " << areaTotalTransferencia << std::endl;
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


void exportarDados(const std::string& path, const std::vector<std::string>& propriedades,
                   const std::vector<double>& X, const std::vector<std::vector<double>>& Y) {
    std::ofstream file;
    file.open(path);


    // Vetor x contém os dados do eixo X para plotar. Enquanto a matriz Y contém os dados a serem plotados no eixo Y.
    // Cada série de propriedade será inserida ao longo de uma coluna. A primeira linha contém os headers.

    // Headers
    for (const auto& p : propriedades) {
        if (p != propriedades[0]) {
            file << ";";
        }
        file << p;
    } file << std::endl;

    // Dados
    for (int j = 0; j < X.size(); j++) {
        file << X[j] << ";";
        for (const auto& y : Y) {
            if (y != Y[0]) {
                file << ";";
            }
            file << y[j];
        } file << std::endl;
    }
    file.close();
}


int main(int argc, char* argv[]) {
    //testeEntradaSaidaDados();
    //testeGeometria();

    // Script a partir da análise
    if (argc > 1) {
        std::vector<std::string> propriedades {"Empacotamento", "Porosidade", "Numero de Fibras","Area Total de trasferencia"};
        auto X = linspace(1, 10, 50);
        std::vector<std::vector<double>> Y;
        for (int i = 1; i<4; i++) {
            auto y = transform(X, [&](double k) {return k*i;});
            Y.push_back(y);
        }
        exportarDados(argv[1], propriedades, X, Y);
    }


    return 0;
}
