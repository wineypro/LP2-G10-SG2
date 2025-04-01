#ifndef GESTORTAREAS_H
#define GESTORTAREAS_H

#include "ITareaRepository.h"
#include <vector>

class GestorTareas {
private:
    ITareaRepository* tareaRepository;

public:
    GestorTareas(ITareaRepository* repository) : tareaRepository(repository) {}

    void agregarTarea(Tarea* tarea) {
        tareaRepository->agregarTarea(tarea);
    }

    void mostrarTareas() {
        tareaRepository->mostrarTareas();
    }

    void actualizarEstadoTarea(int idTarea, std::string nuevoEstado) {
        tareaRepository->actualizarEstadoTarea(idTarea, nuevoEstado);
    }
};

#endif
