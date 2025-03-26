#ifndef TIENDA_H
#define TIENDA_H

#include <iostream>
#include <vector>
#include "Producto.h"
using namespace std;

class Tienda {
private:
    vector<Producto> productos;

public:
    void agregarProducto(const Producto& producto) {
        productos.push_back(producto);
    }

    void mostrarProductos() {
        cout << "\n--- Productos Disponibles ---\n";
        for (const auto& producto : productos) {
            cout << "- " << producto.getNombre() << " ($" << producto.getPrecio() 
                 << ") - Stock: " << producto.getStock() << endl;
        }
    }

    bool eliminarProducto(const string& nombre) {
        for (size_t i = 0; i < productos.size(); i++) {
            if (productos[i].getNombre() == nombre) {
                productos.erase(productos.begin() + i);
                return true;
            }
        }
        return false;
    }

    bool actualizarPrecio(const string& nombre, double nuevoPrecio) {
        for (auto& producto : productos) {
            if (producto.getNombre() == nombre) {
                producto.setPrecio(nuevoPrecio);
                return true;
            }
        }
        return false;
    }
};

#endif
