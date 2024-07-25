//
// Created by LABCFD on 7/12/2024.
//

#ifndef MODELAGEM_MEMBRANAS_DISTRIBUICAOUNIFORME_H
#define MODELAGEM_MEMBRANAS_DISTRIBUICAOUNIFORME_H

#include <cmath>
#include "DistribuicaoBase.h"

class DistribuicaoUniforme : public DistribuicaoBase {
    /// Supondo fibras cilindricas, que não se sobrepoem, em uma geometria cúbica.
private:
    const double porosidadeMaximaTeorica = M_PI * sqrt(3) / 6;
};


#endif //MODELAGEM_MEMBRANAS_DISTRIBUICAOUNIFORME_H
