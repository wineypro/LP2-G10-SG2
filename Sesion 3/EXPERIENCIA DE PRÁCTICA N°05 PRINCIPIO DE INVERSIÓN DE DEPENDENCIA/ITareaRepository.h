#ifndef ITAREAREPOSITORY_H
#define ITAREAREPOSITORY_H

#include "Tarea.h"
#include <vector>

class ITareaRepository {
public:
    virtual void agregarTarea(Tarea* tarea) = 0;
    virtual void mostrarTareas() = 0;
    virtual void actualizarEstadoTarea(int idTarea, std::string nuevoEstado) = 0;
    virtual ~ITareaRepository() {}
};

#endif
