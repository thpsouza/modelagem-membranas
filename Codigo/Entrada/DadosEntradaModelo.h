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

    DadosEntradaModelo(TipoGeometria geometria, double empacotamento, double volumeControle);

    TipoGeometria getGeometria() const;
    double getEmpacotamento() const;
    double getVolumeControle() const;

private:
    TipoGeometria geometria;
    double empacotamento;
    double volumeControle;
};


#endif //DADOSENTRADAMODELO_H
