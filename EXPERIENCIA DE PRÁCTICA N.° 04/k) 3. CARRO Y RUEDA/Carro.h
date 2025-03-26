#ifndef CARRO_H
#define CARRO_H

#include "Rueda.h"
#include <iostream>

using namespace std;

class Carro {
private:
    Rueda ruedas[4];
public:
    Carro(int tamanoRueda) : ruedas{Rueda(tamanoRueda), Rueda(tamanoRueda), Rueda(tamanoRueda), Rueda(tamanoRueda)} {}

    void mover() const {
        cout << "El carro está en movimiento con ruedas de tamaño " << ruedas[0].getTamano() << ".\n";
    }

    void cambiarRuedas(int nuevoTamano) {
        for (int i = 0; i < 4; i++) {
            ruedas[i].setTamano(nuevoTamano);
        }
        cout << "Las ruedas han sido cambiadas a tamaño " << nuevoTamano << ".\n";
    }
};

#endif
