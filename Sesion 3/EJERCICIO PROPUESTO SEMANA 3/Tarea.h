#ifndef TAREA_H
#define TAREA_H

#include <string>
#include <iostream>

using namespace std;

class Tarea {
private:
    int id;
    string descripcion;
    string fechaLimite;
    int idUsuarioAsignado;
    string estado;

public:
    Tarea(int id, const string& descripcion, const string& fechaLimite, int idUsuarioAsignado)
        : id(id), descripcion(descripcion), fechaLimite(fechaLimite), idUsuarioAsignado(idUsuarioAsignado), estado("Pendiente") {}

    virtual void mostrar() const = 0;  // Función virtual pura

    // Getter para los atributos
    int obtenerId() const { return id; }
    string obtenerDescripcion() const { return descripcion; }
    string obtenerFechaLimite() const { return fechaLimite; }
    int obtenerIdUsuarioAsignado() const { return idUsuarioAsignado; }
    string obtenerEstado() const { return estado; }

    // Método para actualizar estado
    void actualizarEstado(const string& nuevoEstado) { estado = nuevoEstado; }
};

#endif

