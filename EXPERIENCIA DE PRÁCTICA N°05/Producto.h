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
        nombre = _nombre;
        precio = (_precio > 0) ? _precio : 0;
        stock = (_stock > 0) ? _stock : 0;
    }

    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getStock() const { return stock; }
    void setStock(int _stock) { stock = _stock; }

    void mostrar() const {
        cout << "Producto: " << nombre << " | Precio: $" << precio << " | Stock: " << stock << endl;
    }

    double aplicarDescuento(int cantidad) const {
        if (cantidad > 5) return precio * 0.9; 
        return precio;
    }
};

#endif
