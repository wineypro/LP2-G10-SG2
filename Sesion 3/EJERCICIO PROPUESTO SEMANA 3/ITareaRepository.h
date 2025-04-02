#ifndef ITAREAREPOSITORY_H
#define ITAREAREPOSITORY_H

#include <vector>
#include <string>  

using namespace std;

class Tarea;  

class ITareaRepository {
public:
    virtual void agregarTarea(Tarea* tarea) = 0;
    virtual vector<Tarea*> obtenerTareas() const = 0;
    virtual void actualizarEstadoTarea(int idTarea, const string& nuevoEstado) = 0;
};

#endif
