#include <iostream>

using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    string genero;

public:
    Libro(string titulo, string autor, string genero)
        : titulo(titulo), autor(autor), genero(genero) {}

    string getTitulo() {
        return titulo;
    }

    string getAutor() {
        return autor;
    }

    void setAutor(string nuevoAutor) {
        autor = nuevoAutor;
    }

    string getGenero() {
        return genero;
    }

    void setGenero(string nuevoGenero) {
        genero = nuevoGenero;
    }

    void mostrarInfoLibro() {
        cout << "Titulo: " << titulo << ", Autor: " << autor << ", Genero: " << genero << endl;
    }
};

int main() {
    Libro libro1("1984", "George Orwell", "Distopia");
    Libro libro2("Cien anos de soledad", "Gabriel Garcia Marquez", "Realismo magico");

    libro1.mostrarInfoLibro();
    libro2.mostrarInfoLibro();

    libro2.setAutor("G. Garcia Marquez"); // Modificando el autor
    libro2.setGenero("Ficcion"); // Modificando el genero
    libro2.mostrarInfoLibro();

    return 0;
}
