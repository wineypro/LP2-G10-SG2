#ifndef TAREA_H
#define TAREA_H

#include <iostream>
#include <string>

using namespace std;

class Tarea {
private:
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

    void mostrar() {
        cout << "ID: " << id << ", Descripcion: " << descripcion 
             << ", Fecha Limite: " << fechaLimite << ", Estado: " << estado 
             << ", Usuario Asignado: " << idUsuarioAsignado << endl;
    }

    void actualizarEstado(string _estado) {
        estado = _estado;
    }

    int obtenerId() {
        return id;
    }
};

#endif
