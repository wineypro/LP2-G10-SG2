#ifndef IPROYECTO_H
#define IPROYECTO_H

#include "Tarea.h"  
#include <vector>

using namespace std;  

class IProyecto {
public:
    // Destructor virtual para asegurar que las clases derivadas tengan un destructor adecuado
    virtual ~IProyecto() = default;

    // Metodos virtuales puros para agregar y obtener tareas
    virtual void agregarTarea(Tarea* tarea) = 0; 
    virtual vector<Tarea*> obtenerTareas() const = 0; 

    // Metodo virtual puro para obtener el ID del proyecto (si es necesario)
    virtual int obtenerId() const = 0;  
};

#endif


