/**
 * @file VolumeControle.cpp
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <cmath>
#include <memory>
#include "../Entrada/DadosEntradaModelo.h"
#include "VolumeControle.h"
#include "Geometrias/GeometriaBase.h"
#include "Fibras/FibraBase.h"
#include "Distribuicoes/DistribuicaoBase.h"
#include "Distribuicoes/DistribuicaoUniformeAlternada.h"
#include "Distribuicoes/DistribuicaoUniformeEstruturada.h"

/**
 * @brief Construtor do volume de controle.
 * 
 * @param geometria : Ponteiro para um objeto da classe de geometria do volume de controle.
 * @param fibra : Ponteiro para um objeto da classe de geometria da fibra.
 * @param entrada : Ponteiro para um objeto da classe de dados de entrada.
 */
VolumeControle::VolumeControle(const GeometriaBase *geometria,
                               const FibraBase *fibra,
                               const DadosEntradaModelo *entrada) :
    geometria(geometria),
    fibra(fibra),
    entrada(entrada)
{
}

/**
 * @brief Método para construir o modelo de cálculos para o volume de controle, levando em conta a distribuição de fibras escolhida.
 */
void VolumeControle::construirModelo() {
    std::unique_ptr<DistribuicaoBase> modelo;
    /// TODO: Criar as demais distribuicoes
    switch (entrada->getDadosVC().distribuicao) {
        case DadosEntradaModelo::TipoDistribuicao::UniformeEstruturada1D:
            modelo = std::make_unique<DistribuicaoUniformeEstruturada>();
        case DadosEntradaModelo::TipoDistribuicao::UniformeAlternada1D:
            modelo = std::make_unique<DistribuicaoUniformeAlternada>();
            break;
        default:
            ;
    }
    /// TODO: Implementar os cálculos para diferentes distribuições
    // Na prática, o modelo de cálculo adotado já assume uma distribuição uniforme unidimensional; portanto, não serão
    // implementadas, por enquanto, as alterações necessárias para uma distribuição qualquer.
    //modelo->aplicar();
    raioFibra = fibra->getDiametro()/2;

    ///
}

// Métodos auxiliares
/**
 * @brief Calcula e retorna o ângulo característico de sobreposição das fibras no caso de superempacotamento.
 * @return double
 */
double VolumeControle::calcularAnguloSobreposicao() const {
    if (espacamentoFibras >= 0) return 0;
    else return acos((raioFibra + espacamentoFibras/2) / raioFibra);
}

/**
 * @brief Calcula e retorna o comprimento auxiliar característico de sobreposição das fibras no caso de superempacotamento.
 * @return double
 */
double VolumeControle::calcularComprimentoAuxiliar() const {
    if (espacamentoFibras >= 0) return 0;
    else return sqrt(- (espacamentoFibras*espacamentoFibras/4 + espacamentoFibras*raioFibra));
}

/**
 * @brief Calcula o número efetivo de fibras no caso de superempacotamento.
 */
void VolumeControle::calcularNumeroEfetivoDeFibras() {
    double areaSobresposta = 2 * (raioFibra*raioFibra*calcularAnguloSobreposicao() - (raioFibra + espacamentoFibras/2)*calcularComprimentoAuxiliar());
    double razaoAreas = areaSobresposta / (M_PI * raioFibra*raioFibra);
    setnumEfetivoFibras(numFibras - 2 * (numFibras + sqrt(numFibras)) * razaoAreas);
}

/**
 * @brief Calcula o perímetro total não impedido das fibras no V.C.
 */
void VolumeControle::calcularPerimetroTotalFibras() {
    setPerimetroTotalFibras(4 * (M_PI_2 - 2*calcularAnguloSobreposicao()) * raioFibra * numFibras);
}


// Métodos principais
/**
 * @brief Calcula o espaçamento entre fibras a partir do número de fibras e dos parâmetros geométricos.
 */
void VolumeControle::calcularEspacamentoFibras() {
    setEspacamentoFibras(sqrt(numFibras) * geometria->getComprimentoCaracteristico() / numFibras - fibra->getDiametro());
}

/**
 * @brief Calcula o empacotamento a partir do número de fibras, volume das fibras e volume do VC. Definidos na classe de entrada.
 */
void VolumeControle::calcularEmpacotamento() {
    setEmpacotamento(numEfetivoFibras * fibra->getVolume() / geometria->getVolume());
}

/**
 * @brief Calcula a porosidade a partir do parâmetro de empacotamento.
 */
void VolumeControle::calcularPorosidade() {
    setPorosidade(1 - empacotamento);
}

/**
 * @brief Calcula a área total de transferência, com base no número de fibras, calculado anteriormente pela própria classe, e na área de superfície de cada fibra.
 */
void VolumeControle::calcularAreaTotalTransferencia() {
    setAreaTransferenciaTotal(perimetroTotalFibras * fibra->getComprimento());
}


// SETTERS E GETTERS
/**
 * @brief Define um novo valor para a variável 'empacotamento'.
 * @param valor : Novo fator de empacotamento calculado.
 */
void VolumeControle::setEmpacotamento(double valor) {
    empacotamento = valor;
}

/**
 * @brief Define um novo valor para a variável 'porosidade'.
 * @param valor : Nova porosidade calculada.
 */
void VolumeControle::setPorosidade(double valor) {
    porosidade = valor;
}

/**
 * @brief Define um novo valor para a variável 'numFibras'.
 * @param valor : Novo número de fibras calculado.
 */
void VolumeControle::setNumFibras(int valor) {
    numFibras = valor;
}

/**
 * @brief Define um novo valor para a variável 'EspacamentoFibras'.
 * @param valor : Novo espaçamento entre fibras calculado.
 */
void VolumeControle::setEspacamentoFibras(double valor) {
    espacamentoFibras = valor;
}


/**
* @brief Define um novo valor para a variável 'numEfetivoFibras'.
 * @param valor : Número efetivo de fibras calculado para a condição de superempacotamento.
 */
void VolumeControle::setnumEfetivoFibras(double valor) {
    numEfetivoFibras = valor;
}

/**
 * @brief Define um novo valor para a variável 'perimetroTotalFibras'.
 * @param valor : Perímetro total de fibras não impedido na condição de superempacotamento.
 */
void VolumeControle::setPerimetroTotalFibras(double valor) {
    perimetroTotalFibras = valor;
}

/**
 * @brief Define um novo valor para a variável 'areaTransferenciaTotal'.
 * @param valor : Nova área total de transferência calculada.
 */
void VolumeControle::setAreaTransferenciaTotal(double valor) {
    areaTransferenciaTotal = valor;
}

/**
 * @brief Retorna a porosidade calculada.
 * @return double
 */
double VolumeControle::getPorosidade() const {
    return porosidade;
}

/**
 * @brief Retorna o número de fibras calculado.
 * @return int
 */
int VolumeControle::getNumFibras() const {
    return numFibras;
}

/**
 * @brief Retorna o valor do espaçamento entre de fibras calculado.
 * @return double
 */
double VolumeControle::getEspacamentoFibras() const {
    return espacamentoFibras;
}

/**
 * @brief Retorna o fator do espaçamento máximo entre as fibras, em relação ao seu raio.
 * @return double
 */
double VolumeControle::getFatorEspacamentoMaximo() const {
    return FatorEspacamentoMaximoFibras;
}

/**
 * @brief Retorna o fator do espaçamento mínimo entre as fibras, em relação ao seu raio.
 * @return double
 */
double VolumeControle::getFatorEspacamentoMinimo() const {
    return FatorEspacamentoMinimoFibras;
}

/**
 * @brief Retorna o valor do número efetivo de fibras. (Útil na condição de superempacotamento.)
 * @return double
 */
double VolumeControle::getNumEfetivoFibras() const {
    return numEfetivoFibras;
}

/**
 * @brief Retorna o valor do perímetro total de fibras não impedido. (Útil na condição de superempacotamento.)
 * @return double
 */
double VolumeControle::getPerimetroTotalFibras() const {
    return perimetroTotalFibras;
}

/**
 * @brief Retorna a área total de transferência calculada.
 * @return double
 */
double VolumeControle::getAreaTransferenciaTotal() const {
    return areaTransferenciaTotal;
}

/**
 * @brief Retorna o empacotamento do volume de controle.
 * @return double
 */
double VolumeControle::getEmpacotamento() const {
    return empacotamento;
}
