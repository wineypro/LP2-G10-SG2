#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
using namespace std;

class Producto {
public:
    string codigo, descripcion, proveedor;
    float precio;

    Producto(string _codigo, string _descripcion, float _precio, string _proveedor) {
        codigo = _codigo;
        descripcion = _descripcion;
        precio = _precio;
        proveedor = _proveedor;
    }
};

#endif
