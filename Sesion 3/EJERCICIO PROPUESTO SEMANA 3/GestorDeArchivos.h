#ifndef GESTORDEARCHIVOS_H
#define GESTORDEARCHIVOS_H

#include "IArchivo.h"
#include <vector>
#include <iostream>

using namespace std;

class GestorDeArchivos {
private:
    vector<IArchivo*> archivos;

public:
    void agregarArchivo(IArchivo* archivo) {
        archivos.push_back(archivo);
    }

    vector<IArchivo*> obtenerArchivos() {
        return archivos;
    }

    IArchivo* obtenerArchivoPorNombre(const string& nombre) {
        for (auto archivo : archivos) {
            if (archivo->obtenerNombreArchivo() == nombre) {
                return archivo;
            }
        }
        return nullptr;
    }

    bool eliminarArchivo(const string& nombre) {
        for (auto it = archivos.begin(); it != archivos.end(); ++it) {
            if ((*it)->obtenerNombreArchivo() == nombre) {
                delete *it;
                archivos.erase(it);
                return true;
            }
        }
        return false;
    }

    ~GestorDeArchivos() {
        for (auto archivo : archivos) {
            delete archivo;
        }
    }
};

#endif