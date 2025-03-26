#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Libro.h"
#include <vector>
#include <iostream>

using namespace std;

class Biblioteca {
private:
    vector<Libro> libros;
public:
    void agregarLibro(const Libro& libro) {
        libros.push_back(libro);
    }

    void prestarLibro(const string& nombre) {
        for (Libro& libro : libros) {
            if (libro.getNombre() == nombre && !libro.estaPrestado()) {
                libro.prestar();
                cout << "Libro prestado con éxito.\n";
                return;
            }
        }
        cout << "No se pudo prestar el libro. Puede que no exista o ya esté prestado.\n";
    }

    void devolverLibro(const string& nombre) {
        for (Libro& libro : libros) {
            if (libro.getNombre() == nombre && libro.estaPrestado()) {
                libro.devolver();
                cout << "Libro devuelto con éxito.\n";
                return;
            }
        }
        cout << "No se encontró el libro prestado para devolver.\n";
    }

    void mostrarLibros() const {
        cout << "\nLista de libros en la biblioteca:\n";
        for (const Libro& libro : libros) {
            cout << "- " << libro.getNombre() << " de " << libro.getAutor()
                 << (libro.estaPrestado() ? " (Prestado)" : " (Disponible)") << "\n";
        }
    }
};

#endif
