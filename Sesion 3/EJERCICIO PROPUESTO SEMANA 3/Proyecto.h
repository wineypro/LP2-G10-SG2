// Proyecto.h
#ifndef PROYECTO_H
#define PROYECTO_H

#include "IProyecto.h"  
#include "Tarea.h"      

class Proyecto : public IProyecto {
private:
    int idProyecto;  

public:
    // Implementación del mtodo obtenerId
    int obtenerId() const override {
        return idProyecto;  // Retorna el ID del proyecto
    }

    
};

#endif
