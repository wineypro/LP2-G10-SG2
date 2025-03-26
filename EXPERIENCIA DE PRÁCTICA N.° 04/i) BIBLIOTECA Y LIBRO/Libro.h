#ifndef LIBRO_H
#define LIBRO_H

#include <string>

using namespace std;

class Libro {
private:
    string nombre;
    string autor;
    bool prestado;
public:
    Libro(string _nombre, string _autor) 
        : nombre(_nombre), autor(_autor), prestado(false) {}

    string getNombre() const { return nombre; }
    string getAutor() const { return autor; }
    bool estaPrestado() const { return prestado; }

    void prestar() { prestado = true; }
    void devolver() { prestado = false; }
};

#endif
