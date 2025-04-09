#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string>
using namespace std;

class Estudiante {
private:
    string nombre;
public:
    Estudiante(string _nombre) {
        nombre = _nombre;
    }
    string getNombre() {
        return nombre;
    }
};
#endif
