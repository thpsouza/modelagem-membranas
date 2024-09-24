/**
 * @file DadosEntradaModelo.h
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief Arquivo com a classe de dados de entrada do programa.
 * @version 0.1
 * @date 2024-07-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef DADOSENTRADAMODELO_H
#define DADOSENTRADAMODELO_H

/**
 * @brief Classe de entrada de dados para os cálculos do modelo. Aceita a geometria do volume de controle, a distribuição
 * de fibras, tal como o empacotamento e volume do VC.
 */
class DadosEntradaModelo{
public:
    enum TipoGeometria
    {
        CuboPerfeito,
        Esfera,
        Cilindro
    };
    enum TipoDistribuicao
    {
        UniformeEstruturada1D,
        UniformeAlternada1D
    };
    struct DadosModulo {
        int numTotalFibras{0};
        double areaTotalMembrana{0};
        double volumeTotalModulo{0};
    };
    struct DadosVC {
        TipoGeometria geometria{CuboPerfeito};
        TipoDistribuicao distribuicao{UniformeEstruturada1D};
        double diametroFibra{0};
        double volumeVC{0};
        int numFibrasVC{0};
        double distanciaFibras{0};
        double empacotamento{0};
        //double razaoComprimentoDiametroFibra{0};
        //double dimensoesVC[3]{0};
    };


    DadosEntradaModelo() = default;

    DadosEntradaModelo(const DadosVC &dadosVC, const DadosModulo &dadosModulo);

    [[nodiscard]] const DadosModulo &getDadosModulo() const;
    [[nodiscard]] const DadosVC &getDadosVC() const;

//    DadosEntradaModelo(TipoGeometria geometria, TipoDistribuicao distribuicao,
//                       int numTotalFibras, double areaTotalMembrana, double volumeTotalModulo, double diametroFibra,
//                       double volumeVC, int numFibrasVC, double distanciaFibras,
//                       double empacotamento, double razaoComprimentoDiametroFibra);
//    [[nodiscard]] TipoGeometria getGeometria() const;
//    [[nodiscard]] TipoDistribuicao getDistribuicao() const;
//    [[nodiscard]] double getEmpacotamento() const;
//    [[nodiscard]] int getNumTotalFibras() const;
//    [[nodiscard]] double getAreaTotalMembrana() const;
//    [[nodiscard]] double getDiametroFibra() const;
//    [[nodiscard]] double getVolumeTotalModulo() const;
//    [[nodiscard]] double getDistanciaFibras() const;
//    [[nodiscard]] int getNumFibrasVC() const;
//    [[nodiscard]] double getVolumeVC() const;
//    double razaoComprimentoDiametroFibra;

private:
    DadosModulo dadosModulo;
    DadosVC dadosVC;
};


#endif //DADOSENTRADAMODELO_H
