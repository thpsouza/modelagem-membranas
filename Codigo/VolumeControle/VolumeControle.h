/**
 * @file VolumeControle.h
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief Arquivo com a classe para definir o volume de controle, com geometria e distribuicao de fibras quaisqueres.
 * @version 0.1
 * @date 2024-07-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#ifndef MODELAGEM_MEMBRANAS_VOLUMECONTROLE_H
#define MODELAGEM_MEMBRANAS_VOLUMECONTROLE_H


class FibraBase;
class GeometriaBase;
class DadosEntradaModelo;

/**
 * @brief Classe para definir o volume de controle a se considerar nos cálculos do modelo.
 */
class VolumeControle {
private:
    double raioFibra;
    double empacotamento;
    double porosidade;
    int numFibras;
    double espacamentoFibras;
    double areaTransferenciaTotal;
    const FibraBase *fibra;
    const GeometriaBase *geometria;
    const DadosEntradaModelo *entrada;
    const double FatorEspacamentoMaximoFibras = 2.00;
    const double FatorEspacamentoMinimoFibras = -0.1;

public:
    VolumeControle(const GeometriaBase *geometria, const FibraBase *fibra, const DadosEntradaModelo *entrada);

    void construirModelo();

    // Metodos auxiliares
    double calcularAnguloSobreposicao() const;
    double calcularComprimentoAuxiliar() const;
    double calcularNumeroEfetivoDeFibras() const;
    double calcularPerimetroTotal() const;

    // Métodos principais
    void calcularEspacamentoFibras();
    void calcularEmpacotamento();
    void calcularPorosidade();
    void calcularNumFibras();
    void calcularAreaTotalTransferencia();
    //double calcularCoordenadasFibras();

    // Setters e Getters
    void setEmpacotamento(double valor);
    void setPorosidade(double valor);
    void setNumFibras(int valor);
    void setEspacamentoFibras(double valor);
    void setAreaTransferenciaTotal(double valor);

    double getEspacamentoFibras() const;
    double getFatorEspacamentoMaximo() const;
    double getFatorEspacamentoMinimo() const;
    double getEmpacotamento() const;
    double getPorosidade() const;
    int getNumFibras() const;
    double getAreaTransferenciaTotal() const;

};


#endif //MODELAGEM_MEMBRANAS_VOLUMECONTROLE_H
