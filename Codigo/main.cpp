//
// Created by LABCFD on 7/5/2024.
//

#include <iostream>
#include <vector>
#include <cmath>
#include "AnaliseGrafica/gerais.h"
#include "Entrada/DadosEntradaModelo.h"
#include "Gerador/GeradorDadosSaida.h"
#include "Saida/DadosSaidaModelo.h"


DadosSaidaModelo realizarCalculos(
        double empacotamento,
        double volume = 1,
        DadosEntradaModelo::TipoGeometria geometria = DadosEntradaModelo::CuboPerfeito,
        DadosEntradaModelo::TipoDistribuicao distribuicao = DadosEntradaModelo::UniformeUmaDirecao
){
    /// Não seria melhor passar também o objeto de saída e modificá-lo in-place?
    const DadosEntradaModelo dadosEntrada {geometria, distribuicao, empacotamento, volume};
    GeradorDadosSaida gerador {&dadosEntrada};
    gerador.gerar();
    return *gerador.getDadosSaida();
}


void testeEntradaSaidaDados() {
    DadosSaidaModelo dadosSaida = realizarCalculos(0.8);

    // Output
    print("Porosidade: ", dadosSaida.getPorosidade(), "\n"
          "Num Fibras: ", dadosSaida.getNumFibras(), "\n"
          "Area Total de Transferencia: ", dadosSaida.getAreaTotalTransferencia(), "\n");
}


void analisarDados(const char* path) {
    std::vector<std::string> propriedades {
            "Empacotamento", "Porosidade", "Numero de Fibras", "Area Total de trasferencia"
    };

    int N = 100;
    const double porosidadeMaximaTeorica = M_PI * sqrt(3) / 6;
    std::vector<double> empacotamentos = linspace(0, porosidadeMaximaTeorica, N);
    std::vector<double> porosidades(N);
    std::vector<double> numFibras(N);
    std::vector<double> AreaTotal(N);

    DadosSaidaModelo saida;
    for (int i = 0; i<N; i++) {
        saida = realizarCalculos(empacotamentos[i]);
        porosidades[i] = saida.getPorosidade();
        numFibras[i] = (double) saida.getNumFibras();
        AreaTotal[i] = saida.getAreaTotalTransferencia();
    }

    std::vector<std::vector<double>> Y {porosidades, numFibras, AreaTotal};
    ///

    exportarDados(path, propriedades, empacotamentos, Y);
}


int main(int argc, char* argv[]) {
    testeEntradaSaidaDados();

    //
    if (argc>1) {
        analisarDados(argv[1]);
    }
    return 0;
}
