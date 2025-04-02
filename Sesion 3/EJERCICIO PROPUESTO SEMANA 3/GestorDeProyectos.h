#ifndef GESTORDEPROYECTOS_H
#define GESTORDEPROYECTOS_H

#include <vector>
#include "IProyecto.h"

using namespace std;

class GestorDeProyectos {
private:
    vector<IProyecto*> proyectos;

public:
    GestorDeProyectos() {}

    // Agregar un proyecto al gestor
    void agregarProyecto(IProyecto* proyecto) {
        proyectos.push_back(proyecto);
    }

    // Eliminar un proyecto por su ID
    void eliminarProyecto(int idProyecto) {
        for (auto it = proyectos.begin(); it != proyectos.end(); ++it) {
            if ((*it)->obtenerId() == idProyecto) {
                proyectos.erase(it);
                break;
            }
        }
    }

    // Obtener un proyecto por su ID
    IProyecto* obtenerProyectoPorId(int idProyecto) {
        for (auto& proyecto : proyectos) {
            if (proyecto->obtenerId() == idProyecto) {
                return proyecto;
            }
        }
        return nullptr;
    }

    // Obtener todos los proyectos
    vector<IProyecto*> obtenerProyectos() const {
        return proyectos;
    }

    // Destructor
    virtual ~GestorDeProyectos() {
        for (auto& proyecto : proyectos) {
            delete proyecto;
        }
    }
};

#endif
