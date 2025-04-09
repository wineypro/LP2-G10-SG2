#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <vector>
using namespace std;

class Prestamo;

class Usuario {
private:
    string nombre;
    string direccion;
    string telefono;
    vector<Prestamo*> prestamos;
public:
    Usuario(string _nombre, string _direccion, string _telefono) {
        nombre = _nombre;
        direccion = _direccion;
        telefono = _telefono;
    }
    void agregarPrestamo(Prestamo* p) {
        prestamos.push_back(p);
    }
    string getNombre() {
        return nombre;
    }
    vector<Prestamo*> getPrestamos() {
        return prestamos;
    }
};
#endif
