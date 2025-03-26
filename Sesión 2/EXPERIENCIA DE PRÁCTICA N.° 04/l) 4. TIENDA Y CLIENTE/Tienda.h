#ifndef TIENDA_H
#define TIENDA_H

#include "Producto.h"
#include "Cliente.h"
#include <vector>
#include <iostream>

using namespace std;

class Tienda {
private:
    vector<Producto> productos;
public:
    void agregarProducto(const Producto& producto) {
        productos.push_back(producto);
    }

    void mostrarProductos() const {
        cout << "\n--- Productos Disponibles ---\n";
        for (const Producto& producto : productos) {
            cout << producto.getNombre() << " - $" << producto.getPrecio() << "\n";
        }
    }

    Producto buscarProducto(string nombre) const {
        for (const Producto& producto : productos) {
            if (producto.getNombre() == nombre) {
                return producto;
            }
        }
        return Producto("", 0);
    }
};

#endif
