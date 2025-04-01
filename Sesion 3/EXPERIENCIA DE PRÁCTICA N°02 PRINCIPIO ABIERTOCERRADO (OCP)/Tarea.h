#ifndef TAREA_H
#define TAREA_H

#include <iostream>
#include <string>

using namespace std;

class Tarea {
public:
    virtual void mostrar() = 0;
    virtual void actualizarEstado(string _estado) = 0;
    virtual int obtenerId() = 0;
    virtual int obtenerUsuarioAsignado() = 0;
    virtual ~Tarea() {}
};

#endif
