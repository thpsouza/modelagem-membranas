//
// Created by LABCFD on 7/11/2024.
//

#ifndef MODELAGEM_MEMBRANAS_CUBOPERFEITO_H
#define MODELAGEM_MEMBRANAS_CUBOPERFEITO_H

#include "GeometriaBase.h"

class CuboPerfeito : public GeometriaBase {
private:
    double aresta;
public:
    CuboPerfeito(double aresta);

    void calcularAreaFace() override;
    void calcularVolume() override;
    void setAresta(double valor);
    double getAresta() const;

};


#endif //MODELAGEM_MEMBRANAS_CUBOPERFEITO_H
