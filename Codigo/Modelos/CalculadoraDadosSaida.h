//
// Created by LABCFD on 7/5/2024.
//

#ifndef CALCULADORADADOSSAIDA_H
#define CALCULADORADADOSSAIDA_H

class DadosSaidaModelo;

class CalculadoraDadosSaida {
protected:
    virtual DadosSaidaModelo* calcular();
};


#endif //CALCULADORADADOSSAIDA_H
