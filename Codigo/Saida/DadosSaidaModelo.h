//
// Created by LABCFD on 7/5/2024.
//

#ifndef DADOSSAIDAMODELO_H
#define DADOSSAIDAMODELO_H


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
