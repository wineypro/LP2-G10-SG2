#ifndef AVION_H
#define AVION_H

#include <iostream>
#include "Mision.h"
using namespace std;

class Avion {
private:
    string modelo;
    double combustible;
    int tripulacionMaxima;

public:
    Avion(string _modelo, double _combustible, int _tripulacionMaxima)
        : modelo(_modelo), combustible(_combustible), tripulacionMaxima(_tripulacionMaxima) {}

    bool verificarMision(const Mision &mision) const {
        return (mision.getDuracion() * 500 <= combustible && mision.getTripulacion() <= tripulacionMaxima);
    }

    void ejecutarMision(const Mision &mision) {
        cout << "Misión a " << mision.getDestino() << " en curso...\n";
        cout << "Duración: " << mision.getDuracion() << " horas\n";
        cout << "Tripulación: " << mision.getTripulacion() << endl;
        cout << "Misión completada con éxito.\n";
    }
};

#endif
