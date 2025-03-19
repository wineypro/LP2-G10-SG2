#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <iostream>

using namespace std;

class Producto {
private:
    string nombre;
    double precio;
    int cantidad;

public:
    Producto(string _nombre, double _precio, int _cantidad) {
        nombre = _nombre;
        precio = _precio;
        cantidad = _cantidad;
    }

    string getNombre() const { return nombre; }
    int getCantidadEnInventario() const { return cantidad; }
    void setCantidadEnInventario(int nuevaCantidad) { cantidad = nuevaCantidad; }

    void mostrarInformacion() const {
        cout << "Producto: " << nombre << ", Precio: " << precio << ", Stock: " << cantidad << endl;
    }
};

#endif
