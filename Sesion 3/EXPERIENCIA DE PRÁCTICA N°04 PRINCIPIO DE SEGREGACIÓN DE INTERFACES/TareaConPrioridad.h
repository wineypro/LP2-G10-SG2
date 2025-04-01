#ifndef TAREACONPRIORIDAD_H
#define TAREACONPRIORIDAD_H

#include "Tarea.h"

class TareaConPrioridad : public Tarea {
private:
    int prioridad;

public:
    TareaConPrioridad(int _id, string _descripcion, string _fechaLimite, int _idUsuarioAsignado, int _prioridad)
        : Tarea(_id, _descripcion, _fechaLimite, _idUsuarioAsignado) {
        prioridad = _prioridad;
    }

    void mostrar() override {
        cout << "ID: " << id << ", Descripcion: " << descripcion
             << ", Fecha Limite: " << fechaLimite << ", Estado: " << estado
             << ", Usuario Asignado: " << idUsuarioAsignado
             << ", Prioridad: " << prioridad << endl;
    }
};

#endif
