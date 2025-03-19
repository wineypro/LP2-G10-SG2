#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
using namespace std;

class Producto {
private:
    string nombre;
    double precio;
    int stock;

public:
    Producto(string _nombre, double _precio, int _stock) {
        if (_precio < 0) _precio = 0;
        if (_stock < 0) _stock = 0;
        nombre = _nombre;
        precio = _precio;
        stock = _stock;
    }

    void mostrar() const {
        cout << "Producto: " << nombre << " | Precio: $" << precio << " | Stock: " << stock << endl;
    }
};

#endif
