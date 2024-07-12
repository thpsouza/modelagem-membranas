//
// Created by LABCFD on 7/11/2024.
//

#ifndef MODELAGEM_MEMBRANAS_GEOMETRIABASE_H
#define MODELAGEM_MEMBRANAS_GEOMETRIABASE_H


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
