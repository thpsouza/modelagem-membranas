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

    DadosEntradaModelo(TipoGeometria geometria, TipoDistribuicao distribuicao, double empacotamento, double volume);

    TipoGeometria getGeometria() const;
    TipoDistribuicao getDistribuocao() const;
    double getEmpacotamento() const;
    double getVolume() const;

private:
    TipoGeometria geometria;
    TipoDistribuicao distribuicao;
    double empacotamento;
    double volume;
};


#endif //DADOSENTRADAMODELO_H
