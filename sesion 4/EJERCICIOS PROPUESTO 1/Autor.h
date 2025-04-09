#ifndef AUTOR_H
#define AUTOR_H
#include <string>
#include <vector>
using namespace std;

class Libro;

class Autor {
private:
    string nombre;
    string nacionalidad;
    vector<Libro*> libros;
public:
    Autor(string _nombre, string _nacionalidad) {
        nombre = _nombre;
        nacionalidad = _nacionalidad;
    }
    void agregarLibro(Libro* libro) {
        libros.push_back(libro);
    }
    string getNombre() {
        return nombre;
    }
};
#endif
