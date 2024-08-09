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
        UniformeUmaDirecao
    };
    DadosEntradaModelo() = default;

    DadosEntradaModelo(TipoGeometria geometria, TipoDistribuicao distribuicao,
                       double empacotamento, double volume, double razaoComprimentoDiametroFibra);

    DadosEntradaModelo(TipoGeometria geometria, TipoDistribuicao distribuicao,
                       double areaMembrana, int numFibras, double diametroFibra);

    DadosEntradaModelo(TipoGeometria geometria, TipoDistribuicao distribuicao,
                       double areaMembrana, int numFibras, double diametroFibra,
                       double empacotamento, double volume, double razaoComprimentoDiametroFibra);

    [[nodiscard]] TipoGeometria getGeometria() const;
    [[nodiscard]] TipoDistribuicao getDistribuicao() const;
    [[nodiscard]] double getEmpacotamento() const;
    [[nodiscard]] double getAreaMembrana() const;
    [[nodiscard]] int getNumFibras() const;
    [[nodiscard]] double getDiametroFibra() const;
    [[nodiscard]] double getVolume() const;
    double razaoComprimentoDiametroFibra;

private:
    TipoGeometria geometria;
    TipoDistribuicao distribuicao;
    double diametroFibra;
    double empacotamento;
    double areaMembrana;
    int numFibras;
    double volume;
};


#endif //DADOSENTRADAMODELO_H
