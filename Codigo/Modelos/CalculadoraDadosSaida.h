//
// Created by LABCFD on 7/5/2024.
//

#ifndef CALCULADORADADOSSAIDA_H
#define CALCULADORADADOSSAIDA_H

class DadosSaidaModelo;

class CalculadoraDadosSaida {
public:
    virtual void calcular(DadosSaidaModelo *dados);
};


#endif //CALCULADORADADOSSAIDA_H
