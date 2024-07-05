//
// Created by LABCFD on 7/5/2024.
//

#ifndef GERADORDADOSSAIDA_H
#define GERADORDADOSSAIDA_H

class DadosEntradaModelo;
class DadosSaidaModelo;

class GeradorDadosSaida {
private:
    const DadosEntradaModelo *entrada;
    DadosSaidaModelo *saida;
public:
    explicit GeradorDadosSaida(const DadosEntradaModelo *entrada);
    void gerar();
    DadosSaidaModelo *getDadosSaida();
};


#endif //GERADORDADOSSAIDA_H
