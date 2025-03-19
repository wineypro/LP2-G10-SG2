#include "Tienda.h"
#include <iostream>
using namespace std;
//Constructortienda
Tienda::Tienda() {
    totalProd = 0;
    totalVent = 0;
    totalPed = 0;
}
// Agregarprodinventario 
void Tienda::agregarProd(const char* nom, int id, int cant, float p) {
    if (totalProd < MAX_PROD) {
        Prod prod;
        for (int i = 0; i < 30; i++) prod.nom[i] = nom[i];
        prod.id = id;
        prod.cant = cant;
        prod.p = p;
        inv[totalProd++] = prod;
        cout << "Producto agregado.\n";
    } else {
        cout << "Inventario lleno.\n";
    }
}
// Registraventa
void Tienda::vender(int id, int cant) {
    for (int i = 0; i < totalProd; i++) {
        if (inv[i].id == id && inv[i].cant >= cant) {
            inv[i].cant -= cant;

            Vent v;
            v.idProd = id;
            v.cantVend = cant;
            v.total = cant * inv[i].p;
            ventas[totalVent++] = v;

            cout << "Venta registrada.\n";
            return;
        }
    }
    cout << "Producto insuficiente o no encontrado.\n";
}
// Registrapedido
void Tienda::nuevoPed(int id, int cant, const char* cli) {
    if (totalPed < MAX_PED) {
        Ped p;
        p.idProd = id;
        p.cant = cant;
        p.listo = false;
        for (int i = 0; i < 30; i++) p.cli[i] = cli[i];

        pedidos[totalPed++] = p;
        cout << "Pedido registrado para " << cli << ".\n";
    } else {
        cout << "Limite de pedidos alcanzado.\n";
    }
}
// pedidolisto
void Tienda::pedListo(int id) {
    for (int i = 0; i < totalPed; i++) {
        if (pedidos[i].idProd == id) {
            pedidos[i].listo = true;
            cout << "Pedido listo para " << pedidos[i].cli << ".\n";
            enviarNotif(pedidos[i].cli);
            return;
        }
    }
    cout << "Pedido no encontrado.\n";
}
// Greporte
void Tienda::reporte() {
    cout << "\n=== Inventario ===\n";
    for (int i = 0; i < totalProd; i++) {
        cout << "ID: " << inv[i].id << " | " << inv[i].nom 
             << " | Cantidad: " << inv[i].cant << " | Precio: " 
             << inv[i].p << "\n";
    }

    cout << "\n=== Ventas ===\n";
    for (int i = 0; i < totalVent; i++) {
        cout << "Producto ID: " << ventas[i].idProd 
             << " | Cantidad: " << ventas[i].cantVend 
             << " | Total: " << ventas[i].total << "\n";
    }
}

