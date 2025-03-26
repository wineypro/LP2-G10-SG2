#ifndef MISION_H
#define MISION_H

#include <iostream>
using namespace std;

class Mision {
private:
    string destino;
    double duracion;
    int tripulacion;

public:
    Mision(string _destino, double _duracion, int _tripulacion)
        : destino(_destino), duracion(_duracion), tripulacion(_tripulacion) {}

    string getDestino() const { return destino; }
    double getDuracion() const { return duracion; }
    int getTripulacion() const { return tripulacion; }

    void setDuracion(double _duracion) { duracion = _duracion; }
    void setTripulacion(int _tripulacion) { tripulacion = _tripulacion; }
};

#endif
