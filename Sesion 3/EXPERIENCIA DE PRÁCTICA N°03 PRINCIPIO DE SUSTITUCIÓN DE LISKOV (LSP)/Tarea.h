#ifndef TAREA_H
#define TAREA_H

#include <iostream>
#include <string>

using namespace std;

class Tarea {
protected:
    int id;
    string descripcion;
    string fechaLimite;
    string estado;
    int idUsuarioAsignado;

public:
    Tarea(int _id, string _descripcion, string _fechaLimite, int _idUsuarioAsignado) {
        id = _id;
        descripcion = _descripcion;
        fechaLimite = _fechaLimite;
        estado = "Pendiente";
        idUsuarioAsignado = _idUsuarioAsignado;
    }

    virtual void mostrar() = 0;
    virtual void actualizarEstado(string _estado) {
        estado = _estado;
    }

    int obtenerId() {
        return id;
    }

    int obtenerUsuarioAsignado() {
        return idUsuarioAsignado;
    }

    virtual ~Tarea() {}
};

#endif
