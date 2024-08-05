/**
 * @file FibraBase.h
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief Arquivo com a classe base para descrever a geometria das fibras do módulo de membranas.
 * @version 0.1
 * @date 2024-07-11
 *
 * @copyright Copyright (c) 2024
 */

#ifndef MODELAGEM_MEMBRANAS_FIBRABASE_H
#define MODELAGEM_MEMBRANAS_FIBRABASE_H

/**
 * @brief Classe base para definição da geometria da geometria das fibras do módulo de membranas.
 */
class FibraBase {
private:
    double comprimento;
    double diametroMedio;
    double areaSuperficial;
    double volume;

public:
    // Construtor
    FibraBase();
    FibraBase(double comprimento, double diametro);
    // Calculadoras
    virtual void calcularAreaSuperficial();
    virtual void calcularVolume();
    // Setters e Getters
    void setComprimento(double valor);
    void setDiametro(double valor);
    void setAreaSuperficial(double valor);
    void setVolume(double valor);
    double getComprimento() const;
    double getDiametro() const;
    double getAreaSuperficial() const;
    double getVolume() const;
};


#endif //MODELAGEM_MEMBRANAS_FIBRABASE_H
