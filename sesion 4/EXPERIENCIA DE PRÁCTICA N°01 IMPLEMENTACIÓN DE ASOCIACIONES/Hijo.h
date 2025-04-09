#ifndef HIJO_H
#define HIJO_H
#include <string>
using namespace std;

class Hijo {
private:
    string nombre;
public:
    Hijo(string _nombre) {
        nombre = _nombre;
    }
    void setNombre(string _nombre) {
        nombre = _nombre;
    }
    string getNombre() {
        return nombre;
    }
};
#endif
