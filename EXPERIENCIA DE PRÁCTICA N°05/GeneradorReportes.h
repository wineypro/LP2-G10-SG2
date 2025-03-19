#ifndef GENERADORREPORTES_H
#define GENERADORREPORTES_H

#include <vector>
#include <iostream>
#include "GestorInventario.h"

class GeneradorReportes {
private:
    GestorInventario* inventario;
    vector<Pedido> historial;

public:
    GeneradorReportes(GestorInventario* _inventario) : inventario(_inventario) {}

    void registrarPedido(Pedido pedido) {
        historial.push_back(pedido);
    }

    void reporteVentas() const {
        double total = 0;
        for (const auto& p : historial) {
            for (size_t i = 0; i < p.getProductos().size(); i++) {
                total += p.getProductos()[i].getPrecio() * p.getCantidades()[i];
            }
        }
        cout << "Ventas totales: $" << total << endl;
    }

    void reporteInventarioBajo(int umbral) const {
        for (const auto& p : inventario->getInventario()) {
            if (p.getStock() < umbral) {
                cout << p.getNombre() << " | Stock: " << p.getStock() << endl;
            }
        }
    }

    void reporteGeneral() const {
        cout << "Pedidos completados: " << historial.size() << endl;
        reporteVentas();
    }
};

#endif
