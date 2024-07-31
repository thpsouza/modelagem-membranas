/**
 * @file DadosSaidaModelo.h
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief Arquivo com a classe de dados de saída do programa.
 * @version 0.1
 * @date 2024-07-05
 *
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef DADOSSAIDAMODELO_H
#define DADOSSAIDAMODELO_H

/**
 * @brief Classe de saída de dados para os cálculos do modelo. Contém os valores calculados para a porosidade, o número
 * de fibras e a área total de transferência.
 */
class DadosSaidaModelo {
private:
    double porosidade;
    int numFibras;
    double areaTransferenciaTotal;
public:
    DadosSaidaModelo();

    void setPorosidade(double value);
    void setNumFibras(int value);
    void setAreaTotalTransferencia(double value);
    double getPorosidade() const;
    int getNumFibras() const;
    double getAreaTotalTransferencia() const;
};


#endif //DADOSSAIDAMODELO_H
