#ifndef CLIENTE_H
#define CLIENTE_H

#include "Producto.h"
#include <vector>
#include <iostream>

using namespace std;

class Cliente {
private:
    string nombre;
    vector<Producto> carrito;
public:
    Cliente(string _nombre) : nombre(_nombre) {}

    void agregarProducto(const Producto& producto) {
        carrito.push_back(producto);
        cout << producto.getNombre() << " agregado al carrito de " << nombre << ".\n";
    }

    double pagarCuenta() const {
        double total = 0;
        for (const Producto& producto : carrito) {
            total += producto.getPrecio();
        }
        cout << "Total a pagar por " << nombre << ": $" << total << "\n";
        return total;
    }
};

#endif
