#ifndef VENTA_H
#define VENTA_H

#include <string>
#include <vector>
#include "Cliente.h"
#include "Producto.h"
using namespace std;

class Venta {
public:
    string numeroFactura, fecha;
    Cliente* cliente;
    vector<Producto> productos;

    Venta(string _numeroFactura, string _fecha, Cliente* _cliente) {
        numeroFactura = _numeroFactura;
        fecha = _fecha;
        cliente = _cliente;
    }

    void agregarProducto(Producto producto) {
        productos.push_back(producto);
        cliente->agregarCompra(producto.descripcion);
    }
};

#endif
