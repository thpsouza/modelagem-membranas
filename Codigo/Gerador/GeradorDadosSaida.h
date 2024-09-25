/**
 * @file GeradorDadosSaida.h
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief Arquivo com a classe de dados de saída do programa.
 * @version 0.1
 * @date 2024-07-05
 *
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef GERADORDADOSSAIDA_H
#define GERADORDADOSSAIDA_H

class DadosEntradaModelo;
class DadosSaidaModelo;

/**
 * @brief Classe geradora dos dados de saída, com base nos dados de entrada.
 */
class GeradorDadosSaida {
private:
    const DadosEntradaModelo *entrada;
    DadosSaidaModelo *saida;
public:
    explicit GeradorDadosSaida(const DadosEntradaModelo *entrada);

    void gerar();
    void gerarCuboPerfeito();
    void gerarCilindroPerfeito();
    void gerarEsferaPerfeita();
    DadosSaidaModelo *getDadosSaida();

};


#endif //GERADORDADOSSAIDA_H
