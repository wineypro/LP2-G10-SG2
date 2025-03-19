#ifndef GESTORINVENTARIO_H
#define GESTORINVENTARIO_H

#include <vector>
#include "Producto.h"
#include "Pedido.h"

class GestorInventario {
private:
    vector<Producto> inventario;

public:
    void agregarProducto(Producto p) {
        inventario.push_back(p);
    }

    Producto buscarProducto(const string& nombre) const {
        for (const auto& p : inventario) {
            if (p.getNombre() == nombre) return p;
        }
        return Producto("", 0, 0); 
    }

    void actualizarInventario(const Pedido& pedido) {
        for (size_t i = 0; i < pedido.getProductos().size(); i++) {
            for (auto& p : inventario) {
                if (p.getNombre() == pedido.getProductos()[i].getNombre()) {
                    int nuevaCantidad = p.getStock() - pedido.getCantidades()[i];
                    p.setStock(nuevaCantidad > 0 ? nuevaCantidad : 0);
                }
            }
        }
    }

    vector<Producto> getInventario() const { return inventario; }
};

#endif
