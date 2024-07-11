
//
// Created by LABCFD on 7/11/2024.
//

#ifndef MODELAGEM_MEMBRANAS_VOLUMECONTROLE_H
#define MODELAGEM_MEMBRANAS_VOLUMECONTROLE_H


class VolumeControle {
private:
    double areaTransferenciaTotal;
    double porosidade;
public:
    VolumeControle();

    virtual void calcularAreaTotalTransferencia();
    virtual void calcularPorosidade();

    void setAreaTransferenciaTotal(double valor);
    void setPorosidade(double valor);
    double getAreaTransferenciaTotal() const;
    double getPorosidade() const;
};


#endif //MODELAGEM_MEMBRANAS_VOLUMECONTROLE_H
