//
// Created by LABCFD on 7/11/2024.
//

#ifndef MODELAGEM_MEMBRANAS_FIBRACILINDRICA_H
#define MODELAGEM_MEMBRANAS_FIBRACILINDRICA_H

#include "FibraBase.h"

class FibraCilindrica : public FibraBase {
private:
    double areaTransversal;
public:
    // Construtor
    FibraCilindrica();
    // Calculadoras
    void calcularAreaTransversal();
    void calcularAreaSuperficial() override;
    void calcularVolume() override;
    // Set e Get
    void setAreaTransversal(double valor);
    double getAreaTransversal() const;
};


#endif //MODELAGEM_MEMBRANAS_FIBRACILINDRICA_H
