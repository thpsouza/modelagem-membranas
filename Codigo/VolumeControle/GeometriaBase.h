//
// Created by LABCFD on 7/11/2024.
//

#ifndef MODELAGEM_MEMBRANAS_GEOMETRIABASE_H
#define MODELAGEM_MEMBRANAS_GEOMETRIABASE_H


class GeometriaBase {
private:
    double volume;

public:
    GeometriaBase();
    //GeometriaBase(double volume);

    virtual void calcularVolume();
    void setVolume(double valor);
    double getVolume() const;
};


#endif //MODELAGEM_MEMBRANAS_GEOMETRIABASE_H
