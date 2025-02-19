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
    double empacotamento;
    double porosidade;
    int numFibras;
    double EspacamentoFibras;
    double areaTransferenciaTotal;
    const FibraBase *fibra;
    const GeometriaBase *geometria;
    const DadosEntradaModelo *entrada;
    double teste;

public:
    VolumeControle(const GeometriaBase *geometria, const FibraBase *fibra, const DadosEntradaModelo *entrada);

    void construirModelo();
    void calcularEmpacotamento();
    void calcularPorosidade();
    void calcularNumFibras();
    void calcularEspacamentoFibras();
    void calcularAreaTotalTransferencia();

    // Metodos auxiliares
    void calcularAnguloSobreposicao();
    void calcularComprimentoAuxiliar();
    void calcularCoordenadasFibras();
    void calcularAreaSobreposicao();
    void calcularRazaoAreas();
    void calcularNumeroSobreposicoes();
    void calcularNumeroEfetivoDeFibras();
    void calcularAnguloComplementar();
    void calcularPerimetroTotal();

    void setEmpacotamento(double valor);
    void setPorosidade(double valor);
    void setNumFibras(int valor);
    void setEspacamentoFibras(double valor);
    void setAreaTransferenciaTotal(double valor);

    double getEmpacotamento() const;
    double getPorosidade() const;
    int getNumFibras() const;
    double getEspacamentoFibras() const;
    double getAreaTransferenciaTotal() const;
};


#endif //MODELAGEM_MEMBRANAS_VOLUMECONTROLE_H
