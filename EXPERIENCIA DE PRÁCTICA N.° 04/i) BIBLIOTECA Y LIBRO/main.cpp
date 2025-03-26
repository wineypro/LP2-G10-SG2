#include <iostream>
#include "Biblioteca.h"

using namespace std;

void mostrarMenu() {
    cout << "\n--- Menú ---\n";
    cout << "1. Registrar libro\n";
    cout << "2. Prestar libro\n";
    cout << "3. Devolver libro\n";
    cout << "4. Mostrar libros\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    Biblioteca biblioteca;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            string nombre, autor;
            cout << "Nombre del libro: ";
            getline(cin, nombre);
            cout << "Autor: ";
            getline(cin, autor);
            biblioteca.agregarLibro(Libro(nombre, autor));
        } else if (opcion == 2) {
            string nombre;
            cout << "Nombre del libro a prestar: ";
            getline(cin, nombre);
            biblioteca.prestarLibro(nombre);
        } else if (opcion == 3) {
            string nombre;
            cout << "Nombre del libro a devolver: ";
            getline(cin, nombre);
            biblioteca.devolverLibro(nombre);
        } else if (opcion == 4) {
            biblioteca.mostrarLibros();
        }
    } while (opcion != 5);

    return 0;
}
