#ifndef PEDIDO_H
#define PEDIDO_H

#include <vector>
#include "Producto.h"

class Pedido {
private:
    vector<Producto> productos;
    vector<int> cantidades;
    string estado;

public:
    Pedido(vector<Producto> _productos, vector<int> _cantidades, string _estado) {
        productos = _productos;
        cantidades = _cantidades;
        estado = _estado;
    }

    vector<Producto> getProductos() const { return productos; }
    vector<int> getCantidades() const { return cantidades; }
    string getEstado() const { return estado; }

    void mostrar() const {
        for (size_t i = 0; i < productos.size(); i++) {
            double precioFinal = productos[i].aplicarDescuento(cantidades[i]);
            cout << productos[i].getNombre() << " | Cantidad: " << cantidades[i] << " | Precio Final: $" << precioFinal << endl;
        }
    }
};

#endif
