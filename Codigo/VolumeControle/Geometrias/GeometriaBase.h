/**
 * @file GeometriaBase.h
 * @author Thiago Souza (thiagosouza@eq.ufrj.com)
 * @brief Arquivo com a classe base da geometria do volume de controle.
 * @version 0.1
 * @date 2024-07-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#ifndef MODELAGEM_MEMBRANAS_GEOMETRIABASE_H
#define MODELAGEM_MEMBRANAS_GEOMETRIABASE_H

/**
 * @brief Classe base para definição da geometria do volume de controle.
 */
class GeometriaBase {
private:
    double volume;
    double areaFace;

protected:
    bool temFace;

public:
    GeometriaBase();
    //GeometriaBase(double volume);

    virtual void calcularVolume();
    virtual void calcularAreaFace();
    void setVolume(double valor);
    void setAreaFace(double valor);
    double getVolume() const;
    double getAreaFace() const;
};


#endif //MODELAGEM_MEMBRANAS_GEOMETRIABASE_H
