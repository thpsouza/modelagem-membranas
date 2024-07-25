//
// Created by LABCFD on 7/5/2024.
//

#ifndef CALCULADORACUBOPERFEITODADOSSAIDA_H
#define CALCULADORACUBOPERFEITODADOSSAIDA_H

#include "CalculadoraDadosSaida.h"

class CalculadoraCuboPerfeitoDadosSaida : public CalculadoraDadosSaida {
public:
    explicit CalculadoraCuboPerfeitoDadosSaida(const DadosEntradaModelo* entrada);

    DadosSaidaModelo* calcular() override;
};


#endif //CALCULADORACUBOPERFEITODADOSSAIDA_H
