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

public:
    FibraBase();

    void setComprimento(double valor);
    void setDiametro(double valor);
    void setAreaSuperficial(double valor);
    double getComprimento() const;
    double getDiametro() const;
    double getAreaSuperficial() const;
};


#endif //MODELAGEM_MEMBRANAS_FIBRABASE_H
