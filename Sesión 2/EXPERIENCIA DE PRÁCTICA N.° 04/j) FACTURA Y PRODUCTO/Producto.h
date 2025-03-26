#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

using namespace std;

class Producto {
private:
    string nombre;
    double precio;
    int cantidad;
public:
    Producto(string _nombre, double _precio, int _cantidad) 
        : nombre(_nombre), precio(_precio), cantidad(_cantidad) {}

    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getCantidad() const { return cantidad; }

    void setPrecio(double _precio) { precio = _precio; }
    void setCantidad(int _cantidad) { cantidad = _cantidad; }
};

#endif
