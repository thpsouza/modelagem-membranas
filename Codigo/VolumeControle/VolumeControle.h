
//
// Created by LABCFD on 7/11/2024.
//

#ifndef MODELAGEM_MEMBRANAS_VOLUMECONTROLE_H
#define MODELAGEM_MEMBRANAS_VOLUMECONTROLE_H

#include "../Entrada/DadosEntradaModelo.h"

class FibraBase;
class GeometriaBase;

class VolumeControle {
private:
    double porosidade;
    int numFibras;
    double areaTransferenciaTotal;
    FibraBase *fibra;
    GeometriaBase *geometria;

public:
    VolumeControle(GeometriaBase *geometria, FibraBase *fibra);

    void construirModelo(DadosEntradaModelo::TipoDistribuicao tipoDistribuicao);

    void calcularPorosidade();
    void calcularNumFibras();
    void calcularAreaTotalTransferencia();

    void setPorosidade(double valor);
    void setNumFibras(int valor);
    void setAreaTransferenciaTotal(double valor);

    double getPorosidade() const;
    int getNumFibras() const;
    double getAreaTransferenciaTotal() const;
};


#endif //MODELAGEM_MEMBRANAS_VOLUMECONTROLE_H
