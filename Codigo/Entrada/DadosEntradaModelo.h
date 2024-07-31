//
// Created by LABCFD on 7/5/2024.
//

#ifndef DADOSENTRADAMODELO_H
#define DADOSENTRADAMODELO_H


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

    DadosEntradaModelo(TipoGeometria geometria, TipoDistribuicao distribuicao,
                       double empacotamento, double volume, double razaoComprimentoDiametroFibra);

    TipoGeometria getGeometria() const;
    TipoDistribuicao getDistribuicao() const;
    double getEmpacotamento() const;
    double getVolume() const;
    double razaoComprimentoDiametroFibra;

private:
    TipoGeometria geometria;
    TipoDistribuicao distribuicao;
    double empacotamento;
    double volume;
};


#endif //DADOSENTRADAMODELO_H
