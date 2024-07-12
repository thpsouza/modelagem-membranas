//
// Created by LABCFD on 7/11/2024.
//

#ifndef MODELAGEM_MEMBRANAS_FIBRABASE_H
#define MODELAGEM_MEMBRANAS_FIBRABASE_H


class FibraBase {
private:
    double comprimento;
    double diametroMedio;
    double areaSuperficial;
    double volume;

public:
    // Construtor
    FibraBase();
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
