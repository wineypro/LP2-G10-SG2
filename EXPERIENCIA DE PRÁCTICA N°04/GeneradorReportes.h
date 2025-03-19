#ifndef GENERADORREPORTES_H
#define GENERADORREPORTES_H

#include <vector>
#include "GestorInventario.h"

class GeneradorReportes {
private:
    GestorInventario* inventario;
    vector<Pedido> historial;

public:
    // Constructor con referencia al inventario
    GeneradorReportes(GestorInventario* _inventario) : inventario(_inventario) {}

    // Registrar un pedido completado
    void registrarPedido(Pedido pedido) {
        historial.push_back(pedido);
    }

    // Generar reporte de ventas totales
    void reporteVentas() const {
        double total = 0;
        for (const auto& p : historial) {
            for (size_t i = 0; i < p.getProductos().size(); i++) {
                total += p.getProductos()[i].getPrecio() * p.getCantidades()[i];
            }
        }
        cout << "Ventas totales: $" << total << endl;
    }

    // Reporte de productos con stock bajo
    void reporteInventarioBajo(int umbral) const {
        cout << "Stock bajo (<" << umbral << "):" << endl;
        for (const auto& p : inventario->getInventario()) {
            if (p.getStock() < umbral) cout << p.getNombre() << " | Stock: " << p.getStock() << endl;
        }
    }

    // Reporte general de ventas e inventario
    void reporteGeneral() const {
        cout << "Pedidos completados: " << historial.size() << endl;
        reporteVentas();
        inventario->mostrarInventario();
    }
};

#endif
