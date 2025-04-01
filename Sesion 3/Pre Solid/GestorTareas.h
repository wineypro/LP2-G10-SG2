#ifndef GESTORTAREAS_H
#define GESTORTAREAS_H

#include "Tarea.h"
#include <vector>

class GestorTareas {
private:
    vector<Tarea*> tareas;

public:
    GestorTareas() {}

    ~GestorTareas() {
        for (Tarea* tarea : tareas) {
            delete tarea;
        }
    }

    void agregarTarea(Tarea* _tarea) {
        tareas.push_back(_tarea);
    }

    void mostrarTareas() {
        for (Tarea* tarea : tareas) {
            tarea->mostrar();
        }
    }

    void actualizarEstadoTarea(int _idTarea, string _nuevoEstado) {
        for (Tarea* tarea : tareas) {
            if (tarea->obtenerId() == _idTarea) {
                tarea->actualizarEstado(_nuevoEstado);
                break;
            }
        }
    }
};

#endif
