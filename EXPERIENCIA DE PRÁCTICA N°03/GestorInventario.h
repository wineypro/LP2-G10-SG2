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

    void actualizarInventario(const Pedido& pedido) {
        for (size_t i = 0; i < pedido.getListaDeProductos().size(); i++) {
            for (auto& p : inventario) {
                if (p.getNombre() == pedido.getListaDeProductos()[i].getNombre()) {
                    int nuevaCantidad = p.getCantidadEnInventario() - pedido.getCantidadPorProducto()[i];
                    if (nuevaCantidad < 0) nuevaCantidad = 0;
                    p.setCantidadEnInventario(nuevaCantidad);
                }
            }
        }
    }

    void mostrarInventario() const {
        for (const auto& p : inventario) p.mostrarInformacion();
    }
};

#endif
