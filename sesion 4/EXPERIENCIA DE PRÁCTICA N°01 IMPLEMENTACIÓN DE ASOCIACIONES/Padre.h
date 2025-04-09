#ifndef PADRE_H
#define PADRE_H
#include <string>
#include "Hijo.h"
using namespace std;

class Padre {
private:
    string nombre;
    Hijo* hijos[10];
    int numHijos;
public:
    Padre(string _nombre) {
        nombre = _nombre;
        numHijos = 0;
    }
    void setNombre(string _nombre) {
        nombre = _nombre;
    }
    string getNombre() {
        return nombre;
    }
    void agregarHijo(Hijo* h) {
        if (numHijos < 10) {
            hijos[numHijos] = h;
            numHijos++;
        }
    }
    void imprimirInfo() {
        cout << "Nombre del padre: " << nombre << endl;
        cout << "Cantidad de hijos: " << numHijos << endl;
    }
};
#endif
