#ifndef TAREAESTANDAR_H
#define TAREAESTANDAR_H

#include "Tarea.h"

using namespace std;

class TareaEstandar : public Tarea {
public:
    TareaEstandar(int id, const string& descripcion, const string& fechaLimite, int idUsuarioAsignado)
        : Tarea(id, descripcion, fechaLimite, idUsuarioAsignado) {}

    void mostrar() const override {
        cout << "ID: " << obtenerId() << ", Descripcion: " << obtenerDescripcion()
             << ", Fecha Limite: " << obtenerFechaLimite() << ", Estado: " << obtenerEstado() << endl;
    }
};

#endif
