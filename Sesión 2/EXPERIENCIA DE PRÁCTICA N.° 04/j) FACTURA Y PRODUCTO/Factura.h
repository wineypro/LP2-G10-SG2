#ifndef FACTURA_H
#define FACTURA_H

#include "Producto.h"
#include <vector>
#include <iostream>

using namespace std;

class Factura {
private:
    vector<Producto> productos;
public:
    void agregarProducto(Producto& producto, int cantidadSolicitada) {
        if (producto.getCantidad() >= cantidadSolicitada) {
            producto.setCantidad(producto.getCantidad() - cantidadSolicitada);
            productos.push_back(Producto(producto.getNombre(), producto.getPrecio(), cantidadSolicitada));
            cout << "Producto agregado a la factura.\n";
        } else {
            cout << "Stock insuficiente para " << producto.getNombre() << ".\n";
        }
    }

    double calcularTotal(double descuento = 0, double impuesto = 0) const {
        double subtotal = 0;
        for (const Producto& producto : productos) {
            subtotal += producto.getPrecio() * producto.getCantidad();
        }

        double descuentoAplicado = subtotal * (descuento / 100);
        double impuestoAplicado = subtotal * (impuesto / 100);
        double total = subtotal - descuentoAplicado + impuestoAplicado;

        cout << "Subtotal: $" << subtotal << "\n";
        cout << "Descuento (" << descuento << "%): -$" << descuentoAplicado << "\n";
        cout << "Impuesto (" << impuesto << "%): +$" << impuestoAplicado << "\n";
        cout << "Total a pagar: $" << total << "\n";

        return total;
    }
};

#endif
