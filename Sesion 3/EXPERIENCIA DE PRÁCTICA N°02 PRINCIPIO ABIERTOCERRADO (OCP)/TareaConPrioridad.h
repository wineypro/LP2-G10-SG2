#ifndef TAREACONPRIORIDAD_H
#define TAREACONPRIORIDAD_H

#include "Tarea.h"

class TareaConPrioridad : public Tarea {
private:
    int id;
    string descripcion;
    string fechaLimite;
    string estado;
    int idUsuarioAsignado;
    int prioridad;

public:
    TareaConPrioridad(int _id, string _descripcion, string _fechaLimite, int _idUsuarioAsignado, int _prioridad) {
        id = _id;
        descripcion = _descripcion;
        fechaLimite = _fechaLimite;
        estado = "Pendiente";
        idUsuarioAsignado = _idUsuarioAsignado;
        prioridad = _prioridad;
    }

    void mostrar() override {
        cout << "ID: " << id << ", Descripcion: " << descripcion 
             << ", Fecha Limite: " << fechaLimite << ", Estado: " << estado 
             << ", Usuario Asignado: " << idUsuarioAsignado << ", Prioridad: " << prioridad << endl;
    }

    void actualizarEstado(string _estado) override {
        estado = _estado;
    }

    int obtenerId() override {
        return id;
    }

    int obtenerUsuarioAsignado() override {
        return idUsuarioAsignado;
    }

    int obtenerPrioridad() {
        return prioridad;
    }
};

#endif
