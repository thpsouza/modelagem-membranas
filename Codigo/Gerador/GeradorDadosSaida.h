//
// Created by LABCFD on 7/5/2024.
//

#ifndef NEW_FOLDER_GERADORDADOSSAIDA_H
#define NEW_FOLDER_GERADORDADOSSAIDA_H

class DadosEntradaModelo;
class DadosSaidaModelo;

class GeradorDadosSaida {
private:
    const DadosEntradaModelo *entrada;
    DadosSaidaModelo *saida;
public:
    explicit GeradorDadosSaida(const DadosEntradaModelo *entrada);
    void gerador();
    DadosSaidaModelo *getDadosSaida();
};


#endif //NEW_FOLDER_GERADORDADOSSAIDA_H
