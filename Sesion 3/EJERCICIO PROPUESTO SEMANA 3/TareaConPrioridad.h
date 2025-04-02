#ifndef TAREACONPRIORIDAD_H
#define TAREACONPRIORIDAD_H

#include "Tarea.h"

using namespace std;

class TareaConPrioridad : public Tarea {
private:
    int prioridad;

public:
    TareaConPrioridad(int id, const string& descripcion, const string& fechaLimite, int idUsuarioAsignado, int prioridad)
        : Tarea(id, descripcion, fechaLimite, idUsuarioAsignado), prioridad(prioridad) {}

    void mostrar() const override {
        cout << "ID: " << obtenerId() << ", Descripcion: " << obtenerDescripcion()
             << ", Fecha Limite: " << obtenerFechaLimite() << ", Estado: " << obtenerEstado()
             << ", Prioridad: " << prioridad << endl;
    }
};

#endif
