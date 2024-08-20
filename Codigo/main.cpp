//
// Created by LABCFD on 7/5/2024.
//

#include <iostream>
#include <vector>
#include <cmath>
#include "Gerais/gerais.h"
#include "Entrada/DadosEntradaModelo.h"
#include "Gerador/GeradorDadosSaida.h"
#include "Saida/DadosSaidaModelo.h"

struct Args {
    DadosEntradaModelo::TipoGeometria geometria = DadosEntradaModelo::CuboPerfeito;
    DadosEntradaModelo::TipoDistribuicao distribuicao = DadosEntradaModelo::UniformeUmaDirecao;
    int numTotalFibras = 0;
    double areaTotalMembrana = 0.0;
    double volumeTotalModulo = 0.0;
    double volumeVC = 0.0;
    double diametroFibra = 0.0;

    double empacotamento = 0.0;
    double razaoComprimentoDiametroFibra = 0.0;
};

DadosSaidaModelo realizarCalculos(Args *args) {
    /// Não seria melhor passar também o objeto de saída e modificá-lo in-place?
    const DadosEntradaModelo dadosEntrada {
            args->geometria, args->distribuicao,
            args->areaTotalMembrana, args->numTotalFibras, args->diametroFibra,
            args->volumeTotalModulo, args->volumeVC,
            args->empacotamento, args->razaoComprimentoDiametroFibra
    };
    GeradorDadosSaida gerador {&dadosEntrada};
    gerador.gerar();
    return *gerador.getDadosSaida();
}


void analisarDados(const char* path, double razaoComprimentoDiametroFibra = 10) {
    std::vector<std::string> cabecalhos {
            "Empacotamento", "Porosidade", "Numero de Fibras", "Area Total de trasferencia"
    };

    int N = 100;
    const double porosidadeMaximaTeorica = 1 - M_PI * sqrt(3) / 6; // Geometria cúbica / Distribuicao uniforme
    std::vector<double> empacotamentos = linspace(0,  1 - porosidadeMaximaTeorica, N);
    std::vector<double> porosidades(N);
    std::vector<double> numFibras(N);
    std::vector<double> AreaTotal(N);

    DadosSaidaModelo saida;
    Args args;
    args.razaoComprimentoDiametroFibra = razaoComprimentoDiametroFibra;
    args.volumeTotalModulo = 1;
    for (int i = 0; i<N; i++) {
        args.empacotamento = empacotamentos[i];
        saida = realizarCalculos(&args);
        porosidades[i] = saida.getPorosidade();
        numFibras[i] = (double) saida.getNumFibras();
        AreaTotal[i] = saida.getAreaTotalTransferencia();
    }
    std::vector<std::vector<double>> propriedades {porosidades, numFibras, AreaTotal};

    exportarDados(path, cabecalhos, empacotamentos, propriedades);
}


void testeEntradaSaidaDados() {
    Args args;

    // Parâmetros de entrada do módulo de membranas:
    args.numTotalFibras = 30000;
    args.areaTotalMembrana = 2.1;
    args.diametroFibra = 300e-6;
    args.volumeTotalModulo = 8.9 * 8.9 * M_PI_4 * 14.2 * 1e-6;

    // Volume de controle escolhido:
    args.geometria = DadosEntradaModelo::CuboPerfeito;
    args.distribuicao = DadosEntradaModelo::UniformeUmaDirecao;
    args.volumeVC = args.volumeTotalModulo;

    // Output
    DadosSaidaModelo dadosSaida = realizarCalculos(&args);
    print("Porosidade: ", dadosSaida.getPorosidade(),
          "\nNum Fibras: ", dadosSaida.getNumFibras(),
          "\nArea Total de Transferencia: ", dadosSaida.getAreaTotalTransferencia()
          );
}


int main(int argc, char* argv[]) {
    if (argc == 3) {
        analisarDados(argv[1], atof(argv[2]));
    } else {
        testeEntradaSaidaDados();
    }
    return 0;
}
