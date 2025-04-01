#ifndef TAREA_H
#define TAREA_H

#include "IMostrable.h"
#include "IActualizable.h"
#include <iostream>
#include <string>

using namespace std;

class Tarea : public IMostrable, public IActualizable {
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

    void actualizarEstado(string _estado) override {
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
