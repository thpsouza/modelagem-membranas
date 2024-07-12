//
// Created by LABCFD on 7/5/2024.
//

#ifndef DADOSSAIDAMODELO_H
#define DADOSSAIDAMODELO_H


class DadosSaidaModelo {
private:
    double porosidade;
    double areaTransferenciaTotal;
public:
    DadosSaidaModelo();

    void setPorosidade(double value);
    void setAreaTotalTransferencia(double value);
    double getPorosidade() const;
    double getAreaTotalTransferencia() const;
};


#endif //DADOSSAIDAMODELO_H
