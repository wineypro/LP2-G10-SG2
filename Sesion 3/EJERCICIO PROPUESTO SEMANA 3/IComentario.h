#ifndef ICOMENTARIO_H
#define ICOMENTARIO_H

#include <string>
#include "Usuario.h"

using namespace std;

class IComentario {
public:
    // Metodo para obtener el ID del comentario
    virtual int obtenerId() const = 0;

    // Metodo para obtener el contenido del comentario
    virtual string obtenerContenido() const = 0;

    // Metodo para obtener el autor del comentario (usuario)
    virtual Usuario* obtenerAutor() const = 0;

    // Metodo para obtener la fecha en que se hizo el comentario
    virtual string obtenerFecha() const = 0;

    // Metodo para agregar un comentario
    virtual void agregarComentario(const string& contenido) = 0;

    // Destructor virtual
    virtual ~IComentario() {}
};

#endif
