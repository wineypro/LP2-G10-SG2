#ifndef GESTORTAREAS_H
#define GESTORTAREAS_H

#include <vector>
#include <string>

using namespace std;

#include "Tarea.h"
#include "ITareaRepository.h"

class GestorTareas {
private:
    ITareaRepository* tareaRepository;

public:
    GestorTareas(ITareaRepository* repo) : tareaRepository(repo) {}

    void agregarTarea(Tarea* tarea) {
        tareaRepository->agregarTarea(tarea);
    }

    vector<Tarea*> obtenerTareas() const {
        return tareaRepository->obtenerTareas();
    }

    void actualizarEstadoTarea(int idTarea, const string& nuevoEstado) {
        tareaRepository->actualizarEstadoTarea(idTarea, nuevoEstado);
    }

    // Nuevo metodo para mostrar todas las tareas
    void mostrarTareas() const {
        for (auto tarea : obtenerTareas()) {
            tarea->mostrar();
        }
    }
};

#endif
