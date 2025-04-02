#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "IArchivo.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Archivo : public IArchivo {
private:
    string nombreArchivo;
    string contenidoArchivo;

public:
    Archivo(const string& _nombreArchivo) : nombreArchivo(_nombreArchivo), contenidoArchivo("") {}

    string obtenerNombreArchivo() const override {
        return nombreArchivo;
    }

    string obtenerContenidoArchivo() const override {
        return contenidoArchivo;
    }

    void subirArchivo(const string& contenido) override {
        contenidoArchivo = contenido;
        ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            archivo << contenido;
            archivo.close();
        } else {
            cout << "No se pudo abrir el archivo para escribir." << endl;
        }
    }

    string descargarArchivo() const override {
        ifstream archivo(nombreArchivo);
        string contenido;
        if (archivo.is_open()) {
            getline(archivo, contenido, '\0');
            archivo.close();
        } else {
            cout << "No se pudo abrir el archivo para leer." << endl;
        }
        return contenido;
    }
};

#endif


