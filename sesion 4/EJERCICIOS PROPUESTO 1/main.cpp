#include <iostream>
#include <vector>
#include <regex>
#include "Autor.h"
#include "Libro.h"
#include "Usuario.h"
#include "Prestamo.h"
using namespace std;

bool validarTelefono(const string& telefono) {
    return regex_match(telefono, regex("^[0-9]{9}$"));
}

bool validarISBN(const string& isbn) {
    return regex_match(isbn, regex("^[0-9]{13}$"));
}

bool validarAnio(int anio) {
    return anio <= 2025;
}

bool validarFecha(const string& fecha) {
    return regex_match(fecha, regex("^([0-2][0-9]|3[0-1])-(0[1-9]|1[0-2])-(19|20)[0-9]{2}$"));
}

int main() {
    vector<Autor*> autores;
    vector<Libro*> libros;
    vector<Usuario*> usuarios;
    vector<Prestamo*> prestamos;
    int opcion;

    do {
        cout << "\n--- MENU BIBLIOTECA ---" << endl;
        cout << "1. Registrar autor" << endl;
        cout << "2. Registrar libro" << endl;
        cout << "3. Registrar usuario" << endl;
        cout << "4. Registrar préstamo" << endl;
        cout << "5. Ver préstamos de usuario" << endl;
        cout << "6. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            string nombre, nacionalidad;
            cout << "Nombre del autor: ";
            getline(cin, nombre);
            cout << "Nacionalidad: ";
            getline(cin, nacionalidad);
            autores.push_back(new Autor(nombre, nacionalidad));
            cout << "Autor registrado." << endl;
        }

        else if (opcion == 2) {
            if (autores.empty()) {
                cout << "Primero debe registrar al menos un autor." << endl;
                continue;
            }
            string isbn, titulo;
            int anio, cantidad, posAutor;

            do {
                cout << "ISBN (13 dígitos): ";
                getline(cin, isbn);
            } while (!validarISBN(isbn));

            cout << "Título: ";
            getline(cin, titulo);

            do {
                cout << "Año de publicación (máx 2025): ";
                cin >> anio;
            } while (!validarAnio(anio));

            cout << "Cantidad de ejemplares: ";
            cin >> cantidad;

            cout << "Seleccione autor:" << endl;
            for (int i = 0; i < autores.size(); i++) {
                cout << i << ". " << autores[i]->getNombre() << endl;
            }
            cin >> posAutor;
            cin.ignore();
            if (posAutor >= 0 && posAutor < autores.size()) {
                libros.push_back(new Libro(isbn, titulo, anio, cantidad, autores[posAutor]));
                cout << "Libro registrado." << endl;
            } else {
                cout << "Autor no válido." << endl;
            }
        }

        else if (opcion == 3) {
            string nombre, direccion, telefono;
            cout << "Nombre del usuario: ";
            getline(cin, nombre);
            cout << "Dirección: ";
            getline(cin, direccion);

            do {
                cout << "Teléfono (9 dígitos): ";
                getline(cin, telefono);
            } while (!validarTelefono(telefono));

            usuarios.push_back(new Usuario(nombre, direccion, telefono));
            cout << "Usuario registrado." << endl;
        }

        else if (opcion == 4) {
            if (usuarios.empty() || libros.empty()) {
                cout << "Debe haber al menos un usuario y un libro registrados." << endl;
                continue;
            }
            int posUsuario, posLibro;
            string fechaPrestamo, fechaDevolucion;

            cout << "Seleccione usuario:" << endl;
            for (int i = 0; i < usuarios.size(); i++) {
                cout << i << ". " << usuarios[i]->getNombre() << endl;
            }
            cin >> posUsuario;
            cin.ignore();

            cout << "Seleccione libro:" << endl;
            for (int i = 0; i < libros.size(); i++) {
                cout << i << ". " << libros[i]->getTitulo() << endl;
            }
            cin >> posLibro;
            cin.ignore();

            do {
                cout << "Fecha de préstamo (DD-MM-AAAA): ";
                getline(cin, fechaPrestamo);
            } while (!validarFecha(fechaPrestamo));

            do {
                cout << "Fecha de devolución (DD-MM-AAAA): ";
                getline(cin, fechaDevolucion);
            } while (!validarFecha(fechaDevolucion));

            prestamos.push_back(new Prestamo(libros[posLibro], usuarios[posUsuario], fechaPrestamo, fechaDevolucion));
            cout << "Préstamo registrado." << endl;
        }

        else if (opcion == 5) {
            if (usuarios.empty()) {
                cout << "No hay usuarios registrados." << endl;
                continue;
            }
            int posUsuario;
            cout << "Seleccione usuario:" << endl;
            for (int i = 0; i < usuarios.size(); i++) {
                cout << i << ". " << usuarios[i]->getNombre() << endl;
            }
            cin >> posUsuario;
            cin.ignore();
            vector<Prestamo*> ps = usuarios[posUsuario]->getPrestamos();
            if (ps.empty()) {
                cout << "Este usuario no tiene préstamos registrados." << endl;
            } else {
                for (Prestamo* p : ps) {
                    p->imprimir();
                }
            }
        }

    } while (opcion != 6);

    for (Autor* a : autores) delete a;
    for (Libro* l : libros) delete l;
    for (Usuario* u : usuarios) delete u;
    for (Prestamo* p : prestamos) delete p;

    cout << "Programa finalizado." << endl;
    return 0;
}
