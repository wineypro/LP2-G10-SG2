#ifndef TAREAREPOSITORY_H
#define TAREAREPOSITORY_H

#include "ITareaRepository.h"
#include <vector>

class TareaRepository : public ITareaRepository {
private:
    std::vector<Tarea*> tareas;

public:
    void agregarTarea(Tarea* tarea) override {
        tareas.push_back(tarea);
    }

    void mostrarTareas() override {
        for (Tarea* tarea : tareas) {
            tarea->mostrar();
        }
    }

    void actualizarEstadoTarea(int idTarea, std::string nuevoEstado) override {
        for (Tarea* tarea : tareas) {
            if (tarea->obtenerId() == idTarea) {
                tarea->actualizarEstado(nuevoEstado);
                break;
            }
        }
    }

    ~TareaRepository() {
        for (Tarea* tarea : tareas) {
            delete tarea;
        }
    }
};

#endif
