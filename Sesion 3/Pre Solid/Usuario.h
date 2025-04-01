#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>

using namespace std;

class Usuario {
private:
    int id;
    string nombre;

public:
    Usuario(int _id, string _nombre) {
        id = _id;
        nombre = _nombre;
    }

    string obtenerNombre() {
        return nombre;
    }

    int obtenerId() {
        return id;
    }
};

#endif
