#ifndef PEDIDO_H
#define PEDIDO_H

#include <vector>
#include <string>
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

    vector<Producto> getListaDeProductos() const { return productos; }
    vector<int> getCantidadPorProducto() const { return cantidades; }
    string getEstado() const { return estado; }

    void mostrar() const {
        cout << "Pedido (" << estado << "):" << endl;
        for (size_t i = 0; i < productos.size(); i++) {
            productos[i].mostrarInformacion();
            cout << "Cantidad: " << cantidades[i] << endl;
        }
    }
};

#endif
