#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include <vector>
#include "IProyecto.h"  

using namespace std;

class Usuario {
private:
    int id;
    string nombre;
    vector<IProyecto*> proyectos;  // Lista de proyectos asociados a este usuario

public:
    Usuario(int _id, string _nombre) {
        id = _id;
        nombre = _nombre;
    }

    int obtenerId() {
        return id;
    }

    string obtenerNombre() {
        return nombre;
    }

    // Metodo para agregar un proyecto a un usuario
    void agregarProyecto(IProyecto* proyecto) {
        proyectos.push_back(proyecto);
    }

    // Metodo para obtener la lista de proyectos asociados al usuario
    vector<IProyecto*> obtenerProyectos() const {
        return proyectos;
    }

    // Metodo para obtener un proyecto especifico por su id
    IProyecto* obtenerProyectoPorId(int idProyecto) const {
        for (auto& proyecto : proyectos) {
            if (proyecto->obtenerId() == idProyecto) {
                return proyecto;
            }
        }
        return nullptr;  // Si no se encuentra el proyecto
    }

    // Destructor
    virtual ~Usuario() {}
};

#endif

