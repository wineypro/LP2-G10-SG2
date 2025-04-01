#ifndef TAREAESTANDAR_H
#define TAREAESTANDAR_H

#include "Tarea.h"

class TareaEstandar : public Tarea {
public:
    TareaEstandar(int _id, string _descripcion, string _fechaLimite, int _idUsuarioAsignado)
        : Tarea(_id, _descripcion, _fechaLimite, _idUsuarioAsignado) {}

    void mostrar() override {
        cout << "ID: " << id << ", Descripcion: " << descripcion
             << ", Fecha Limite: " << fechaLimite << ", Estado: " << estado
             << ", Usuario Asignado: " << idUsuarioAsignado << endl;
    }
};

#endif
