//
// Created by LABCFD on 7/5/2024.
//

#ifndef CALCULADORACUBOPERFEITODADOSSAIDA_H
#define CALCULADORACUBOPERFEITODADOSSAIDA_H

#include "CalculadoraDadosSaida.h"

class CalculadoraCuboPerfeitoDadosSaida : public CalculadoraDadosSaida {
public:
    virtual void calcular(DadosSaidaModelo *dados);
};


#endif //CALCULADORACUBOPERFEITODADOSSAIDA_H
