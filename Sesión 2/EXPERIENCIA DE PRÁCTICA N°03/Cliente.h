#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <vector>
#include "Producto.h"
using namespace std;

class Cliente {
private:
    string nombre;
    vector<Producto> carrito;
    double total;

public:
    Cliente(string _nombre) : nombre(_nombre), total(0) {}

    string getNombre() const { return nombre; }

    void agregarProducto(Producto producto) {
        carrito.push_back(producto);
        total += producto.getPrecio();
        cout << producto.getNombre() << " agregado al carrito.\n";
    }

    void mostrarCarrito() {
        cout << "\n--- Carrito de " << nombre << " ---\n";
        for (const auto& producto : carrito) {
            cout << "- " << producto.getNombre() << " ($" << producto.getPrecio() << ")\n";
        }
        cout << "Total a pagar: $" << total << endl;
    }

    void pagarCuenta() {
        cout << nombre << " ha pagado $" << total << ".\n";
        carrito.clear();
        total = 0;
    }
};

#endif
