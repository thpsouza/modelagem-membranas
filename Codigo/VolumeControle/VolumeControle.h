
//
// Created by LABCFD on 7/11/2024.
//

#ifndef MODELAGEM_MEMBRANAS_VOLUMECONTROLE_H
#define MODELAGEM_MEMBRANAS_VOLUMECONTROLE_H


class FibraBase;
class GeometriaBase;
class DadosEntradaModelo;

class VolumeControle {
private:
    double porosidade;
    int numFibras;
    double areaTransferenciaTotal;
    const FibraBase *fibra;
    const GeometriaBase *geometria;
    const DadosEntradaModelo *entrada;

public:
    VolumeControle(const GeometriaBase *geometria, const FibraBase *fibra, const DadosEntradaModelo *entrada);

    void construirModelo();
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
