#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

using namespace std;

class Producto {
private:
    string nombre;
    double precio;
public:
    Producto(string _nombre, double _precio) : nombre(_nombre), precio(_precio) {}

    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
};

#endif
