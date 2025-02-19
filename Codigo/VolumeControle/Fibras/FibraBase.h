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
    double diametroMedio;
    double comprimento;
    double areaSuperficial;
    double volume;

public:
    // Construtores
    FibraBase();
    explicit FibraBase(double diametro);
    FibraBase(double diametro, double comprimento);
    FibraBase(double diametro, double comprimento, double areaSuperficial, double volume);
    // Calculadoras
    virtual void calcularDiametro();
    virtual void calcularComprimento();
    virtual void calcularAreaSuperficial();
    virtual void calcularVolume();
    // Setters e Getters
    void setDiametro(double valor);
    void setComprimento(double valor);
    void setAreaSuperficial(double valor);
    void setVolume(double valor);
    double getDiametro() const;
    double getComprimento() const;
    double getAreaSuperficial() const;
    double getVolume() const;
};


#endif //MODELAGEM_MEMBRANAS_FIBRABASE_H
