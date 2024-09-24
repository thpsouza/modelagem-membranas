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


DadosSaidaModelo realizarCalculos(const DadosEntradaModelo::DadosVC &dadosVC, const DadosEntradaModelo::DadosModulo &dadosModulo) {
    /// Não seria melhor passar também o objeto de saída e modificá-lo in-place?
    const DadosEntradaModelo dadosEntrada {dadosVC, dadosModulo};
    GeradorDadosSaida gerador {&dadosEntrada};
    gerador.gerar();
    return *gerador.getDadosSaida();
}


void analisarDados(const char* path, double razaoComprimentoDiametroFibra = 10) {
    /// TODO: Reescrever - Parou de funcionar com as modificações feitas
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
    DadosEntradaModelo::DadosModulo argsModulo;
    DadosEntradaModelo::DadosVC argsVC;
    //argsVC.razaoComprimentoDiametroFibra = razaoComprimentoDiametroFibra;
    argsModulo.volumeTotalModulo = 1;
    for (int i = 0; i<N; i++) {
        argsVC.empacotamento = empacotamentos[i];
        saida = realizarCalculos(argsVC, argsModulo);
        porosidades[i] = saida.getPorosidade();
        numFibras[i] = (double) saida.getNumFibras();
        AreaTotal[i] = saida.getAreaTotalTransferencia();
    }
    std::vector<std::vector<double>> propriedades {porosidades, numFibras, AreaTotal};

    exportarDados(path, cabecalhos, empacotamentos, propriedades);
}


void testeEntradaSaidaDados() {
    // Parâmetros reais do módulo de membranas:
    DadosEntradaModelo::DadosModulo argsModulo;
    argsModulo.numTotalFibras = 30000;
    argsModulo.areaTotalMembrana = 2.1;
    argsModulo.volumeTotalModulo = 8.9 * 8.9 * M_PI_4 * 14.2 * 1e-6;

    // Volume de controle escolhido:
    DadosEntradaModelo::DadosVC argsVC;
    argsVC.diametroFibra = 300e-6;
    argsVC.distanciaFibras = 0.0;
    argsVC.numFibrasVC = 4;
    argsVC.geometria = DadosEntradaModelo::CuboPerfeito;
    argsVC.distribuicao = DadosEntradaModelo::UniformeEstruturada1D;
    argsVC.volumeVC = argsModulo.volumeTotalModulo;

    // Output
    DadosSaidaModelo dadosSaida = realizarCalculos(argsVC, argsModulo);
    print("Porosidade: ", dadosSaida.getPorosidade(),
          "\nNum Fibras: ", dadosSaida.getNumFibras(),
          "\nArea Total de Transferencia: ", dadosSaida.getAreaTotalTransferencia()
          );
}


int main(int argc, char* argv[]) {
    if (argc == 3) {
        //analisarDados(argv[1], atof(argv[2]));
    } else {
        testeEntradaSaidaDados();
    }
    return 0;
}
