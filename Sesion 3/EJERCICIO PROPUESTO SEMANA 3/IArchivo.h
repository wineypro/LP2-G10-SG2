#ifndef IARCHIVO_H
#define IARCHIVO_H

#include <string>

using namespace std;

class IArchivo {
public:
    // Metodo para obtener el nombre del archivo
    virtual string obtenerNombreArchivo() const = 0;

    // Metodo para obtener el contenido del archivo
    virtual string obtenerContenidoArchivo() const = 0;

    // Metodo para subir el archivo al sistema
    virtual void subirArchivo(const string& contenido) = 0;

    // Metodo para descargar el archivo del sistema
    virtual string descargarArchivo() const = 0;

    // Destructor virtual
    virtual ~IArchivo() {}
};

#endif
