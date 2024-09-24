/**
 * @file DistribuicaoBase.h
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief Arquivo com a classe base da distribuição de fibras no volume de controle
 * @version 0.1
 * @date 2024-07-12
 *
 * @copyright Copyright (c) 2024
 */

#ifndef MODELAGEM_MEMBRANAS_DISTRIBUICAOBASE_H
#define MODELAGEM_MEMBRANAS_DISTRIBUICAOBASE_H

#include <vector>

/**
 * @brief Classe base para definição da distribuição de fibras no volume de controle.
 * TODO: Implementar distribuições de fibras
 */
class DistribuicaoBase {
private:
    double distanciaFibras;
    std::vector<double[2]> coordenadasFibras;

public:
    DistribuicaoBase();
    virtual double calcularDistanciaFibras(double ladoVC, double raio, int numCentroFibras);
    virtual std::vector<double[2]> calcularCoordenadasFibras(double raioFibra, double distanciaEntreFibras, int numCentroFibras);
    virtual double calcularNumeroEfetivoDeFibras(int numCentroFibras, int numSobreposicoes, double razaoAreas);
    void setDistanciaFibras(double valor);
    [[nodiscard]] double getDistanciaFibras() const;
};


#endif //MODELAGEM_MEMBRANAS_DISTRIBUICAOBASE_H
