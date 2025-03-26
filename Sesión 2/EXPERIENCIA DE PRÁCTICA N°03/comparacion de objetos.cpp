#include <iostream>
#include <string>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;

public:
    Libro(string t, string a) : titulo(t), autor(a) {}

    bool esIgualA(Libro otro) {
        return titulo == otro.titulo && autor == otro.autor;
    }

    string getTitulo() const {
        return titulo;
    }

    string getAutor() const {
        return autor;
    }
};

int main() {
    Libro libro1("Cien años de soledad", "Gabriel García Márquez");
    Libro libro2("Cien años de soledad", "Gabriel García Márquez");
    Libro libro3("Don Quijote de la Mancha", "Miguel de Cervantes");

    if (libro1.esIgualA(libro2)) {
        cout << "Los libros 1 y 2 son iguales." << endl;
    } else {
        cout << "Los libros 1 y 2 no son iguales." << endl;
    }

    if (libro1.esIgualA(libro3)) {
        cout << "Los libros 1 y 3 son iguales." << endl;
    } else {
        cout << "Los libros 1 y 3 no son iguales." << endl;
    }

    return 0;
}
