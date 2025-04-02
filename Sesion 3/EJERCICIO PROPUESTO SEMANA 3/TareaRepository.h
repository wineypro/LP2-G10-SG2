#ifndef TAREAREPOSITORY_H
#define TAREAREPOSITORY_H

#include <vector>
#include <string>

using namespace std;

#include "Tarea.h"
#include "ITareaRepository.h"

class TareaRepository : public ITareaRepository {
private:
    vector<Tarea*> tareas;

public:
    void agregarTarea(Tarea* tarea) override {
        tareas.push_back(tarea);
    }

    vector<Tarea*> obtenerTareas() const override {
        return tareas;
    }

    void actualizarEstadoTarea(int idTarea, const string& nuevoEstado) override {
        for (auto tarea : tareas) {
            if (tarea->obtenerId() == idTarea) {
                tarea->actualizarEstado(nuevoEstado);
                break;
            }
        }
    }
};

#endif
