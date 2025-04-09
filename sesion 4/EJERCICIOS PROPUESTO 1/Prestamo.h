#ifndef PRESTAMO_H
#define PRESTAMO_H
#include <string>
#include <iostream>
#include "Libro.h"
#include "Usuario.h"
using namespace std;

class Prestamo {
private:
    Libro* libro;
    Usuario* usuario;
    string fechaPrestamo;
    string fechaDevolucion;
public:
    Prestamo(Libro* _libro, Usuario* _usuario, string _fPrestamo, string _fDevolucion) {
        libro = _libro;
        usuario = _usuario;
        fechaPrestamo = _fPrestamo;
        fechaDevolucion = _fDevolucion;
        usuario->agregarPrestamo(this);
    }
    void imprimir() {
        cout << "Usuario: " << usuario->getNombre()
             << " - Libro: " << libro->getTitulo()
             << " - Prestado: " << fechaPrestamo
             << " - Devolución: " << fechaDevolucion << endl;
    }
};
#endif
