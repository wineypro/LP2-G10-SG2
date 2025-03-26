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
    Producto(string _nombre, double _precio, int _stock) 
        : nombre(_nombre), precio(_precio), stock(_stock) {}

    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getStock() const { return stock; }

    void setStock(int cantidad) { stock = cantidad; }
    void setPrecio(double nuevoPrecio) { precio = nuevoPrecio; }
};

#endif
