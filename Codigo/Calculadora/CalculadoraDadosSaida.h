//
// Created by LABCFD on 7/5/2024.
//

#ifndef CALCULADORADADOSSAIDA_H
#define CALCULADORADADOSSAIDA_H

#include <memory>
#include "../Entrada/DadosEntradaModelo.h"

class DadosSaidaModelo;

class CalculadoraDadosSaida {
protected:
    DadosEntradaModelo::TipoDistribuicao distribuicao;
    std::unique_ptr<DadosSaidaModelo> dadosPtr;


public:
    CalculadoraDadosSaida(DadosEntradaModelo::TipoDistribuicao distribuicao);

    virtual DadosSaidaModelo* calcular();
};


#endif //CALCULADORADADOSSAIDA_H
