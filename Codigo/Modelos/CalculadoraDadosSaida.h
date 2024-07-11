//
// Created by LABCFD on 7/5/2024.
//

#ifndef CALCULADORADADOSSAIDA_H
#define CALCULADORADADOSSAIDA_H

#include <memory>

class DadosSaidaModelo;

class CalculadoraDadosSaida {
protected:
    std::unique_ptr<DadosSaidaModelo> dadosPtr;

public:
    CalculadoraDadosSaida();

    virtual DadosSaidaModelo* calcular();
};


#endif //CALCULADORADADOSSAIDA_H
