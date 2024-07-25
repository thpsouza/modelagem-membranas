//
// Created by LABCFD on 7/5/2024.
//

#ifndef CALCULADORADADOSSAIDA_H
#define CALCULADORADADOSSAIDA_H

#include <memory>

class DadosSaidaModelo;
class DadosEntradaModelo;

class CalculadoraDadosSaida {
protected:
    const DadosEntradaModelo* entrada;
    std::unique_ptr<DadosSaidaModelo> dadosPtr;

public:
    explicit CalculadoraDadosSaida(const DadosEntradaModelo* entrada);
    virtual DadosSaidaModelo* calcular();
};


#endif //CALCULADORADADOSSAIDA_H
