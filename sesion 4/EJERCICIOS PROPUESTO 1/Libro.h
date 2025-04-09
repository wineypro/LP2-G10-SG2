#ifndef LIBRO_H
#define LIBRO_H
#include <string>
using namespace std;

class Autor;

class Libro {
private:
    string isbn;
    string titulo;
    int anioPublicacion;
    int cantidad;
    Autor* autor;
public:
    Libro(string _isbn, string _titulo, int _anio, int _cantidad, Autor* _autor) {
        isbn = _isbn;
        titulo = _titulo;
        anioPublicacion = _anio;
        cantidad = _cantidad;
        autor = _autor;
        autor->agregarLibro(this);
    }
    string getTitulo() {
        return titulo;
    }
    string getISBN() {
        return isbn;
    }
    Autor* getAutor() {
        return autor;
    }
};
#endif
