#ifndef GESTORINVENTARIO_H
#define GESTORINVENTARIO_H

#include <vector>
#include "Producto.h"
#include "Pedido.h"

class GestorInventario {
private:
    vector<Producto> inventario;

public:
    // Agregar un producto al inventario
    void agregarProducto(Producto p) {
        inventario.push_back(p);
    }

    // Actualizar inventario tras un pedido
    void actualizarInventario(const Pedido& pedido) {
        for (size_t i = 0; i < pedido.getProductos().size(); i++) {
            for (auto& p : inventario) {
                if (p.getNombre() == pedido.getProductos()[i].getNombre()) {
                    int nuevaCantidad = p.getStock() - pedido.getCantidades()[i];
                    if (nuevaCantidad < 0) nuevaCantidad = 0; // Evitar valores negativos
                    p.setStock(nuevaCantidad);
                }
            }
        }
    }

    // Mostrar el inventario actual
    void mostrarInventario() const {
        for (const auto& p : inventario) p.mostrar();
    }

    // Obtener el inventario (para reportes)
    vector<Producto> getInventario() const { return inventario; }
};

#endif
