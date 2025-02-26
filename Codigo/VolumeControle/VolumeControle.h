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
    int numFibras;
    double espacamentoFibras;
    double numEfetivoFibras;
    double perimetroTotalFibras;
    double empacotamento;
    double porosidade;
    double areaTransferenciaTotal;
    const FibraBase *fibra;
    const GeometriaBase *geometria;
    const DadosEntradaModelo *entrada;
    double toleranciaEspacamentoMinimo;
    double toleranciaEspacamentoMaximo;
    const double fatorEspacamentoMaximo = 2.00;
    const double fatorEspacamentoMinimo = -0.1;

public:
    VolumeControle(const GeometriaBase *geometria, const FibraBase *fibra, const DadosEntradaModelo *entrada);

    void construirModelo();

    // Metodos auxiliares
    double calcularAnguloSobreposicao() const;
    double calcularComprimentoAuxiliar() const;

    // Métodos principais
    void calcularEspacamentoFibras();
    void validarEspacamentoFibras() const;
    void calcularNumeroEfetivoDeFibras();
    void calcularPerimetroTotalFibras();
    void calcularEmpacotamento();
    void calcularPorosidade();
    void calcularAreaTotalTransferencia();
    // void calcularNumFibras();
    //double calcularCoordenadasFibras();

    // Setters e Getters
    void setEmpacotamento(double valor);
    void setPorosidade(double valor);
    void setNumFibras(int valor);
    void setEspacamentoFibras(double valor);
    void setnumEfetivoFibras(double valor);
    void setPerimetroTotalFibras(double valor);
    void setAreaTransferenciaTotal(double valor);

    int getNumFibras() const;
    double getEspacamentoFibras() const;
    double getFatorEspacamentoMaximo() const;
    double getFatorEspacamentoMinimo() const;
    double getNumEfetivoFibras() const;
    double getPerimetroTotalFibras() const;
    double getEmpacotamento() const;
    double getPorosidade() const;
    double getAreaTransferenciaTotal() const;

};


#endif //MODELAGEM_MEMBRANAS_VOLUMECONTROLE_H
